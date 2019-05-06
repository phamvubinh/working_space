#include <stdio.h>

/*
 * printf() return number of printed character
 * using minimum width init value to print number of chacater that equal a or b or a + b
 */

int add_using_printf(int a, int b)
{
	return printf("%*c%*c", a, ' ', b, ' ');
}

int main(void)
{
	int x = 0;
	int a = 5, b = 6;
	printf("Calculating sum");
	// add_using_printf(a,b);
	printf("%d\n", add_using_printf(a,b));

	return 0;
}
