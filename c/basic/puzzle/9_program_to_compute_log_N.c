#include <stdio.h>

int findLog2N(int n)
{
	if(n > 1)
	{
		return 1 + findLog2N(n/2);
	}
	else
	{
		return 0;
	}
}

// unsigned int Log2n(unsigned int n) 
// { 
//     return (n > 1) ? 1 + Log2n(n / 2) : 0; 
// } 

int main(int argc, char const *argv[])
{
	int n = 64;
	printf("Log2 of %d is %d", n, findLog2N(64));
	return 0;
}