#include <stdio.h>
#include <unistd.h> /* For execl function */
#include <fcntl.h>  /* Header file for open option */
#include <string.h>

int main(int argc, char const *argv[])
{
	int result 	= 0;
	int fd 		= 0;
	pid_t pid 	= 0, cpid = 0;
	char c 		= 0;

	if(argc)
	{
		/* Fork a children PID to run other program */
		pid = fork();
		/* Check if children pid */
		if(pid == 0)
		{
			/* Run system command in children to get list of file and save into 06.result file */
			system("ls -al > 06.result");
		}
		else
		{
			/* Wait until children process is finish */
			cpid = wait(NULL);

			/* Open file to check content value */
			fd = open("06.result", O_RDONLY);
			if(fd)
			{
				/* Loop to read all file data, EOF will return value != 1 for read function */
				while(read(fd, &c, 1))
				{
					printf("%c", c);
				}
			}
			else
			{
				return -1;
			}
		}
	}
	return 0;
}
