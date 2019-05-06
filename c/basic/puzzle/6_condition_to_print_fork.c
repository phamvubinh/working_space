#include <stdio.h>

#include <unistd.h>

int main()
{
	if(fork())
		printf("Hello");
	else
		printf("World");
	return 0;
}