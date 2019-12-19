#include <stdio.h>
#include <string.h>

#define INFO_NUM 3

/* Most of the C compilers support a third parameter to main which store all envorinment variables */
int main(int argc, char *argv[], char *envp[])
{
	int i = 0, j = 0;
	/* Pointer to save compare string value */
	char *p = NULL;
	/* Array to list required information */
	char *infoList[INFO_NUM] = {"HOME=", "USER=", "_="};

	/* Loop to check all environment variable */
	for (i = 0; envp[i] != NULL; i++)
	{
		/* Loop to check the data is in required list or not */
		for (j = 0; j < INFO_NUM; ++j)
		{
			/* Find the info key in environment data */
			p = strstr(envp[i], infoList[j]);
			if(p != NULL)
			{
				printf("%s folder is: %s\n", infoList[j], p + strlen(infoList[j]));
			}
		}
	}
	return 0;
}
