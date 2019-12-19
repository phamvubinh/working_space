#include <stdio.h>
#include <dirent.h>    /* This file to use readdir function */
#include <string.h>    /* String function */
#include <sys/stat.h>  /* Header for mkdir function */
#include <stdlib.h>    /* Malloc Calloc function */

/* Function to get file mode and convert to string */
int FILE_MODE_Get(char *fileName, char *modeStr)
{
	int result = 0;
	struct stat st = {0};

	result = stat(fileName, &st);
	if(result != 0)
	{
		printf("Cannot get status of file\n");
		return -1;
	}

	/* Check pointer condition */
	if(modeStr == NULL)
	{
		printf("Need to setup pointer\n");
		return -1;
	}
	/* Check file is folder or directory */
	modeStr[0] = S_ISDIR(st.st_mode) ? 'd' : '-';
	modeStr[1] = st.st_mode & S_IRUSR ? 'r' : '-';
	modeStr[2] = st.st_mode & S_IWUSR ? 'w' : '-';
	modeStr[3] = st.st_mode & S_IXUSR ? 'x' : '-';
	modeStr[4] = st.st_mode & S_IRGRP ? 'r' : '-';
	modeStr[5] = st.st_mode & S_IWGRP ? 'w' : '-';
	modeStr[6] = st.st_mode & S_IXGRP ? 'x' : '-';
	modeStr[7] = st.st_mode & S_IROTH ? 'r' : '-';
	modeStr[8] = st.st_mode & S_IWOTH ? 'w' : '-';
	modeStr[9] = st.st_mode & S_IXOTH ? 'x' : '-';
	return 0;
}

/* Function to operate the command */
int CMD_Operate(const char *option, const char *pathName)
{
	/* Pointer to directiry entry */
	struct dirent *de;
	/* DIR pointer to save open data from dir */
	DIR *dr = NULL;

	if(pathName)
	{
		dr = opendir(pathName);
	}
	else
	{
		/* Open current dir if pathname is NULL */
		dr = opendir(".");
	}

	if(dr == NULL)
	{
		printf("Could not open directory\n");
		return -1;
	}

	/* Check if option is valid */
	if(option)
	{
		/* Check -a option */
		if(strcmp(option, "-a") == 0)
		{
			while((de = readdir(dr)) != NULL)
			{
				/* List up all file include hidden file */
				printf("%s\n", de->d_name);
			}
		}
		else if(strcmp(option, "-l") == 0)
		{
			char *modeStr = (char*)malloc(sizeof(char)*10);
			char *newFileName = (char*)malloc(sizeof(char)*30);
			while((de = readdir(dr)) != NULL)
			{
				/* List up all file include hidden file */
				if(de->d_name[0] != '.')
				{
					memset(modeStr, '-', 10);
					/* Need to update file name with current folder */
					snprintf(newFileName, strlen(pathName) + strlen(de->d_name) + 1, "%s%s\n", pathName, de->d_name);
					FILE_MODE_Get(newFileName, modeStr);
					printf("%-12s %-20s\n", modeStr, de->d_name);
				}
			}
			free(modeStr);
		}
		else if((strcmp(option, "-al") == 0) || (strcmp(option, "-la") == 0))
		{
			char *modeStr = (char*)malloc(sizeof(char)*10);
			char *newFileName = (char*)malloc(sizeof(char)*30);
			while((de = readdir(dr)) != NULL)
			{
					/* List up all file include hidden file */
					memset(modeStr, '-', 10);
					snprintf(newFileName, strlen(pathName) + strlen(de->d_name) + 1, "%s%s\n", pathName, de->d_name);
					FILE_MODE_Get(newFileName, modeStr);
					printf("%-12s %-20s\n", modeStr, de->d_name);
			}
			free(modeStr);
			free(newFileName);
		}
		else
		{
			printf("Usage: 01.my_ls [-a | -l | -al]");
		}
	}
	else
	{
		while((de = readdir(dr)) != NULL)
		{
			/* If the first file or foleder name has '.' that mean it is current or hidden folder */
			/* So we will not list it here */
			if(de->d_name[0] != '.')
			{
				printf("%s\n", de->d_name);
			}
		}
	}
	closedir(dr);
	return 0;
}

int main(int argc, char const *argv[])
{
	/* Check if only my_ls command, then we will check current folder */
	if(argc == 1)
	{
		return CMD_Operate(NULL, NULL);
	}
	/* Pass option to the command operation */
	else if(argc == 2)
	{
		return CMD_Operate(argv[1], NULL);
	}
	/* Pass option and pathname to command operation */
	else if(argc == 3)
	{
		return CMD_Operate(argv[1], argv[2]);
 	}
	else
	{
		printf("Usage: 01.my_ls [-a | -l | -al]");
	}
	return 0;
}
