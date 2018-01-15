/* File pipedemo.c */
/* Equivalent to "ls | sort -r" */

#include <unistd.h>

void main()
{
  int p[2];

  pipe(p);       /* Create the pipe */
  if (fork() == 0) {
    /* Child: connect stdout to pipe */
    dup2(p[1], 1);
    close(p[0]);
    execlp("ls", "ls", (char *)0);
  }
  /* Parent: connect stdin to pipe */
  dup2(p[0], 0);
  close(p[1]);
  execlp("sort", "sort", "-r", (char *)0);
}
