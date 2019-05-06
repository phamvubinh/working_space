#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n = 678;

	int sum = 0;

	int temp = n;
	while(temp>0)
	{
		sum += (int)temp%10;
		temp = temp/10;
	}

	printf("Sum digit of %d is %d\n", n, sum);

	for (sum = 0; n > 0; sum += n % 10, n /= 10); 
	printf("Sum digit in single line is %d\n", sum);

	return 0;
}