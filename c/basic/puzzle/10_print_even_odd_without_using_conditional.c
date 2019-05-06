#include <stdio.h>
#include <stdlib.h>
int main()
{
	
	int n = 0;

	printf("Enter a num: ");

	scanf("%d", &n);

	(n & 1 && printf("odd")) || printf("even");

	getch();
	return 0;
}