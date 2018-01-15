#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

void myhandler(int sigtype) {
  printf("got signal %d\n", sigtype);
}

int main(int argc, char *argv[]) {
  struct sigaction action;
  int n, p[2];
  char buf[1000];

  pipe(p);

  action.sa_handler = myhandler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = SA_RESTART;

  sigaction(SIGINT, &action, NULL);

  while(1) {
    n = read(p[0], buf, 1000);
    printf("read returned %d, errno = %d\n", n, errno);
  }
}
