#include <iostream>

class SubsystemA
{
public:
	void suboperation()
	{
		std::cout << "Subsystem A method " << std::endl;
	}
};

class SubsystemB
{
public:
	void suboperation()
	{
		std::cout << "Subsystem B method " << std::endl;
	}
};

class SubsystemC
{
public:
	void suboperation()
	{
		std::cout << "Subsystem C method " << std::endl;
	}
};

class Facade
{
public:
	Facade()
	{
		subSystemA = new SubsystemA();
		subSystemB = new SubsystemB();
		subSystemC = new SubsystemC();
	}

	void operation1()
	{
		subSystemA->suboperation();
		subSystemC->suboperation();
	}

	void operation2()
	{
		subSystemB->suboperation();
		subSystemC->suboperation();
	}

private:
	SubsystemA *subSystemA;
	SubsystemB *subSystemB;
	SubsystemC *subSystemC;
};

int main(int argc, char const *argv[])
{
	Facade * facade = new Facade();

	facade->operation1();
	facade->operation2();
	return 0;
}