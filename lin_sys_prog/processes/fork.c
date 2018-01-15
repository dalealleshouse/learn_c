#include <stdio.h>
#include <unistd.h>

int main() {
  if (fork())
    printf("I am the parent\n");
  else
    printf("I am the child\n");
}
