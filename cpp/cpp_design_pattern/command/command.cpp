#include <iostream>


class Receiver
{
public:
	void action()
	{
		std::cout << "Receiver: excecute action" << std::endl;
	}
	
};

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;

protected:
	Command(){}
	
};

class ConcreteCommand : public Command
{
public:
	ConcreteCommand(Receiver *r) : receiver(r) {}

	~ConcreteCommand()
	{
		if(receiver)
		{
			delete receiver;
		}
	}

	void execute()
	{
		receiver->action();
	}

private:
	Receiver *receiver;
};


class Invoker
{
public:
	void set(Command *c)
	{
		command = c;
	}

	void confirm()
	{
		if(command)
		{
			command->execute();
		}
	}
private:
	Command * command;
};

int main()
{
	ConcreteCommand command(new Receiver());

	Invoker ink;
	ink.set(&command);
	ink.confirm();
	return 0;
}
