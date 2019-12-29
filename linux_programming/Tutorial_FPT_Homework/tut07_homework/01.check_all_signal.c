#include <stdio.h>   /* print and put function */
#include <signal.h>  /* signal function */
/* Function for signal action */
void sig_handler(int sig)
{
	/* Print signal number */
	printf("sig_handler: %d\n", sig);
}

typedef struct
{
	int signum;
	char *signame;
}SIGNAL_NAME_ST;

SIGNAL_NAME_ST sigTable[] = {
	{SIGABRT, 	"SIGABRT"},
	{SIGALRM, 	"SIGALRM"},
	{SIGBUS, 	"SIGBUS"},
	{SIGCHLD, 	"SIGCHLD"},
	{SIGCLD, 	"SIGCLD"},
	{SIGCONT, 	"SIGCONT"},
	{SIGFPE, 	"SIGFPE"},
	{SIGHUP, 	"SIGHUP"},
	{SIGILL, 	"SIGILL"},
	{SIGINT, 	"SIGINT"},
	{SIGIO, 	"SIGIO"},
	{SIGIOT, 	"SIGIOT"},
	{SIGKILL, 	"SIGKILL"},
	{SIGPIPE, 	"SIGPIPE"},
	{SIGPOLL, 	"SIGPOLL"},
	{SIGPROF, 	"SIGPROF"},
	{SIGPWR, 	"SIGPWR"},
	{SIGQUIT, 	"SIGQUIT"},
	{SIGSEGV, 	"SIGSEGV"},
	{SIGSTKFLT, "SIGSTKFLT"},
	{SIGSTOP, 	"SIGSTOP"},
	{SIGTSTP, 	"SIGTSTP"},
	{SIGSYS, 	"SIGSYS"},
	{SIGTERM, 	"SIGTERM"},
	{SIGTRAP, 	"SIGTRAP"},
	{SIGTTIN, 	"SIGTTIN"},
	{SIGTTOU, 	"SIGTTOU"},
	{SIGUNUSED, "SIGUNUSED"},
	{SIGURG, 	"SIGURG"},
	{SIGUSR1, 	"SIGUSR1"},
	{SIGUSR2, 	"SIGUSR2"},
	{SIGVTALRM, "SIGVTALRM"},
	{SIGXCPU, 	"SIGXCPU"},
	{SIGXFSZ, 	"SIGXFSZ"},
	{SIGWINCH, 	"SIGWINCH"},
};

int main(int argc, char const *argv[])
{
	int i = 0;

	int tableSize = sizeof(sigTable)/sizeof(sigTable[0]);

	for (i = 0; i < tableSize; ++i)
	{
		printf("%-10s: %-3d\n", sigTable[i].signame, sigTable[i].signum);

		/* Register signal handler for all signum */
		signal(sigTable[i].signum, sig_handler);
	}

	printf("Checking all signal");
	/* Infinite loop to wait for kill signal */
	while(1);

	return 0;
}
