#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
  time_t seconds = time(NULL);

  printf("Seconds since EPOCH - time(): %ld\n", seconds);


  printf("gettimeofday(): ");
}
