#include <stdio.h>

#define N 100

int main(int num)
{
	while(num <= N && printf("%d ", num) && num++)
	{}
}