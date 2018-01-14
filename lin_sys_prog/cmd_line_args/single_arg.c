#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s file\n", argv[0]);
    exit(1);
  }

  printf("processing %s\n", argv[1]);
}
