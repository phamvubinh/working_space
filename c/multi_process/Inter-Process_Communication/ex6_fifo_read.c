#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h> /* define for S_IRUSR ...*/
#include <unistd.h>   /* define for close read write ...*/
#include <fcntl.h>    /* define file access mode O_RDWR ...*/
#include <stdlib.h>   /* define exit()*/

int main()
{
	char msg[100]; 
	char * myFIFO = "/tmp/fifo";
	while(1)
	{
		int fd = open(myFIFO, O_RDONLY);
		if (fd == 0)
		{
			perror("Cannot open fifo");
			unlink(myFIFO);
			exit(1);
		}

		read(fd, msg, 100);
		printf("Message: %s\n", msg);
		close(fd);
	}
	unlink(myFIFO);
	return 0;
}