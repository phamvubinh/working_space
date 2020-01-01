#include <stdio.h>   /* print and put function */
#include <stdlib.h>  /* atoi function */
#include <signal.h>  /* signal function */
#include <unistd.h>  /* sleep function */
#include <string.h>

#include <sys/shm.h>  /* shm_open function */
#include <sys/mman.h> /* mmap function */

#include <fcntl.h>    /* open file option */

#include "share_mem_info.h"

/* Pointer to mapped memory on virtual address */
void * p_shm = NULL;

int32_t share_memory_init(void)
{
	/* File descriptor to manage created share mem file */
	int shm_fd = 0;

	/* Create the file for share memory management */
	shm_fd = shm_open(SHARE_MEM_NAME, O_RDWR, 0777);
	if (shm_fd < 0)
	{
		return -1;
	}

	/* Function to set physical memory size is not needed because it is created in server side */
	/* ftruncate(shm_fd, SHARE_MEM_SIZE); */

	/* Map the phisical memory to virtual memory address */
	p_shm = mmap(SHM_VIRTUAL_START_ADDR, SHARE_MEM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, SHM_PHYSICAL_OFFSET_ADDR);
	if(!p_shm)
	{
		printf("Mmap invalid pointer\n");
		return -1;
	}
	return 0;
}

int32_t share_memory_write(SHARE_MEM_DATA_ST *data)
{
	SHARE_MEM_DATA_ST *share_data = NULL;
	if(!p_shm)
	{
		printf("Invalid pointer\n");
		return -1;
	}
	share_data = (SHARE_MEM_DATA_ST *)p_shm;
	share_data->age = data->age;
	memset(share_data->name, 0, sizeof(share_data->name));
	snprintf(share_data->name, strlen(data->name) + 1, "%s", data->name);
	return 0;
}

int main(int argc, char const *argv[])
{
	int result = 0;

	SHARE_MEM_DATA_ST share_mem_data = {{0}};
	char buff[1024] = {0};
	result = share_memory_init();
	if((result != 0) || ((p_shm == NULL)))
	{
		printf("share_memory_init failed\n");
		return -1;
	}

	/* While loop to get share_mem_data from user */
	while(1)
	{
		/* Get share_mem_data from user */
		printf("Username: ");
		gets(share_mem_data.name);
		printf("Age: ");
		gets(buff);
		share_mem_data.age = atoi(buff);
		/* Write share_mem_data to share memory */
		share_memory_write(&share_mem_data);
		/* Send the signal to other process by using agrument */
		kill(atoi(argv[1]), SIGUSR1);
	}
	return 0;
}
