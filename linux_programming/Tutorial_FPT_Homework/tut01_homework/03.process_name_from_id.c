#include <stdio.h>
#include <fcntl.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	if(argc != 2)
	{
		printf("Not correct parameter nummber\n");
		printf("Usage: ./03.process_name_from_id <proccess id number>\n");
	}
	else
	{
		/* Buffer to save file name of proccess */
		char buff[30] = {0};
		/* Buffer to save proccess name */
		char buff2[30] = {0};
		/* File descriptor */
		int fd = 0;

		printf("Getting process name from id: %d\n", atoi(argv[1]));
		/* Create file name to open by using process id */
		snprintf(buff, 30, "/proc/%s/cmdline", argv[1]);
		/* Open file contain process name */
		fd = open(buff, O_RDONLY);
		/* Read content to buff */
		if(fd < 0)
		{
			printf("Cannot open the file: %s\n", buff);
		}
		else
		{
			/* Read file content from valid fd */
			read(fd, buff2, 50);
			printf("Proces name is: %s\n", buff2);
			close(fd);
		}

	}
	return 0;
}