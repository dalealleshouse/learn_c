#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int status;
  int a, b, c;

  if (fork()) {
    wait (&status);
    if (WIFEXITED(status))
      printf("Child exited normaly with exit status %d\n", WEXITSTATUS(status));
    if (WIFSIGNALED(status))
      printf("Child exited on signal %d: %s\n", WTERMSIG(status),
          strsignal(WTERMSIG(status)));
  } else {
    printf("Child PID = %d\n", getpid());
    pause();
    exit(5);
  }
}
