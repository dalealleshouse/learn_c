#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

struct record {
	int id;
	char name[80];
};

int main() {
	int fd, size = sizeof(struct record);

	struct record info;

	if ((fd = open("datafile", O_RDWR)) < 0) {
		perror("datafile");
		exit(1);
	}

	lseek(fd, size, SEEK_SET);
	read(fd, &info, size);

	info.id = 99;
	lseek(fd, -size, SEEK_CUR);
	write(fd, &info, size);

	close(fd);
}
