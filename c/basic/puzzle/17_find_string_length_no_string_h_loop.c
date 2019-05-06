#include <stdio.h>
#include <string.h>

int findStringLen_1(char *str)
{
	return strlen(str);
}

int findStringLen_2(char *str)
{
	int len = 0;
	char * tempPtr = (char *)str;
	while(*tempPtr != '\0')
	{
		len++; 
		tempPtr++;
	}

	return len;
}

int findStringLen_3(int n, char *str)
{
	if(str[n] == '\0')
	{
		/* Return string len */
		return n;
	}
	findStringLen_3(n + 1, str);
}

int main(int argc, char const *argv[])
{
	char str[100] = "sfasdfkajsdsdffh";

	printf("strlen(str): %d\n", findStringLen_1(str));
	printf("string len check null character: %d\n", findStringLen_2(str));
	printf("string len recursion: %d\n", findStringLen_3(0, str));

	return 0;
}