#include <iostream>
#include <map>

class Flyweight
{
public:
	virtual ~Flyweight() {}
	virtual void operation() = 0;
};

class UnsharedConcreteFlyweight : public Flyweight
{
public:
	UnsharedConcreteFlyweight(const int intrinsic_state) :
		state(intrinsic_state) {}
	~UnsharedConcreteFlyweight(){}

	void operation()
	{
		std::cout << "Unshared Flyweight with state" << state << std::endl;
	}
private:
	int state;
};

class ConcreteFlyweight : public Flyweight
{
public:
	ConcreteFlyweight(const int all_state):
		state(all_state) {}
	~ConcreteFlyweight() {}

	void operation()
	{
		std::cout << "Concete flyweight with state " << state << std::endl;
	}

private:
	int state;
};

class FlyweightFactory
{
public:
	~FlyweightFactory()
	{
		for (auto it = flies.begin(); it != flies.end(); it++)
		{
			delete it->second;
		}

		flies.clear();
	}

	Flyweight * getFlyweight(const int key)
	{
		if(flies.find(key) != flies.end())
		{
			std::cout << "Cheking key int map: " << key << std::endl;
			return flies[key];
		}

		std::cout << "Cheking key create: " << key << std::endl;
		Flyweight *fly = new ConcreteFlyweight(key);
		flies.insert(std::pair<int, Flyweight *> (key, fly));
		return fly;
	}

private:
	std::map<int, Flyweight*> flies;
};

int main(int argc, char const *argv[])
{
	FlyweightFactory *factory = new FlyweightFactory();
	factory->getFlyweight(2)->operation();
	factory->getFlyweight(3)->operation();

	factory->getFlyweight(2)->operation();
	return 0;
}