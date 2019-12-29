#include <stdio.h>   /* print and put function */
#include <signal.h>  /* signal function */
#include <unistd.h>  /* sleep function */
#include <string.h>


int main(int argc, char const *argv[])
{
	/* Send the signal to other process by using agrument */
	kill(atoi(argv[1]), SIGUSR1);
	sleep(1);
	return 0;
}
