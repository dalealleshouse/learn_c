/* Monitor specified files for change, using inotify */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/inotify.h>
#include <limits.h>
#include <unistd.h>

#define BUFSIZE (100 * (sizeof(struct inotify_event) + NAME_MAX + 1))

int main() {
  FILE *fconfig;
  FILE *fout;
  char watchname[PATH_MAX];
  struct stat sb;
  int notifyfd, watchfd;
  char eventbuf[BUFSIZE];
  char *p;
  struct inotify_event *event;

  char watchednames[100][NAME_MAX+1];

  notifyfd = inotify_init();

  if ((fconfig = fopen("monitor.conf", "r")) == NULL) {
    printf("unable to open the config file; giving up!\n");
    exit(1);
  }

  while (fgets(watchname, PATH_MAX, fconfig) != NULL) {
    watchname[strlen(watchname)-1] = '\0';

    if (stat(watchname, &sb) < 0) {
      printf("Cannot stat %s, ignorned\n", watchname);
      continue;
    }

    if (S_ISREG(sb.st_mode)) {
      if ((watchfd = inotify_add_watch(notifyfd, watchname, IN_MODIFY | IN_DELETE_SELF)) < 0) {
        printf("error adding watch for %s\n", watchname);
      } else {
        printf("added %s to watch list on descriptor %d\n", watchname, watchfd);
        strcpy(watchednames[watchfd], watchname);
      }
    } else {
      printf("%s is not a regular file, ignorned\n", watchname);
    }
  }

  fout = fopen("monitor.out", "a");

  while (1) {
    int n = read(notifyfd, eventbuf, BUFSIZE);

    for (p = eventbuf; p < eventbuf + n;) {
      event = (struct inotify_event *)p;
      p += sizeof(struct inotify_event) + event->len;

      if (event->mask & IN_MODIFY)
        fprintf(fout, "%s was modified\n", watchednames[event->wd]);
      if (event->mask & IN_DELETE_SELF)
        fprintf(fout, "%s was deleted\n", watchednames[event->wd]);

    }

    fflush(fout);
  }
}
