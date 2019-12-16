#include <stdio.h>

int main(void)
{
	int i = 0;
	/* Define file pointer which point to FILE type*/
	FILE* fp;
	/* Define data buffer to write to a file */
	char data[] = "This is data of testing file: AAA\n";
	/* Define buffer to read data */
	char buffer[50], c;

	/* Create a file to add content 
	   Open for reading and writting overwritting */
	fp = fopen("02.file_content.txt", "w+");
	/* Writting data to a file by fputc*/
	for(i = 0; data[i] != '\0'; i++)
	{
		fputc(data[i], fp);
	}
	/* Close a file using file pointer */
	fclose(fp);

	/* Now we will append data to the file */
	/* Open the file with appending mode */
	fp = fopen("02.file_content.txt", "a+");
	/* Write data into file by using fputs function */
	fputs("Use fputs funtion to append data: BBB\n", fp);
	/* Write data using fprintf function */
	fprintf(fp, "Use fprintf function to append data: CCC\n");
	fclose(fp);

	/* Open file to read content */
	fp = fopen("02.file_content.txt", "r");
	/* Read a line */
	printf("-------------------------\n");
	printf("Read data from a line: \n");
	fgets(buffer, 50, fp);
	printf("%s", buffer);
	printf("-------------------------\n");
	/* Parsing data by known format
	   Note that pointer will continue jump */
	char str1[10], str2[2], str3[20], str4[20];
	printf("-------------------------\n");
	printf("Parsing data by known format: \n");
	fscanf(fp, "%s %s %s %s", str1, str2, str3, str4);
	printf("String 1: [%s]\n", str1);
	printf("String 2: [%s]\n", str2);
	printf("String 3: [%s]\n", str3);
	printf("String 4: [%s]\n", str4);
	printf("-------------------------\n");
	/* Read data from start till end of file */
	printf("-------------------------\n");
	printf("Reading all file: \n");
	/* Reset file pointer to begin */
	fp = fopen("02.file_content.txt", "r");
	/* Read file till character is not EOF */
	while ((c = getc(fp)) != EOF)
	{
		/* Print content of character */
		printf("%c", c);
	}
	fclose(fp);
} 
