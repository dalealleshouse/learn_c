#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

void timeout_handler(int signum) {
}

int t_getnum(int timeout) {
  int n;
  char line[100];
  struct sigaction action;

  action.sa_handler = timeout_handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  sigaction(SIGALRM, &action, NULL);

  alarm(timeout);
  n = read(0, line, 100);
  alarm(0);
  if (n == -1 && errno == EINTR) return -1;
  n = atoi(line);
  return n;
}

int main(int argc, char *argv[]) {
  int num;

  while(1) {
    printf("enter a number: ");
    fflush(stdout);

    if ((num = t_getnum(5)) == -1)
      printf("timed out!\n");
    else
      printf("You entered %d\n", num);
  }
}
