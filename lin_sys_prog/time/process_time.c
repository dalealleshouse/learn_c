#include <stdio.h>
#include <sys/times.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[])
{
  struct tms tmsbuf;
  long i;
  double x;
  int fd;

  printf("clock ticks %ld\n", sysconf(_SC_CLK_TCK));
  printf("CLOCKS_PER_SEC %ld\n", CLOCKS_PER_SEC);

  fd = open("/dev/null", O_RDWR);
  for (i=0; i < 10000000; i++) {
    write(fd, &i, sizeof(i));
  }
  close(fd);

  /* for (i=0; i < 100000000; i++) { */
  /*   x = sqrt((double)i); */
  /* } */

  times(&tmsbuf);
  printf("utime = %ld\n", tmsbuf.tms_utime);
  printf("stime = %ld\n", tmsbuf.tms_stime);
  printf("cutime = %ld\n", tmsbuf.tms_cutime);
  printf("cstime = %ld\n", tmsbuf.tms_cstime);

  printf("clock = %ld\n", clock());
}
