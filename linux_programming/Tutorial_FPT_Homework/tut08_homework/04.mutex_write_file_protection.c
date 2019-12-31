/* Header for file writting */
#include <unistd.h>
#include <fcntl.h>

/* Basic header */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Thread header */
#include <pthread.h>

/* Define a mutex lock */
pthread_mutex_t lock;

/* Global file descriptpr */
int fd = 0;

/* With a long buffer, writting process will be conflict between task */
/* So we need to use protect method here */
int mutex_write(char *buff)
{
	int result = 0;

	/* Use mutex to protect file writting */
	pthread_mutex_lock(&lock);
	if(buff)
	{
		result = write(fd, buff, strlen(buff));
		printf("%s\n", buff);
	}
	pthread_mutex_unlock(&lock);

	return result;
}

void *write_task(void *param)
{
	char *buff = (char*)param;
	while(1)
	{
		/* Call writting function to write into file */
		mutex_write(buff);
		usleep(10);
	}
	return NULL;
}

#define THREAD_NUM 5

int main(int argc, char const *argv[])
{
	int i = 0;
	char buff[THREAD_NUM][10000] = {{0}};
	/* Init a mutex lock */
	pthread_mutex_init(&lock, NULL );

	pthread_t thread[THREAD_NUM];

	fd = open("04_mutex_file_write.txt", O_RDWR | O_CREAT, 0664);
	if(fd < 0)
	{
		return -1;
	}

	/* Testing buffer */
	for (i = 0; i < THREAD_NUM; ++i)
	{
		// printf("sizeof buff[i]: %d\n", sizeof(buff[i]));
		memset(buff[i], 'a' + i, sizeof(buff[i]));
		buff[i][sizeof(buff[i])-1] = '\0';
	}

	/* Create THREAD_NUM thread to write data into file */
	for (i = 0; i < THREAD_NUM; ++i)
	{
		pthread_create(&thread[i], NULL, write_task, (void *)buff[i]);
	}
	for (i = 0; i < THREAD_NUM; ++i)
	{
		pthread_join(thread[i], NULL);
	}
	close(fd);
	return 0;
}
