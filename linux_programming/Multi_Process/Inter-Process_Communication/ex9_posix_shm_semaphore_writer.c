#include <stdio.h>			/* Standard buffered input/output */
#include <stdlib.h>		 	/* Four variable types, several macros, and various functions for performing general functions */
#include <string.h>
#include <fcntl.h>		 	/* File control options */
#include <sys/shm.h>     	/* Share memory facility */
#include <sys/stat.h>    	/* Data return by stat() function */
#include <sys/mman.h>    	/* Memory map function decleration */

#include <semaphore.h>

#define SIZE 		4096
#define SHM_NAME 	"/SHM_BEN"
#define SEMA_NAME	"/SEMA_BEN"


int main(int argc, char const *argv[])
{
	int i, shm_fd;

	const char *message = "This is about shared memory xxx\n";

	void * ptr;

	/* Create shared memory segment referred by name */
	shm_fd = shm_open(SHM_NAME, O_CREAT| O_RDWR, 0666);
	if (shm_fd == -1)
	{
		printf("Memory segment failed\n");
		exit(-1);
	}

	/* Resize memory region to correct size */
	ftruncate(shm_fd, sizeof(message));

	/* void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset); */
	/* create new mapping in the virtual address space of the calling process */
	/* addr: starting mount address on process */
	/* prot: argument describes the desired memory protection */
	/* flags: define whether updates to the mapping are visible to other process */
	ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if(ptr == MAP_FAILED)
	{
		printf("Map failed\n");
		return -1;
	}

	printf("Debugging line: %d\n", __LINE__);

	/* Open semaphore create, read, write option with 1 key */
	sem_t *sem_id = sem_open(SEMA_NAME, O_CREAT, S_IRUSR | S_IWUSR, 1);

	printf("Debugging line ***: %d\n", __LINE__);
	/* Accessing the shared map, so other process need to wait */
	sem_wait(sem_id);
	printf("Debugging line: %d\n", __LINE__);
	/* Write data into the shared memory by using the ptr */
	snprintf(ptr, strlen(message)+1, "%s", message);
	ptr += strlen(message);
	printf("Debugging line: %d\n", __LINE__);
	sleep(10);
	/* Finish the accessing then other process can access it */
	sem_post(sem_id);

	munmap(ptr, SIZE);
	sem_close(sem_id);
	sem_unlink(SEMA_NAME);

	return 0;
}