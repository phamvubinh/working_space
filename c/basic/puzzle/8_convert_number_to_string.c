#include <stdio.h>

int main(int argc, char const *argv[])
{
	char string[50] = {};

	float f = 45.56;

	int i = 1234;

	sprintf(string, "%f", f);
	printf("Converted string by sprintf is %s\n", string);

	int j = snprintf(string, 4, "%d", i);	
	printf("Converted string by sNprintf is %s\n", string);

	printf("string: %s\ncharacter count = %d\n", 
                                     string, j); 
	return 0;
}