#include <stdio.h>
#include <signal.h>

/* Signal handler for SIGINT */
void sigintHandler(int sig_num)
{
	/* Reset handler to catch SIGINT next time */
	signal(SIGINT, sigintHandler);
	printf("\n Catching terminated using Ctrl+C \n");
	fflush(stdout);
}

int main(int argc, char const *argv[])
{
	/* Set the SIGINT (Ctrl-C) signal handler to sigintHandler */
	signal(SIGINT, sigintHandler);

	while(1)
	{
		printf("Looping infinite\n");
		sleep(5);
	}
	return 0;
}