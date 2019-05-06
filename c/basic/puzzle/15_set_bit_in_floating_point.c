/* 
 * Substraction of 1 from a number toggles all the bits (from the light to left) till the rightmost set bit (including the rightmost set bit)
 * So if we substract number by 1 and do bitwise & with itself(n&(n-1)), we unset the rightmost set bit
 * Till the all set bit is unset, n will be 0. So we can count the number of set bit by count the number of loop till n to zero 
 */

#include <stdio.h>

unsigned int countSetBitChar(char n)
{
	unsigned int count = 0;
	while(n)
	{
		n = n & (n-1);

		count++;
	}

	return count;
}

unsigned int countSetBitFloat(float x)
{
	char * charPtr = (char *)&x;
	unsigned int charNum = sizeof(float)/sizeof(char);

	int count = 0;

	for (int i = 0; i < charNum; i++)
	{
		count += countSetBitChar(*charPtr);
		charPtr++;
	}
	return count;
}

unsigned int countSetBitInt(unsigned int x)
{
	char * charPtr = (char *)&x;
	unsigned int charNum = sizeof(unsigned int)/sizeof(char);

	unsigned int count = 0;

	for (int i = 0; i < charNum; i++)
	{
		count += countSetBitChar(*charPtr);
		charPtr++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	float x = 8;
	int y = 8;
	char c = 8;
	printf("Count set bit in char %d: %d\n", c, countSetBitChar(c));
	printf("Count set bit in float %f: %d\n", x, countSetBitFloat(x));
	printf("Count set bit in int %x: %d\n", y, countSetBitInt(y));
	return 0;
}