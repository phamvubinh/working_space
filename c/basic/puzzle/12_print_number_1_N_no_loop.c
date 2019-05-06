#include <stdio.h>

int print_1_N(int n)
{
	int temp = 0;
	if (n > 1)
	{
		temp = 1 + print_1_N(n-1);
		printf("%d ", temp);
		return temp;
	}
	else
	{
		printf("%d ", 1);
		return 1;
	}
}

int print_1_N_v3(int n)
{
	if (n > 0)
	{
		// temp = 1 + print_1_N(n-1);
		print_1_N_v3(n-1);
		printf("%d ", n);
	}
	else
	{
		return 0;
	}
}


#define N 10

int print_1_N_v2(int num)
{
	// int temp = 0;

	if(num > N)
	{
		return 0;
	}
	else
	{
		printf("%d ", num);
		print_1_N_v2(num + 1);
	}
}

int main(int argc, char const *argv[])
{
	print_1_N(5);
	print_1_N_v2(1);
	print_1_N_v3(20);
	return 0;
}