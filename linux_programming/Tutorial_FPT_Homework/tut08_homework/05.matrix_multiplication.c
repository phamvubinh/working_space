#include <stdio.h>
#include <time.h>
#include <stdlib.h> /* malloc header file */
#include <string.h>
#include <pthread.h>


/* Define for Single or Multi thread example */
#define SINGLE 0

/* Define number of array */
#define MAX_MATRIX_NUM 	2ULL
/* Define matrix size */
#define MAX_SIZE 		2ULL

/* Define thread number */
#define MAX_THREAD 		4ULL

/* Access matrix[i][j] */
#define M_ACCESS(matrix,i,j)  *((matrix+i*MAX_SIZE) + j)


/* Global variable */
static unsigned long long *s_pResultMatrix = NULL;
static unsigned long long  step_i = 0;

/* Define MAX_MATRIX_NUM matrices */
unsigned long long matrixTest[MAX_MATRIX_NUM][MAX_SIZE][MAX_SIZE] = {{{0}}};

/* Display matrix function decleration */
void MATRIX_Display(unsigned long long *matrix);

/* Init unit matrix */
void MATRIX_SetUnitMatrix(unsigned long long *matrix);

/* Init random matrix */
void MATRIX_SetRandomMatrix(unsigned long long *matrix);

/* Multiple two matrix  */
void MATRIX_MultipleSingleThread(unsigned long long *matrix1, unsigned long long *matrix2);

void* MATRIX_MULTI_Task(void* arg)
{
	unsigned long long core = step_i++;

	unsigned long long i = 0;
	unsigned long long j = 0;
	unsigned long long k = 0;

	unsigned long long *matrix1 = (unsigned long long *)matrixTest[0];
	unsigned long long *matrix2 = (unsigned long long *)matrixTest[1];

	/* Each thread now will be a core for multiple process */
	for (k = core * MAX_SIZE / 4; k < (core + 1) * MAX_SIZE / 4; k++)
	{
		for (i = 0; i < MAX_SIZE; i++)
		{
			for (j = 0; j < MAX_SIZE; j++)
			{
				M_ACCESS(s_pResultMatrix,k,i) += M_ACCESS(matrix1,k,j) * M_ACCESS(matrix2,j,i);
			}
		}
	}
}

int	main(int argc, char const *argv[])
{
#if (SINGLE == 1)
	unsigned long long i = 0;
	srand(time(NULL));

	for (i = 0; i < MAX_MATRIX_NUM; i++)
	{
		MATRIX_SetRandomMatrix((unsigned long long *)matrixTest[i]);
		// MATRIX_Display((unsigned long long *)matrixTest[i]);
	}

	/* Init result matrix */
	s_pResultMatrix = (unsigned long long *)malloc(sizeof(unsigned long long)*MAX_SIZE*MAX_SIZE);
	MATRIX_SetUnitMatrix((unsigned long long *)s_pResultMatrix);
	/* Multiple all matrix */
	for (i = 0; i < MAX_MATRIX_NUM; i++)
	{
		MATRIX_MultipleSingleThread(s_pResultMatrix, (unsigned long long *)matrixTest[i]);
	}
	MATRIX_Display((unsigned long long *)s_pResultMatrix);
#else
	unsigned long long i = 0;

	/* Declearing four thread */
	pthread_t threads[MAX_THREAD];

	/* Init result matrix */
	s_pResultMatrix = (unsigned long long *)malloc(sizeof(unsigned long long)*MAX_SIZE*MAX_SIZE);
	// MATRIX_SetUnitMatrix((unsigned long long *)s_pResultMatrix);

	/* Init test matrix */
	srand(time(NULL));
	for (i = 0; i < MAX_MATRIX_NUM; i++)
	{
		MATRIX_SetRandomMatrix((unsigned long long *)matrixTest[i]);
		MATRIX_Display((unsigned long long *)matrixTest[i]);
	}

	/* Creating four threads, each evaluating its own part */
	for (i = 0; i < MAX_THREAD; i++)
	{
		pthread_create(&threads[i], NULL, MATRIX_MULTI_Task, (void *)NULL);
	}

	/* Joining and waiting for all threads to complete */
	for (i = 0; i < MAX_THREAD; i++)
	{
		pthread_join(threads[i], NULL);
	}

	MATRIX_Display((unsigned long long *)s_pResultMatrix);

#endif
	return 0;
}

/* Display matrix function definitaion */
void MATRIX_Display(unsigned long long *matrix)
{
	unsigned long long i = 0, j = 0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		for (j = 0; j < MAX_SIZE; j++)
		{
			printf("%lld ", M_ACCESS(matrix,i,j));
		}
		printf("\n");
	}
	printf("\n");
}

/* Init unit matrix */
void MATRIX_SetUnitMatrix(unsigned long long *matrix)
{
	unsigned long long i = 0;
	unsigned long long j = 0;
	for(i = 0; i < MAX_SIZE; i++)
	{
		for(j = 0; j < MAX_SIZE; j++)
		{
			if(j == i)
			{
				/* Access matrix[i][j] to change value to 1 */
				M_ACCESS(matrix,i,j) = 1;
			}
		}
	}
}

/* Init random matrix */
void MATRIX_SetRandomMatrix(unsigned long long *matrix)
{
	unsigned long long i = 0;
	unsigned long long j = 0;

	for(i = 0; i < MAX_SIZE; i++)
	{
		for(j = 0; j < MAX_SIZE; j++)
		{

			/* Access matrix[i][j] to change value to 1 */
			M_ACCESS(matrix,i,j) = rand()%10;
		}
	}
}

/* Multiple two matrix R[k][i] += M1[k][j] * M2[j][i] */
void MATRIX_MultipleSingleThread(unsigned long long *matrix1, unsigned long long *matrix2)
{
	unsigned long long i = 0;
	unsigned long long j = 0;
	unsigned long long k = 0;

	/* Init temp result matrix */
	unsigned long long *tempResultMatrix = (unsigned long long *)malloc(sizeof(unsigned long long)*MAX_SIZE*MAX_SIZE);
	memset(tempResultMatrix, 0, sizeof(unsigned long long)*MAX_SIZE*MAX_SIZE);

	for (k = 0; k < MAX_SIZE; k++)
	{
		for (i = 0; i < MAX_SIZE; i++)
		{
			for (j = 0; j < MAX_SIZE; j++)
			{
				M_ACCESS(tempResultMatrix,k,i) += M_ACCESS(matrix1,k,j) * M_ACCESS(matrix2,j,i);
			}
		}
	}

	for (i = 0; i < MAX_SIZE; i++)
	{
		for (j = 0; j < MAX_SIZE; j++)
		{
			M_ACCESS(s_pResultMatrix, i, j) =  M_ACCESS(tempResultMatrix, i, j);
		}
	}

	free(tempResultMatrix);
}
