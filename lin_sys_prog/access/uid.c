#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void print_access() {
  printf("Real      UID = %d\n", getuid());
  printf("Effective UID = %d\n", geteuid());

  printf("open: %d\n", open("/etc/hosts", O_RDWR));

  printf("access: %d\n", access("/etc/hosts", W_OK));
}

int main(int argc, char *argv[]) {
  print_access();

  seteuid(getuid());

  print_access();
}
