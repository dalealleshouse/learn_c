#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  uid_t uid;
  gid_t gid;
  struct passwd *u;
  struct group *g;
  char *member;

  uid = getuid();
  printf("uid=%d", uid);

  u = getpwuid(uid);
  printf("(%s) ", u->pw_name);

  gid = getgid();
  printf("gid=%d", gid);

  g = getgrgid(gid);
  printf("(%s) ", g->gr_name);

  printf("groups=");

  while((g = getgrent()) != NULL) {
    while((member = *(g->gr_mem)++) != NULL)
      if (strcmp(member, u->pw_name) == 0)
        printf("%d(%s),", g->gr_gid, g->gr_name);
  }
  printf("\n");
}
