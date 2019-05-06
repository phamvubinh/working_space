#include <stdio.h>

int roundNo(float num)
{
	return num < 0 ? num -0.5 : num + 0.5;
}

int main(int argc, char const *argv[])
{
	float x = 1.77;
	/* %.*f for the number after . of float */
	printf("Round number of %.*f is %d\n", 2, x, roundNo(x));
	return 0;
}