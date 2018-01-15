#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int count = 20;
char c = 'b';

void read_config_file(int signumber) {
  char *line;
  size_t len = 0;
  FILE *fd;

  fd = fopen("reconfigure.conf", "r");
  getline(&line, &len, fd);
  c = line[0];

  getline(&line, &len, fd);
  count = atoi(line);
  printf("read char = %c and count %d\n", c, count);
}

int main(int argc, char *argv[]) {
  int i;

  signal(SIGHUP, read_config_file);
  raise(SIGHUP);

  while (1)
  {
    for (i = 0; i < count; i++)
      putchar(c);
    putchar('\n');
    sleep(3);
  }
}
