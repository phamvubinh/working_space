#include <iostream>
#include "Book.h"
using namespace std;

int main(int argc, char const *argv[])
{
	// Declare and construct an instance of Author
	Author peter("Peter Jones", "peter@somewhere.com", 'm');
	peter.print();  // Peter Jones (m) at peter@somewhere.com

	// Declare and construct an instance of Book
	Book cppDummy("C++ for Dummies", peter, 19.99);
	cppDummy.setQtyInStock(88);
	cppDummy.print();
	// 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com

	cout << cppDummy.getQtyInStock() << endl;  // 88
	cout << cppDummy.getPrice() << endl;       // 19.99
	cout << cppDummy.getAuthor().getName() << endl;  // "Peter Jones"
	cout << cppDummy.getAuthor().getEmail() << endl; // "peter@somewhere.com"
	cout << cppDummy.getAuthorName() << endl;        // "Peter Jones"

	Book moreCpp("More C++ for Dummies", peter, -19.99);
	// price should be positive! Set to 0
	cout << moreCpp.getPrice() << endl;   // 0

	return 0;
}