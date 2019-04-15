#include <iostream>
#include "Stack.h"

int main(int argc, char const *argv[])
{
	Stack<int> stack1(2, 3);
	stack1.push(22);
	stack1.push(13);
	stack1.push(33);
	stack1.push(45);

	cout << stack1 << endl;

	int value;
	stack1.pop(value);
	stack1.pop(value);

	cout << stack1 << endl;

	return 0;
}