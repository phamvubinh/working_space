#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
	char arr[2][5] = {"even", "odd"};

	int num;

	num = scanf("%d", &num);

	printf("%d is a %s\n", num, arr[num%2]);
	getch();
	return 0;
}