#include <iostream>


class Implementor
{
public:
	virtual ~Implementor() {}
	virtual void action() = 0;

	//...
};


class ConcreteImplementorA: public Implementor
{
public:
	~ConcreteImplementorA(){}

	void action()
	{
		std::cout << "Concrete Implementor A" << std::endl;
	}
};

class ConcreteImplementorB: public Implementor
{
public:
	~ConcreteImplementorB(){}

	void action()
	{
		std::cout << "Concrete Implementor B" << std::endl;
	}
};

class Abstraction
{
public:
	virtual ~Abstraction() {}
	
	virtual void operation() = 0;
};

class RefinedAbstraction: public Abstraction
{
public:
	~RefinedAbstraction(){}
	RefinedAbstraction(Implementor *impl):implementor(impl) {}

	void operation()
	{
		implementor->action();
	}

private:
	Implementor *implementor;
};

int main()
{
	ConcreteImplementorA *conA = new ConcreteImplementorA();
	ConcreteImplementorB *conB = new ConcreteImplementorB();

	RefinedAbstraction * ref1 = new	RefinedAbstraction(conA);
	RefinedAbstraction * ref2 = new	RefinedAbstraction(conB);

	ref1->operation();
	ref2->operation();
	return 0;
}


