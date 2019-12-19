#include <stdio.h>
#include <unistd.h> /* For execl function */
#include <fcntl.h>  /* Header file for open option */
#include <string.h>

int main(int argc, char const *argv[])
{
	int result = 0;
	int fd = 0;
	int readNum = 0;
	char readBuff[40] = {0};
	pid_t pid = 0, cpid = 0;

	if(argc == 3)
	{
		/* Fork a children PID to run other program */
		pid = fork();

		/* Check if children pid */
		if(pid == 0)
		{
			/* Execute program with parameter, need NULL to terminate function list */
			printf("%s-%s\n", argv[1], argv[2]);
			/* int execl(const char *pathname, const char *arg0, ... NULL ) */
			/* Result = execl(pathname, program name, first parameter, NULL); */
			execl(argv[1], argv[1], argv[2], NULL);
			/* If this line of code is run that mean execl function doesn't work */
			printf("Too bad errr on execl\n");
		}
		else
		{
			/* Wait until children process is finish */
			cpid = wait(NULL);
			printf("Children PID finish: %d\n", cpid);
			/* Open file to check content value */
			fd = open(argv[2], O_RDONLY);
			if(fd)
			{
				readNum = read(fd, readBuff, sizeof(readBuff));
				if(readNum)
				{
					/* Check content inside result file */
					if(strcmp(readBuff, "hello world") == 0)
					{
						printf("Execl function run correctly\n");
					}
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
