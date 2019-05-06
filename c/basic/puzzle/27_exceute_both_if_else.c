#include <stdio.h>

int main(int argc, char const *argv[])
{
	if(0)
	{
		LABEL_1:
		printf("Running condition 1\n");
		goto LABEL_2;
	}
	else
	{
		goto LABEL_1;
		LABEL_2:
		printf("Running condition 2\n");

	}
	return 0;
}