#include <iostream>
#include <pthread.h>

#include <time.h>		/* For time checking function */

#include "find_function.h"
using namespace std;

#define THREAD_NUM 4

/* Init class for find function */
static find_function ff;

void * find_word_task(void * param)
{
	/* Variable to get thread index */
	int *thread_num = (int *) param;
	/* Vector to get file list */
	vector<string> file_list = ff.get_filelist();

	/* Vector to get word list */
	vector<string> word_list = ff.get_wordlist();

	/* Init start and end index to search in file list, each part equal 1/THREAD_NUM of file list size */
	unsigned int start = (*thread_num) * file_list.size() / THREAD_NUM;
	unsigned int end   = (*thread_num + 1) * file_list.size() / THREAD_NUM;

	/* The loop to search in new file list */
	for (unsigned int i = start; i < end; ++i)
	{
		/* Access each file from list to search */
		if(ff.find_word(file_list[i], word_list) == true)
		{
			/* Print file name if found word list on it */
			cout << file_list[i] << endl;
		}
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	/* String to save path variable */
	string path = "";
	string word_list_string;
	/* Thread list array for management */
	pthread_t thread_list[THREAD_NUM];

	/* Variable to save time */
	time_t startTime  = {0};
	time_t finishTime = {0};

	/* Start counting the time */
	startTime = time(NULL);

	/* If there is only 2 argument then check current dir */
	if (argc == 2)
	{
		path = "./";
	}
	else if(argc == 3)
	{
		/* If there are 3 argument the save word string into word list */
		path = (string) argv[2];
	}
	else
	{
		cout << "Usage: ./coccoc \"many words\" [path to dictionary]\n";
		return 0;
	}

	/* Find all the file in folder and update to list */
	ff.find_filelist_boost(path);
	word_list_string = argv[1];
	ff.set_wordlist(word_list_string);
	ff.set_mode(false);

	for (int i = 0; i < THREAD_NUM; ++i)
	{
		/* Create thread list base on machine capabilities */
		(void) pthread_create(&thread_list[i], NULL, find_word_task, (void *)&i);
		/* Join to wait the thread finish */
		(void) pthread_join(thread_list[i], NULL);
	}

	/* End of counting time */
	finishTime = time(NULL);

	cout << "Running time: " << finishTime - startTime << endl;

	return 0;
}