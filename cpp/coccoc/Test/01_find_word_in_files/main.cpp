#include <iostream>
#include "find_function.h"

using namespace std;

int main(int argc, char const *argv[])
{
	/* Init class fir find function */
	find_function ff;

	/* String to save path variable */
	string path = "";

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
	// ff.get_filelist();

	/* Update the word string to word list */
	string word = argv[1];
	ff.set_wordlist(word);
	// ff.get_wordlist();

	/* Find word list in all file set true or false option to make  */
	ff.find_word(true);

	/* End of counting time */
	finishTime = time(NULL);

	cout << "Running time: " << finishTime - startTime << endl;

	return 0;
}