#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;
  char *val;

  for (i=1; i < argc; i++) {
    if ((val = getenv(argv[i])) != NULL)
      printf("%s: %s\n", argv[i], val);
    else
      printf("%s: not in environment\n", argv[i]);
  }
}
