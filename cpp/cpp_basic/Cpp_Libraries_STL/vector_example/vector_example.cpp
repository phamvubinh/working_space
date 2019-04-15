#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <exception>

using namespace std;

void print(const vector<int> & v);

int main(int argc, char const *argv[])
{
	const int SIZE = 10;

	vector<int> numbers(SIZE); // declare vector of int of SIZE elements, init to 0
	cout << "size = " << numbers.size() << endl;
	cout << "capacity = " << numbers.capacity() << endl;
	print(numbers);

	// Assign random numbers into vector
	srand(time(0)); // Seed the psedo-random number generator
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		numbers.at(i) = rand()%100;
	}
	print(numbers);

	cout << "First element is : " << numbers.front() << endl;
	cout << "Last element is : " << numbers.back() << endl;

	cout << numbers[55] << endl; // No error compile and run
	try
	{
		cout << numbers.at(55) << endl; // runtime out of range exception
	}
	catch(exception & e)
	{
		cout << "Standard exception: " << e.what() << endl;
	}

	return 0;
}


// print the content of vector using index
void print(const vector<int> & v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " "; // No bound check but safe here
	}
	cout << endl;
}