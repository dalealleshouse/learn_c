#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  char line[100];

  while (printf("> "), gets(line) != NULL) {
    if (fork() ==0) {
      execlp(line, line, (char *)0);

      printf("%s: not found\n", line);
      exit(1);
    } else {
      wait(0);
    }
  }
}
