#include <stdio.h>
#include <unistd.h> /* Header file for system call open read write */
#include <fcntl.h>  /* Header file for open option */
#include <string.h> /* Header file for strlen function */
int main(int argc, char const *argv[])
{
	/* Define 2 file descriptors to check open times */
	int fd1 = 0;
	int fd2 = 0;
	int readNum;
	/* Define buffer content */
	char buff1[50] = "Hello world by fd1\n";
	char buff2[50] = {0};
	/* Creat a file with read, write permission */
	fd1 = open("02.file_content_open.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	/* We can open the file one more time */
	fd2 = open("02.file_content_open.txt", O_RDWR);
	/* Write data to a file by write system call */
	write(fd1, buff1, strlen(buff1));
	/* Read data from the file by using fd2 and save to buff2 
	   readNum is number of read character */
	readNum = read(fd2, buff2, 50);
	/* Now print data to console by writting data to stdout */
	write(1, buff2, readNum); /* 1 here is the file desctiptor of stdout */

	/* Close both fd descriptor */
	close(fd1);
	close(fd2);
}