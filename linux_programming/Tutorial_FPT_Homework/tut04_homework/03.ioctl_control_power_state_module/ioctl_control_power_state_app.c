#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#include <fcntl.h>
#include <unistd.h>  /* For getopt function */

#include "ioctl_control.h" /* Define ioctl control header for magic number */

#define FILENAME "/dev/power_state"

int main(int argc, char const *argv[])
{
	int result  = 0;
	int option 	= 0;
	int time 	= 0;
	int fd 		= 0;
	int cmd		= 0;

	if(argc < 2)
	{
		printf("Not enough parameter\n");
	}

	fd = open(FILENAME, O_RDWR);
	if(fd < 0)
	{
		printf("Open failed\n");
	}

	/*
	 * Put ':' in the starting of the
     * String so that program can
     * Distinguish between '?' and ':'
	 */
	while((option = getopt(argc, (char * const*)argv, ":srt:")) != -1)
	{
		switch(option)
		{
			case 's':
				printf("Shutdown: %c\n", option);
				cmd = POWER_SHUTDOWN;
				break;
			case 'r':
				printf("Restart: %c\n", option);
				cmd = POWER_RESTART;
				break;
			case 't':
				printf("Time: %s\n", optarg);
				time = atoi(optarg);
				break;
			case ':':
				printf("Option needs a value\n");
				break;
			case '?':
				printf("Unknown option: %c\n", optopt);
				break;
		}
	}

	/*
	 * Optind is for the extra arguments
     * Which are not parsed
     */
	for(; optind < argc; optind++)
	{
		printf("extra arguments: %s\n", argv[optind]);
	}

	/* Control by command and time value */
	result = ioctl(fd, cmd, &time);
	if(result)
	{
		printf("ioctl failed\n");
	}

	return 0;
}
