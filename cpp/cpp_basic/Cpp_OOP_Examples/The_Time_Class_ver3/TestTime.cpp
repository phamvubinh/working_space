#include "iostream"
#include "Time.h"
#include <stdexcept>
using namespace std;

int main(int argc, char const *argv[])
{
	try
	{
		Time t1(24, 60, 61);
		t1.print();
	}
	catch (invalid_hour & ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
	catch (invalid_minute & ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
	catch (invalid_second & ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
	catch (exception & ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
	cout << "Next statement after try-catch" << endl;
	return 0;
}