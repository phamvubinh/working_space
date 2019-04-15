#include <iostream>

using namespace std;

class Component
{
public:
	virtual ~Component(){}
	virtual void operation() = 0;

	//...
};

class ConcreteComponent : public Component
{
	~ConcreteComponent() {}
	void operation()
	{
		cout << "Concrete Component operation" << endl;
	}
};

class Decorator : public Component
{
public: 
	~Decorator() {}
	Decorator(Component *c) : component(c) {}

	virtual void operation()
	{
		component->operation();
	}
private:
	Component *component;
};

class ConcreteDecoratorA : public Decorator
{
public: 
	ConcreteDecoratorA(Component *c) : Decorator(c) {}

	void operation()
	{
		Decorator::operation();
		cout << "Decorator A " << endl;
	}
};

class ConcreteDecoratorB: public Decorator
{
public: 

	ConcreteDecoratorB(Component *c) : Decorator(c) {}

	void operation()
	{
		Decorator::operation();
		cout << "Decorator B " << endl;
	}
};

int main(int argc, char const *argv[])
{
	ConcreteComponent *cC = new ConcreteComponent();
	ConcreteDecoratorA *cA = new ConcreteDecoratorA(cC);
	ConcreteDecoratorB *cB = new ConcreteDecoratorB(cA);

	Component *component = cB;

	component->operation();

	return 0;
}