#include <time.h>
#include <stdio.h>
#include <unistd.h>

void checking_func(void)
{
	printf("Function is starting\n");
	printf("Enter to stop func \n");
	while(1)
	{
		// if(getchar())
		// {
		// 	break;
		// }
		sleep(5);
		printf("Function ends \n");
		break;
	}
}

/* The main program calls func() and measures time taken by func() */
int main(void)
{
	clock_t start, end;
	double cpu_time_used;
	
	start = clock();	
	checking_func();

	end = clock();

	cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;

	printf("Function take time: %f\n", cpu_time_used);

	// getchar();
	return 0;
}
