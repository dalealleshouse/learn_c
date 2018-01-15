#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int i;

  if (fork()) {
    for (i=0; i<10000; i++)
      printf("**    PARENT %d\n", i);
  } else {
    for (i=0; i<10000; i++)
      printf("  **  CHILD %d\n", i);
  }
}
