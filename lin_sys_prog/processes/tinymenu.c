#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  static const char *cmd[] = {"ps", "ls", "date", "good"};
  int i;

  printf("0=ps, 1=ls, 2=date, 3=goof : ");
  scanf("%d", &i);

  execlp(cmd[i], cmd[i], NULL);

  printf("command not found\n");
}
