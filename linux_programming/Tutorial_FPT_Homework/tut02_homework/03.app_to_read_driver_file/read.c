#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/* File path to device filethat created from misc-module */
#define FILE "/dev/my_misc_device"

int main(void)
{
	/* Buffer to read data */
	char buff[20] = {0};

	/* Open file with read only option */
	int fd = open(FILE, O_RDONLY);
	if (fd < 0) 
	{
		perror("Cannot open file\n");
		exit(1);
	}

	/* Read data from device file */
	read(fd, buff, 20);
	printf("Read data from device file: %s\n", buff);

	close(fd);
	return 0;
}
