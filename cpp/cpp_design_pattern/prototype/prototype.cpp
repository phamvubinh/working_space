#include <iostream>
using namespace std;

class Prototype
{
public:
	virtual ~Prototype() {}
	virtual Prototype* clone() = 0;
	virtual std::string type() = 0;
};

class ConcretePrototypeA : public Prototype
{
public:
	~ConcretePrototypeA() {}

	Prototype* clone()
	{
		return new ConcretePrototypeA();
	}
	string type()
	{
		return "type A";
	}
};

class ConcretePrototypeB : public Prototype
{
public:
	~ConcretePrototypeB() {}
	Prototype* clone()
	{
		return new ConcretePrototypeB();
	}

	string type()
	{
		return "type B";
	}
};

class Client
{
public:
	static void init()
	{
		type[0] = new ConcretePrototypeA();
		type[1] = new ConcretePrototypeB();
	}
	static void remove()
	{
		delete type[0];
		delete type[1];
	}
	static Prototype* make(const int index)
	{
		if(index >= n_types)
		{
			return nullptr;
		}
		return type[index]->clone();
	}
private:
	static Prototype* type[2];
	static int n_types;
};

Prototype* Client::type[2];
int Client::n_types = 2;

int main(int argc, char const *argv[])
{
	Client::init();
	Prototype *prototype1 = Client::make(0);
	cout << "Prototype: " << prototype1->type() << endl;
	delete prototype1;

	Prototype *prototype2 = Client::make(1);
	cout << "Prototype: " << prototype2->type() << endl;

	Client::remove();

	return 0;
}