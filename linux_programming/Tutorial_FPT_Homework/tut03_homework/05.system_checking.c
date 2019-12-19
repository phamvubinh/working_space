#include <stdio.h>
#include <unistd.h> /* For execl function */
#include <fcntl.h>  /* Header file for open option */
#include <string.h>

int main(int argc, char const *argv[])
{
	if(argc < 2)
	{
		return -1;
	}
	else
	{
		if(atoi(argv[1]) == 0)
		{
			/* System command to down eth0 interface */
			system("ifconfig eth0 down");
		}
		else
		{
			system("ifconfig eth0 up");
		}
	}
	return 0;
}
