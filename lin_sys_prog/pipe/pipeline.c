#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int prompt_and_parse(char **u, char **d) {
  static char line[100];

  d[0] = NULL;
  printf("> ");

  if (gets(line) == NULL)
    return -1;

  *u++ = strtok(line, " \t");
  while ((*u = strtok(NULL, " \t"))) {
    if (strcmp(*u, "|") == 0) {
      *u = NULL;
      while ((*d++ = strtok(NULL, " \t")))
        /* NOTHING */

        return 1;
    }
    u++;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int p[2];
  char *upstream[20], *downstream[20];

  while (prompt_and_parse(upstream, downstream) > 0) {
    if (downstream[0] == NULL) {
      if (fork() == 0) {
        execvp(upstream[0], upstream);
        printf("%s: not found\n", upstream[0]);
        exit(1);
      } else {
        wait(0);
      }
    } else {
      pipe(p);
      if (fork() == 0) {
        dup2(p[1], 1);
        close(p[0]);
        execvp(upstream[0], upstream);
        printf("%s: not found\n", upstream[0]);
        exit(1);
      }

      if (fork() == 0) {
        dup2(p[0], 0);
        close(p[1]);
        execvp(downstream[0], downstream);
        printf("%s: not found\n", downstream[0]);
        exit(1);
      } else {
        close(p[0]);
        close(p[1]);
        wait(0);
        wait(0);
      }
    }
  }
}
