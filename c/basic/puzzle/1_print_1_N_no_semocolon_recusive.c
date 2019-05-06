/*
 * Print 1 to N without semicolon
 */

#include <stdio.h>

int main(int num)
{
	if (num <= 100 && printf("%d, ", num) && main(num+1))
	{}
}