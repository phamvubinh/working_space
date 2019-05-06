#include <stdio.h>
#include <stdlib.h>

#define nomain_1 main
#define nomain_2 m##a##i##n
// entry point function
int nomain();

void _start()
{
	// calling entry point 
	nomain();
	exit(0);
}

int nomain_1(void)
{
	printf("Hello nomain_1\n");
}

int nomain()
{
	printf("Hello nomain\n");
}