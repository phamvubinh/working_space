#include <iostream>
#include <iomanip>
#include "Time.h"
#include <stdexcept>

using namespace std;

Time::Time(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
}

int Time::getHour() const
{
	return hour;
}

int Time::getMinute() const
{
	return minute;
}

int Time::getSecond() const
{
	return second;
}

Time & Time::setHour(int h)
{
	if(h >= 0 && h <= 23)
	{
		hour = h;
	}
	else
	{
		throw invalid_hour();
	}
	return * this;
}

Time & Time::setMinute(int m)
{
	if(m >= 0 && m <= 59)
	{
		minute = m;
	}
	else
	{
		throw invalid_minute();
	}
	return * this;
}

Time & Time::setSecond(int s)
{
	if (s >= 0 && s <= 59)
	{
		second = s;
	}
	else
	{
		throw invalid_second();
		// need <stdexcept>
	}
	return * this;
}

void Time::setTime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

void Time::print() const
{
	cout << setfill('0');   // zero filled need <iomanip>
	cout << setw(2) << hour
					<< ':' << setw(2) << minute
					<< ':' << setw(2) << second << endl;
}

// increase current time by one second
Time & Time::nextSecond()
{
	++ second;
	if (second >= 60)
	{
		second = 0;
		++minute;
	}
	if (minute >= 60)
	{
		minute = 0;
		++hour;
	}
	if (hour >= 24)
	{
		hour = 0;
	}

	return *this;
}