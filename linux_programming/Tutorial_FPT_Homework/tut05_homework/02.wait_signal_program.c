#include <stdio.h>   /* print and put function */
#include <signal.h>  /* signal function */
#include <unistd.h>  /* sleep function */
#include <stdbool.h> /* boolen type */

volatile bool b_sleepFlag = true;

void sig_wakeup_handler(int sig)
{
	/* Print signal number */
	printf("sig_wakeup_handler: %d\n", sig);
	/* Change sleep flag to wakeup */
	b_sleepFlag = false;
}

int main(int argc, char const *argv[])
{
	signal(SIGUSR1, sig_wakeup_handler);
	while(1)
	{
		if(b_sleepFlag)
		{
			sleep(1);
		}
		else
		{
			printf("Waked Up\n");
			break;
		}
	}
	return 0;
}
