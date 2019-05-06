#include <stdio.h>

int main(void)
{
	if(!printf("Hello "))
	{
		printf("Hello");
	}
	else
	{
		printf("World");
	}
	return 0;
}