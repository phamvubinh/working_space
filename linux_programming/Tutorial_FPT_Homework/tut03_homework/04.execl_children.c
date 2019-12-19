#include <stdio.h>
#include <unistd.h> /* For execl function */
#include <fcntl.h>  /* Header file for open option */

int main(int argc, char const *argv[])
{
	int fd = 0;
	int result = 0;

	if(argv[1])
	{
		fd = open(argv[1], O_CREAT | O_RDWR, 0777);
		if(fd)
		{
			result = write(fd, "hello world", strlen("hello world"));
			close(fd);
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}

	return 0;
}
