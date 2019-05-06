#include <stdio.h>
#include <stdbool.h>

void swap_char(unsigned char *x, unsigned char *y)
{
	unsigned char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int ftoa(double fNum, char* str, int afterpoint)
{	
	double   tempNum  = 0;
	long int powerNum = 1;
	bool 	 isNeg = false;
	int i = 0, len = 0;

	if (fNum < 0)
	{
		isNeg   = true;
		tempNum = -fNum;
	}
	else
	{
		tempNum = fNum;
	}

	for (int i = 0; i < afterpoint; i++)
	{
		powerNum *= 10;
	}

	tempNum = tempNum*powerNum;

	for (i = 0; i < afterpoint; i++)
	{
		str[i]  = (int)tempNum%10 + '0';
		tempNum = (int)tempNum/10;
	}

	str[i++] = '.';

	while(tempNum)
	{
		str[i++]  = (int)tempNum%10 + '0';
		tempNum = (int)tempNum/10;
	}

	if(isNeg)
	{
		str[i++] = '-';
	}
	str[i] = '\0'; 
	len = i;

	for(i = 0; i < len/2; i ++)
	{
		swap_char(&str[i], &str[len-i-1]);
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	double f = -12.345678;
	char res[100] = {0};

	ftoa(f, res, 6);
	printf("%s\n", res);

	return 0;
}