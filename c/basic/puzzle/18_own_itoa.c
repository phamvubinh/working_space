#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *my_itoa(int value, char* string, int radix)
{
	if (string == NULL)
	{
		return NULL;
	}

	char tempStr[100] = {};

	int index = 0;
	bool isNegative = false;

	if(value < 0)
	{
		isNegative = true;
		value = -value;
	}

	while (value)
	{
		if(value % radix > 9)
		{
			tempStr[index++] = value % radix + 'a';
		}
		else
		{
			tempStr[index++] = value % radix + '0';	
		}
		value = value/radix; 	
	}

	if(isNegative)
	{
		tempStr[index++] = '-'; 
	}
	tempStr[index] = '\0';

	for (int i = index; i >= 0; i--)
	{
		string[index-i] = tempStr[i - 1];
	}

	return string;
}

int main(int argc, char const *argv[])
{
	int a = -54325;
    char buffer[20] = {0};
    char *result;
    result = itoa(a, buffer, 10);   // here 2 means binary
    printf("value = %s\n", buffer);
    printf("return value = %s\n", result);

    result = my_itoa(a, buffer, 10);   // here 2 means binary
    printf("value = %s\n", buffer);
	printf("return value = %s\n", result);    

	int b = 20;
 	result = my_itoa(b, buffer, 16);   // here 2 means binary
    printf("value = %s\n", buffer);
	printf("return value = %s\n", result);    

	return 0;
}