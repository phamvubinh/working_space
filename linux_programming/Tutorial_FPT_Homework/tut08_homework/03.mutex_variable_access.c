#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

pthread_mutex_t lock;

/* Global variable to increased by 2 task */
static unsigned long s_ulVariable;

void *increase_task(void *param)
{
	while(1)
	{
		/* Two thread access to the variable at the same time */
		/* Mutex lock is used to protect variable accessing */
		pthread_mutex_lock(&lock);

		s_ulVariable = s_ulVariable + 1;

		printf("Increase %ld start\n", s_ulVariable);
		usleep(1);
		printf("Increase %ld finish\n", s_ulVariable);

		pthread_mutex_unlock(&lock);

		/* Sleep function to switch task */
		if(s_ulVariable > 100)
		{
			break;
		}
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	/* Create 2 threads to increase variable */
	pthread_t thread0;
	pthread_t thread1;

	/* Init a mutex lock */
	pthread_mutex_init(&lock, NULL );

	/* Create 2 thread to test increase variable */
	pthread_create(&thread0, NULL, increase_task, (void *)(NULL));
	pthread_create(&thread1, NULL, increase_task, (void *)(NULL));
	pthread_join(thread0, NULL);
	pthread_join(thread1, NULL);
	return 0;
}
