#include <stdio.h>			/* Standard buffered input/output */
#include <stdlib.h>		 	/* Four variable types, several macros, and various functions for performing general functions */
#include <string.h>
#include <fcntl.h>		 	/* File control options */
#include <sys/shm.h>     	/* Share memory facility */
#include <sys/stat.h>    	/* Data return by stat() function */
#include <sys/mman.h>    	/* Memory map function decleration */

#define SIZE 4096

int main(int argc, char const *argv[])
{
	const char * shm_name = "/BEN";
	int i, shm_fd;

	const char *message = "This is about shared memory\n";

	void * ptr;

	/* Create shared memory segment referred by name */
	shm_fd = shm_open(shm_name, O_CREAT| O_RDWR, 0666);
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

	/* Write data into the shared memory by using the ptr */
	snprintf(ptr, strlen(message)+1, "%s", message);
	ptr += strlen(message);

	munmap(ptr, SIZE);

	return 0;
}