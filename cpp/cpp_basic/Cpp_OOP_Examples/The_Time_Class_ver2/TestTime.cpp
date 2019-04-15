#include "iostream"
#include "Time.h"
using namespace std;
int main(int argc, char const *argv[])
{
	Time t1(23, 59, 59);
	t1.print();

	t1.setHour(1);
	t1.setMinute(20);
	t1.setSecond(15);

	cout << "Hour is: "   << t1.getHour()   << endl;
	cout << "Minute is: " << t1.getMinute() << endl;
	cout << "Second is: " << t1.getSecond() << endl;

	Time t2;
	t2.print();
	t2.setTime(1, 2, 5);


	Time t3(t2);
	t3.print();

	Time t4(23, 59, 58);
	t4.nextSecond();
	t4.print();
	t4.nextSecond();
	t4.print();

	Time t5(25, 61, 61);
	t5.print();

	Time t6(23, 59, 58);
	t6.nextSecond().nextSecond().nextSecond().print();

	// use return * this method to implement this one
	t6.setHour(1).setMinute(3).setSecond(3).print();

	return 0;
}