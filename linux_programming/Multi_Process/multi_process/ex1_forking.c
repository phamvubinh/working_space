#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t child_pid;
	printf("Main process is = %d (parent PID = %d) \n", (int) getpid(), (int) getppid());

	child_pid = fork();

	/* In parent process address space child_pid is set equal to children pid*/
	if(child_pid != 0)
	{
		printf("This is parent pid: %d\n", getpid());
		printf("Child_pid is: %d\n", child_pid);
	}
	else /* In children process address space child_pid variable is not set */
	{
		printf("This is child pid: %d\n", (int)getpid());
		printf("Child_pid is: %d\n", child_pid);
	}

	return 0;
}