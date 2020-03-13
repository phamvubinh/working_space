#include <vector>
#include <string>
#include <iostream>

#include <find_function.h>
#include <boost/filesystem.hpp>

#include <fstream> /* For file accessing */
#include <sstream> /* For string stream function */

using namespace std;
using namespace boost::filesystem;

find_function::find_function()
{}

find_function::~find_function()
{}

/* Funcion to find all file name from folder */
void find_function::find_filelist_boost(string &folder_path)
{
	path path_name(folder_path);
	string file_name = "";

	/* Iterator to check all item in folder */
	for (auto i = directory_iterator(path_name); i != directory_iterator(); i++)
	{
		/* Check if the path is folder or file */
		if (!is_directory(i->path()))
		{
			/* Add file name to the list if it is a file */
			file_name = folder_path + i->path().filename().string();
			file_list.push_back(file_name);
		}
		else
		{
			/* Update the sub folder name */
			string sub_folder = folder_path + i->path().filename().string() + "/";
			/* Run regression to find file in sub folder */
			find_function::find_filelist_boost(sub_folder);
		}
	}
}

/* Function to get file list */
vector<string> find_function::get_filelist()
{
	/* Return the current file list to check from outside */
	return this->file_list;
}

/* Function to set word list from parameter */
void find_function::set_wordlist(string &word_list_string)
{
	/* Convert string to stream to use getline function */
	stringstream check_line(word_list_string);
	/* Token string inside string */
	string token;

	/* Use space seperator to get token inside string stream */
	while(getline(check_line, token, ' '))
	{
		word_list.push_back(token);
	}
}

/* Function to get word list */
vector<string> find_function::get_wordlist()
{
	/* Return the current file list to check from outside */
	return this->word_list;
}

/* Funtion used to find a single word exist in a single file or not */
bool find_function::find_word(string &file, string &word)
{
	/* Input file stream to save data of opened file */
	ifstream file_stream;
	/* Position of the found word in line */
	size_t pos = 0;
	/* Variable to save line of file */
	string line;

	/* Open file to get data in file */
	file_stream.open(file);
	/* Check if file is openned succeed */
	if(file_stream.is_open())
	{
		/* Get line from the file */
		while(getline(file_stream, line))
		{
			if(this->total_match != true)
			{
				pos = line.find(word);
				/* Check if the position is not negative value, that mean the word is found in line */
				if(pos != string::npos)
				{
					// cout << "Found " << word << " in " << file << endl;
					return true;
				}
			}	
			else
			{
				/* Convert string to stream to use getline function */
				stringstream check_line(line);
				/* Token string inside string */
				string token;

				/* Use space seperator to get token inside string stream */
				while(getline(check_line, token, ' '))
				{
					/* Compare complete word with token */
					if(word == token)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

/* Function to find a word list existed in single file or not */
bool find_function::find_word(string &file, vector<string> word_list)
{
	/* Variable to check found state */
	unsigned int found_flag = 0;

	/* Search each word in word list in file */
	for (auto word: word_list)
	{
		// cout << word << endl;
		if(find_word(file, word))
		{
			/* Increase the found flag to mark the word is found */
			found_flag++;
		}
	}

	/* If number of found flag equal number of member in word list means word list is found */
	if(found_flag  != word_list.size())
	{
		return false;
	}
	// cout << file << endl;
	return true;
}

/* Find word list in all file list, will update for multithread finding */
void find_function::find_word(bool total_match)
{
	/* Set mode to find word is total match or not */
	this->total_match = total_match;
	
	/* Go through all file list */
	for (auto file: find_function::file_list)
	{
		/* Find word list in a file */
		if(find_word(file, word_list))
		{
			cout << file << endl;
		}
	}
}

/* Set search mode */
void find_function::set_mode(bool total_match)
{
	this->total_match = total_match;
}
