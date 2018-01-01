#include <stdio.h>
#define BUFSIZE 16384

int main() {
  FILE *fin, *fout;
  char buf[BUFSIZE];
  int count;

  fin = fopen("foo", "r");
  fout = fopen("bar", "w");

  while((count = fread(buf, 1, BUFSIZE, fin)) > 0)
    fwrite(buf, 1, count, fout);

  fclose(fin);
  fclose(fout);
}
