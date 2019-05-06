#include <stdio.h>

/* Address of 2 next variables to calculate  */
#define my_sizeof(var) (char *)(&var + 1) - (char *)(&var)

int main(int argc, char const *argv[])
{
	int x;

	printf("%ld", my_sizeof(x));

	return 0;
}