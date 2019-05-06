#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void PIPE_Write(char * message, FILE * writePipe)
{
	fprintf(writePipe, "%s\n", message);
	fflush(writePipe);
	sleep(1);
}

void PIPE_Read(FILE * readPipe)
{
	char buffer[1024] = {0};
	feof(readPipe);
	ferror(readPipe);
	while(!feof(readPipe) && !ferror(readPipe) && fgets(buffer, sizeof(buffer), readPipe) != NULL)
	{
		fputs(buffer, stdout);
	}
}

int main(int argc, char const *argv[])
{
	int fds[2] = {0};
	FILE * stream;
	pipe(fds);

	pid_t child_pid;

	child_pid = fork();

	if(child_pid == (pid_t) 0)
	{
		printf("This is the child process\n");
		printf("Reading from pipe\n");
		close(fds[1]);
		/* Open the stream by using fd*/
		stream = fdopen(fds[0], "r");
		PIPE_Read(stream);
		close(fds[0]);
	}
	else
	{
		printf("This is the parent process\n");
		printf("Writing to pipe\n");
		close(fds[0]);
		stream = fdopen(fds[1], "w");
		PIPE_Write("Hello pipe, wrote into pipe\n", stream);
		close(fds[1]);
	}
	return 0;
}