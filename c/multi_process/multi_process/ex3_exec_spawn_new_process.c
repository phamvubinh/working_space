#include <stdio.h>
#include <stdlib.h>
// #include <sys/types.h>
#include <unistd.h>

int spawn(const char * program, char ** arg_list)
{
	pid_t child_pid = fork();
	if(child_pid != 0)
	{
		printf("Main program existing in spawn ...\n");
		return child_pid;		/* This is the parent process */
	}
	else
	{
		execvp(program, arg_list);
		fprintf(stderr, "%s\n", "An error occoured in execvp\n");
		abort();
	}
}

int main()
{
	char * arg_list[] = {"ls", "-z", "./", NULL};
	spawn("ls", arg_list);
	printf("Main program existing in main ...\n");
	return 0;
}