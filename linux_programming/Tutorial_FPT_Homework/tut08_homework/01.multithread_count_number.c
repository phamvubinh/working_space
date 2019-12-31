#include <stdio.h>
#include <time.h>		/* For time checking function */
#include <pthread.h>	/* For thread function creation */

#define COUNT_NUM 4000000000

/* Task to count odd number */
void *count_task(void *param)
{
	unsigned long i 		= 0;
	unsigned long limitNum 	= * (unsigned long *)param;
	unsigned long oddNum 	= 0;

	/* Loop to count  */
	for (i = 0; i < limitNum; ++i)
	{
		/* Check the number is odd */
		if(i%2)
		{
			oddNum++;
		}
	}

	printf("Number of odd is: %ld\n", oddNum);

	return NULL;
}

/*int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void *), void *restrict arg);*/
int main(int argc, char const *argv[])
{
	/* Define variable to mesure counting time */
	time_t startTime  = {0};
	time_t finishTime = {0};
	/* Variable to define the count number */
	unsigned long countNum 			= COUNT_NUM;
	unsigned long multiTaskCountNum = COUNT_NUM/4;

	/* Variable to manage thread */
	pthread_t singleCountThread    = 0;
	pthread_t multipleCountThread0 = 0;
	pthread_t multipleCountThread1 = 0;
	pthread_t multipleCountThread2 = 0;
	pthread_t multipleCountThread3 = 0;

	/* Start counting the time */
	startTime = time(NULL);
	/* Create a thread to count the odd number */
	pthread_create(&singleCountThread, NULL, count_task, (void *) &countNum);
	/* Waits for the thread specified to terminate */
	pthread_join(singleCountThread, NULL);
	/* End of counting time */
	finishTime = time(NULL);
	printf("The time taken to count by single task: %ld second\n", finishTime - startTime);

	/* Now we devide the count to 4 and count it in multiple task */
	startTime = time(NULL);
	/* Create multiple task to count odd number, can upgrade this point using struct for range number */
	pthread_create(&multipleCountThread0, NULL, count_task, (void *) &multiTaskCountNum);
	pthread_create(&multipleCountThread1, NULL, count_task, (void *) &multiTaskCountNum);
	pthread_create(&multipleCountThread2, NULL, count_task, (void *) &multiTaskCountNum);
	pthread_create(&multipleCountThread3, NULL, count_task, (void *) &multiTaskCountNum);
	/* Waits for the thread specified to terminate */
	pthread_join(multipleCountThread0, NULL);
	pthread_join(multipleCountThread1, NULL);
	pthread_join(multipleCountThread2, NULL);
	pthread_join(multipleCountThread3, NULL);
	/* End of counting time */
	finishTime = time(NULL);
	printf("The time taken to count by multiple task: %ld second\n", finishTime - startTime);

	return 0;
}
