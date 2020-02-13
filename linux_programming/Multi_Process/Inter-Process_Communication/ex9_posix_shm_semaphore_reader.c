#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/mman.h>

#include <semaphore.h>

#define SIZE 4096

#define SHM_NAME "/SHM_BEN"
#define SEMA_NAME "/SEMA_BEN"

int main(int argc, char const *argv[])
{
	int i, fd;
	int shm_fd; 
	void * ptr;

	shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
	if(shm_fd == -1)
	{
		printf("shm_open error\n");
	}

	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	if(ptr == MAP_FAILED)
	{
		printf("Map failed\n");
		return -1;
	}

	printf("Debugging line: %d\n", __LINE__);
	sem_t * sem_id = sem_open(SEMA_NAME, O_CREAT, S_IRUSR | S_IWUSR, 1);

	printf("Debugging line: %d\n", __LINE__);
	sem_wait(sem_id);
	/* Get data from ptr, casted to char value */
	printf("%s", (char *) ptr);
	sem_post(sem_id);

	printf("Debugging line: %d\n", __LINE__);
	munmap(ptr, SIZE);
	if(shm_unlink(SHM_NAME) == -1)
	{
		printf("Error removing %s\n", SHM_NAME);
	}

	printf("Debugging line: %d\n", __LINE__);
	sem_close(sem_id);
	sem_unlink(SEMA_NAME);

	return 0;
}