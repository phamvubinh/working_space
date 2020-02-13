#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/mman.h>

#define SIZE 4096

int main(int argc, char const *argv[])
{
	int i, fd;
	int shm_fd; 
	void * ptr;

	char * shm_name = "/BEN";

	shm_fd = shm_open(shm_name, O_RDWR, 0666);
	if(shm_fd == -1)
	{
		printf("shm_open error\n");
	}

	ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if(ptr == MAP_FAILED)
	{
		printf("Map failed\n");
		return -1;
	}

	/* Get data from ptr, casted to char value */
	printf("%s", (char *) ptr);

	munmap(ptr, SIZE);
	if(shm_unlink(shm_name) == -1)
	{
		printf("Error removing %s\n", shm_name);
	}

	return 0;
}