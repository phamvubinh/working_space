#include <iostream>

class Singleton
{
public:
	static Singleton* instance();
	void tell()
	{
		std::cout <<"This is Singleton function" << std::endl;
	}
	//...

	Singleton();
	~Singleton();
	Singleton(const Singleton& a);
	Singleton& operator=(const Singleton& a);
};

Singleton::Singleton() {}
Singleton::~Singleton() {}

Singleton* Singleton::instance()
{
	static Singleton single;
	return &single;
}

int main()
{
	Singleton sj;
	sj.tell();
	Singleton::instance()->tell();
	sj.tell();
}