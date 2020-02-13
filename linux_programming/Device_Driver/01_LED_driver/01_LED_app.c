#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>  	/* For getopt function */

#include "ioctl_LED.h" 	/* Define ioctl control header for magic number */

#define FILENAME "/dev/led"

/* Structure to control led from application */
typedef struct
{
	unsigned int ledIndex;
	unsigned int ledPin;
	unsigned int ledState;
}LED_CONTROL_ST;

int main(int argc, char const *argv[])
{
	int result  = 0;
	int option 	= 0;

	int fd 		= 0;
	int cmd		= 0;

	int index 	= 0;
	int state 	= 0;

	LED_CONTROL_ST ledControl = {0};

	if(argc < 2)
	{
		printf("Not enough parameter\n");
	}

	/* Open device file */
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
	while((option = getopt(argc, (char * const*)argv, ":boi:s:")) != -1)
	{
		switch(option)
		{
			case 'b':
				printf("Blink: %c\n", option);
				cmd = LED_BLINK;
				break;
			case 'o':
				printf("On off: %c\n", option);
				cmd = LED_ON_OFF;
				break;
			case 'i':
				printf("index: %s\n", optarg);
				index = atoi(optarg);
				break;
			case 's':
				printf("state: %s\n", optarg);
				state = atoi(optarg);
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

	ledControl.ledIndex = index;
	ledControl.ledState = state;

	/* Control LED state from argument */
	result = ioctl(fd, cmd, &ledControl);
	if(result)
	{
		printf("ioctl failed\n");
	}

	return 0;
}
