/* http://man7.org/linux/man-pages/man2/lseek.2.html */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  /* System call header file */
#include <fcntl.h>   /* Option for file open */
#include <sys/types.h> /* For lseek function */

int main(int argc, char const *argv[])
{
	/* Check program parameter */
	if(argc < 4)
	{
		/* Usage to read content from offset based on the SEEK option */
		printf("Usage: %s <read_file_name> <offset> <SEEK_SET | SEEK_CUR | SEEK_END>\n", argv[0]);
	}
	else
	{
		/* File descriptor */
		int fd = 0;
		/* Position to read data */
		int pos = -1;
		/* Buffer to save read data */
		char buff[50] = {0};
		int readLen = 0;

		/* Open file and save the file descriptor value */
		fd = open(argv[1], O_RDONLY);
		if(fd < 0)
		{
			printf("File cannot open\n");
			return -1;
		}
		/* Set the start position to read by using lseek */
		pos = lseek(fd, atoi(argv[2]), atoi(argv[3]));
		if(pos < 0)
		{
			printf("Wrong position\n");
			return -1;
		}
		
		/* Read data from lseek */
		printf("Read buffer from pos %d len %ld\n", pos, sizeof(buff));
		readLen = read(fd, buff, 50);
		if(readLen > 0)
		{
			printf("Data content: %s\n", buff);
		}
	}

	return 0;
}