#include <stdio.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[])
{
  struct passwd *u;
  struct group *g;

  while((u = getpwent()) != NULL) {
    if (u->pw_uid >= 1000)
      printf("user: %s\n", u->pw_name);
  }

  while((g = getgrent()) != NULL) {
    printf("group: %s\n", g->gr_name);
  }
}
