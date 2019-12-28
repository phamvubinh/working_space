#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>   /* fork header */
#include <signal.h>   /* signal function */
#include <stdbool.h>   /* boolen type */
#include <string.h>

/* Global variable */
int   fd  	= 0;
pid_t pid 	= 0;
int   count = 0;

/* Function for signal action */
void sig_handler_parent(int sig)
{
	count++;
	printf("This is parent: %d\n", count);
	write(fd, "This is parent1\n", strlen("This is parent1\n"));
	/* Send signal back to childern to write */
	kill(pid, SIGUSR2);
}

/* Function for signal action */
void sig_handler_children(int sig)
{
	count++;
	printf("This is children: %d\n", count);
	write(fd, "This is children1\n", strlen("This is children1\n"));
	/* Send signal back to parent to write */
	kill(getppid(), SIGUSR1);
}


int	main(int argc, char const *argv[])
{
	int i = 0;

	/* Create a counter result file to save data from parent and children */
	fd = open("03.counter_result.txt", O_RDWR | O_CREAT, 0777);
	if(fd < 0)
	{
		printf("Failed to open file\n");
		return -1;
	}

	pid = fork();
	/* Loop to write data into file */
	if(pid != 0)
	{
		signal(SIGUSR1, sig_handler_parent);
		while(1)
		{
			if(count >= 10)
			{
				break;
			}
		}
	}
	else
	{
		signal(SIGUSR2, sig_handler_children);
		/* Send signal to parent to start the writting process sig_handler_parent */
		kill(getppid(), SIGUSR1);
		while(1)
		{
			if(count >= 10)
			{
				break;
			}
		}
	}
	close(fd);
	return 0;
}
