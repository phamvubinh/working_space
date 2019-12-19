#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>   /* fork header */

int	main(int argc, char const *argv[])
{
	pid_t pid = 0;
	int fd = 0;
	int i = 0;

	fd = open("03.fork_test.txt", O_RDWR | O_CREAT, 0777);
	if(fd < 0)
	{
		printf("Failed to open file\n");
		return -1;
	}

	pid = fork();
	/* Loop to write data into file */
	for (i = 0; i < 10; ++i)
	{
		if(pid != 0)
		{
			printf("This is parent\n");
			write(fd, "This is parent\n", strlen("This is parent\n"));
		}
		else
		{
			printf("This is children\n");
			write(fd, "This is children\n", strlen("This is children\n"));
		}
	}
	close(fd);
	return 0;
}
