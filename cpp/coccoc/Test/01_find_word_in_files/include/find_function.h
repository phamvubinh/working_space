#ifndef __FIND_FUNCTION_H__
#define __FIND_FUNCTION_H__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class find_function
{
private:
	/* Vector to save word list */
	vector<string> word_list;	

	/* Vector to save file list */
	vector<string> file_list;

	/* Variable to save find mode */
	bool total_match;

public:
	find_function();
	~find_function();

	/* Funcion to find all file name from folder */
	void find_filelist_boost(string &folder_path);

	/* Function to get file list */
	void get_filelist();

	/* Function to set word list from parameter */
	void set_wordlist(string &word_list_string);

	/* Funtion to get word list */
	void get_wordlist();
	
	/* Funtion used to find a word exist in file or not */
	bool find_word(string &file, string &word);

	/* Function to find a word list existed in file list or not */
	bool find_word(string &file, vector<string> word_list);

	/* Final function to seach word list in all file */
	void find_word(bool total_match = true);

};

#endif