
#include <iostream>
#include <vector>

// forward decleration of class Subject
class Subject;

// virtual function need to be virtual xxx() = 0; to avoid linking error
class Observer
{
public:
	virtual ~Observer(){};

	virtual getState() = 0;
	virtual void update(Subject *subject) = 0;
};

class ConcreteObserver : public Observer
{
public:
	ConcreteObserver(const int state) : observer_state(state){};
	~ConcreteObserver(){}

	int getState()
	{
		return observer_state;
	}

	void update(Subject *subject);

private:
	int observer_state;
};

class Subject
{
public:
	virtual ~Subject(){}
	void attach(Observer * observer)
	{
		observers.push_back(observer);
	}

	void detach(const int index)
	{
		observers.erase(observers.begin() + index);
	}

	void notify()
	{
		// Update this subject state to all observer in list
		for (unsigned int i = 0; i < observers.size(); i++)
		{
			observers.at(i)->update(this);
		}
	}

	virtual int getState() = 0;
	virtual void setState( const int s ) = 0;
private:
	std::vector<Observer*> observers;
};

class ConcreteSubject : public Subject
{
public:
	~ConcreteSubject(){}
	int getState()
	{
		return subject_state;
	}

	void setState(const int state)
	{
		subject_state = state;
	}
private:
	int subject_state;
};

void ConcreteObserver::update(Subject *subject)
{
	observer_state = subject->getState();
	std::cout << "Observer state is updated" << std::endl;
}

int main()
{
	ConcreteObserver * cOS1 = new ConcreteObserver(3);
	ConcreteObserver * cOS2 = new ConcreteObserver(4);

	std::cout << "Check state server 1: " << cOS1->getState() << std::endl;
	std::cout << "Check state server 2: " << cOS2->getState() << std::endl;

	ConcreteSubject *subject = new ConcreteSubject();
	subject->attach(cOS1);
	subject->attach(cOS2);

	subject->setState(12);
	subject->notify();

	std::cout << "Check state server 1: " << cOS1->getState() << std::endl;
	std::cout << "Check state server 2: " << cOS2->getState() << std::endl;

	return 0;
}

