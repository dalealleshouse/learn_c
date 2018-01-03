#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

int main() {
  struct stat sb;

  if((stat("foo", &sb)) < 0) {
    perror("stat");
    exit(1);
  }

  printf("last accessed: %s", ctime((const time_t*)&sb.st_atim));
  printf("last modified: %s", ctime((const time_t*)&sb.st_mtim));
  printf("last change: %s", ctime((const time_t*)&sb.st_ctim));

  exit(0);
}
