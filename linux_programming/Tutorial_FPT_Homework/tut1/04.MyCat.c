#include <stdio.h>
#include <fcntl.h>  /* File open option header */
#include <unistd.h> /* System call file header */

int main(int argc, char const *argv[])
{
	/* Check if Usage is correct or not */
	if(argc != 2)
	{
		printf("Not enough parameter\n");
		printf("Usage: 04.MyCat <filename>\n");
	}
	else
	{
		int fd = -1;
		int i = 0;
		/* Open file to get content if it is valid */
		if(argv[1] != NULL)
		{
			fd = open(argv[1], O_RDONLY);
			if(fd < 0)
			{
				printf("Cannot open file name: \n", argv[1]);
			}
			else
			{
				/* Read content from valid file BYTE by BYTE and print out */
				int readNum = 0;
				char c = 0;
				while(1)
				{
					/* Get BYTE content */
					readNum = read(fd, &c, 1);
					
					/* Expected value is 1, if not it is End of File */
					if(readNum == 1)
					{
						/* Print content to output */
						printf("%c", c);
					}
					else
					{
						/* Break when end of file */
						break;
					}
					
				}
			}
		}
		else
		{
			printf("File name is NULL\n");
		}	
		
	}
	return 0;
}