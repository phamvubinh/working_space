#include <stdio.h>

#define CONVERT_TO_STR(x) #x
int main(int argc, char const *argv[])
{
	printf(CONVERT_TO_STR(HELLO OCTO));
	return 0;
}