#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string msg1("Hello");
	string msg2("hello");
	string msg3("HELLO");

	// Relational operators (conparing the contents)
	cout << boolalpha;
	cout << (msg1 == msg2) << endl;
	cout << (msg1 <= msg2) << endl;
	cout << (msg1 >= msg2) << endl;

	// Assignment
	string msg4 = msg1;
	cout << msg4 << endl;

	// Concatenation
	cout << (msg1 + " " + msg2) << endl;
	msg3 += msg2;
	cout << msg3 << endl;    // hello HELLO

	// Indexing
	cout << msg1[1] << endl;
	cout << msg1[1000] << endl;  // garbadge value
	// cout << msg1.at(99) << endl; // out of range exception

	return 0;
}