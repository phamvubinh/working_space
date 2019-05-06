#include <stdio.h>

void * my_memcpy(void *destination, const void * source, size_t num)
{
	char* des = (char *)destination;
	char* src = (char *)source;

	for (int i = 0; i < num; i++)
	{
		*des++ = *src++;
	}
}

int main(int argc, char const *argv[])
{
	int arr1[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arr2[100] = {0};

	my_memcpy(arr2, arr1, 10*sizeof(int)/sizeof(char));

	for (int i = 0; i < 10; ++i)
	{
		printf("arr2[%d]: %d\n", i , arr2[i]);
	}

	return 0;
}