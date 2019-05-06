#include <stdio.h>

void print_put_char(long int num)
{
	if(num < 0)
	{
		putchar('-');
		num = -num;
	}

	if(num>10)
	{
		print_put_char(num / 10);
		putchar(num%10 + '0');
	}
	else
	{
		putchar(num + '0');
	}
}

void print_put_char_2(long int num)
{
	if(num < 0)
	{
		putchar('-');
		num = -num;
	}

	if(num/10)
	{
		print_put_char(num / 10);
	}
	putchar(num%10 + '0');
}


int main(int argc, char const *argv[])
{
	long int num = -1234567890;

	print_put_char(num);
	printf("\n");
	print_put_char_2(num);
	return 0;
}