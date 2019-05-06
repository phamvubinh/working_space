#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h> /* define for S_IRUSR ...*/
#include <unistd.h>   /* define for close read write ...*/
#include <fcntl.h>    /* define file access mode O_RDWR ...*/
#include <stdlib.h>   /* define exit()*/
#include "fifo.h"

int main()
{
	// struct message msg;
	char msg[100] = {0};
	int count = 0;
	char * myFIFO = "/tmp/fifo";
	if (mkfifo(myFIFO, S_IRUSR | S_IWUSR) != 0)
	{
		perror("Cannot create fifo. Already existing\n");
	}

	while(1)
	{
		int fd = open(myFIFO, O_RDWR);
		if(fd == 0)
		{
			perror("Cannot open fifo\n");
			unlink(myFIFO);
			exit(1);
		}

		snprintf(msg, 100, "Message number %d\n", count++);
		int nb = write(fd, msg, 100);
		if (nb == 0)
		{
			fprintf(stderr, "Write error");
		}
		close(fd);
		sleep(1);
	}
	unlink(myFIFO);	
	return 0;
}