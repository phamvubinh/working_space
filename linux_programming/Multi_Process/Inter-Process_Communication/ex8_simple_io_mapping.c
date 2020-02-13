#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char const *argv[])
{
	int  fd = 0; 
	int  i  = 0;
	char *p = NULL;

	printf("Open and map file name: %s\n", argv[1]);
	fd = open(argv[1], O_RDWR);
	p = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	printf("Read data from file: \n");
	while((char*)p != EOF)
	{
		putchar((char)*p++);
	}
	return 0;
}