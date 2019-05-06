#include <signal.h> /* declare a data structure of type sigaction */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigusr1_count = 0;

void handler (int signal_number)
{
	printf("signal_number is: %d\n", signal_number);
	++sigusr1_count;
}

int main()
{
	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &handler;

	/* Register the signal handler for signal SIGUSR1 by calling the sigaction */
	sigaction (SIGUSR1, &sa, NULL);
	fprintf(stderr, "Running process... (PID=%d)\n", (int) getpid());

	sleep(5);

	printf("SIGUSR1 was raised %d times\n", sigusr1_count);
	return 0;
}