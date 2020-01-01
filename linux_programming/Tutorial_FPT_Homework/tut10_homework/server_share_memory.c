#include <stdio.h>   /* print and put function */
#include <stdbool.h> /* boolen type */
#include <unistd.h>  /* sleep function */

#include <signal.h>  /* signal function */

#include <sys/shm.h>  /* shm_open function */
#include <sys/mman.h> /* mmap function */

#include <fcntl.h>    /* open file option */

#include "share_mem_info.h"

volatile bool b_sleepFlag = true;

/* Pointer to mapped memory on virtual address */
void * p_shm = NULL;

void sig_wakeup_handler(int sig)
{
	/* Print signal number */
	printf("sig_wakeup_handler: %d\n", sig);
	/* Change sleep flag to wakeup */
	b_sleepFlag = false;
}

int32_t share_memory_init(void)
{
	/* File descriptor to manage created share mem file */
	int shm_fd = 0;

	/* Create the file for share memory management */
	shm_fd = shm_open(SHARE_MEM_NAME, O_RDWR | O_CREAT, 0777);
	if (shm_fd < 0)
	{
		return -1;
	}

	/* Function to set physical memory size */
	ftruncate(shm_fd, SHARE_MEM_SIZE);

	/* Map the phisical memory to virtual memory address */
	p_shm = mmap(SHM_VIRTUAL_START_ADDR, SHARE_MEM_SIZE, PROT_READ, MAP_SHARED, shm_fd, SHM_PHYSICAL_OFFSET_ADDR);
	if(p_shm == NULL)
	{
		printf("Mmap invalid pointer\n");
		return -1;
	}
	return 0;
}

int32_t share_memory_read(void)
{
	SHARE_MEM_DATA_ST *share_data = NULL;
	if(p_shm == NULL)
	{
		printf("Invalid pointer\n");
		return -1;
	}
	share_data = (SHARE_MEM_DATA_ST *)p_shm;
	printf("share_data->name: %s\n", share_data->name);
	printf("share_data->age: %d\n", share_data->age);
	return 0;
}

int main(int argc, char const *argv[])
{
	int result = 0;

	/* Register the signal function to SIGUSR1 to wake up server */
	signal(SIGUSR1, sig_wakeup_handler);
	/* Init share memory to start data transfering */
	result = share_memory_init();
	if((result != 0) || ((p_shm == NULL)))
	{
		printf("share_memory_init failed\n");
		return -1;
	}
	/* Loop to sleep and wake up when receive request from client */
	while(1)
	{
		if(b_sleepFlag)
		{
			sleep(1);
		}
		else
		{
			printf("Server wake up and start get info from client\n");
			/* Read data from share memory */
			share_memory_read();
			/* Continue sleeping */
			b_sleepFlag = true;
		}
	}
	return 0;
}
