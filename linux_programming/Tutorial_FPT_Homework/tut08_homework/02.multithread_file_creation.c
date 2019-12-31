#include <stdio.h>
#include <time.h>		/* For time checking function */

#include <pthread.h>	/* For thread function creation */

#include <fcntl.h>  	/* Header file for open option */
#include <string.h> 	/* Header file for strlen function */
#include <unistd.h> 	/* Header file for system call open read write */
#include <stdlib.h>     /* For random function */

#include <string.h>		/* For itoa function */

#define RANDOM_NUM  1000000
#define SINGLE 		1
#define MULTIPLE 	1
/* Function to generate random number between range */
int generate_random_number(int low, int high)
{
	int result = 0;
	if(low <= high)
	{
		result = (rand() % (high - low)) + low;
		return result;
	}
	return -1;
}

/* Define function to write data into file */
int write_file_data(char *fileName)
{
	int fd = 0;
	// int result = 0;
	int i = 0;

	int randomNum = 0;
	char randomStr[2] = {0};

	if(!fileName)
	{
		return -1;
	}

	fd = open(fileName, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd)
	{
		/* Use current time as a seed for random number */
		srand(time(NULL));
		for (i = 0; i < RANDOM_NUM; ++i)
		{
			randomNum = generate_random_number(0, 10);
			if(randomNum >= 0)
			{
				/* Convert number to string */
				snprintf(randomStr, 2, "%d", randomNum);
				/* Write data to file */
				write(fd, randomStr, 1);
			}
		}
		close(fd);
		return 0;
	}
	else
	{
		return -1;
	}
}
/* Task to count odd number */
void *specified_task(void *param)
{
	unsigned long i = 0;
	unsigned long *range = (unsigned long *)param;
	char fileName[50] = {0};

	if(range)
	{
		for(i = range[0]; i < range[1]; ++i)
		{
			/* Create file and write radom number into file */
			snprintf(fileName, 50, "02_radom_num_%ld.txt", i);
			write_file_data(fileName);
		}
	}
	return NULL;
}

/*int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void *), void *restrict arg);*/
int main(int argc, char const *argv[])
{
	/* Define variable to mesure counting time */
	time_t startTime  = {0};
	time_t finishTime = {0};

#if SINGLE
	/* Variable to define the count number */
	unsigned long singleRunningTime[] = {0, 10};
#endif

#if MULTIPLE
	unsigned long multiRunningTime0[] = {0, 2};
	unsigned long multiRunningTime1[] = {2, 4};
	unsigned long multiRunningTime2[] = {4, 6};
	unsigned long multiRunningTime3[] = {6, 8};
	unsigned long multiRunningTime4[] = {8, 10};
#endif

#if SINGLE
	/* Variable to manage thread */
	pthread_t singleThread    = 0;
#endif

#if MULTIPLE
	pthread_t multipleThread0 = 0;
	pthread_t multipleThread1 = 0;
	pthread_t multipleThread2 = 0;
	pthread_t multipleThread3 = 0;
	pthread_t multipleThread4 = 0;
#endif

#if SINGLE
	/* Start counting the time */
	startTime = time(NULL);
	/* Create a thread to  */
	pthread_create(&singleThread, NULL, specified_task, (void *) singleRunningTime);
	/* Waits for the thread specified to terminate */
	pthread_join(singleThread, NULL);
	/* End of counting time */
	finishTime = time(NULL);
	printf("The time taken to count by single task: %ld second\n", finishTime - startTime);
#endif

#if MULTIPLE
	/* Now we devide the count to 4 and count it in multiple task */
	startTime = time(NULL);
	/* Create multiple task to count odd number, can upgrade this point using struct for range number */
	pthread_create(&multipleThread0, NULL, specified_task, (void *) &multiRunningTime0);
	pthread_create(&multipleThread1, NULL, specified_task, (void *) &multiRunningTime1);
	pthread_create(&multipleThread2, NULL, specified_task, (void *) &multiRunningTime2);
	pthread_create(&multipleThread3, NULL, specified_task, (void *) &multiRunningTime3);
	pthread_create(&multipleThread4, NULL, specified_task, (void *) &multiRunningTime4);
	/* Waits for the thread specified to terminate */
	pthread_join(multipleThread0, NULL);
	pthread_join(multipleThread1, NULL);
	pthread_join(multipleThread2, NULL);
	pthread_join(multipleThread3, NULL);
	pthread_join(multipleThread4, NULL);
	/* End of counting time */
	finishTime = time(NULL);
	printf("The time taken to count by multiple task: %ld second\n", finishTime - startTime);
#endif
	return 0;
}
