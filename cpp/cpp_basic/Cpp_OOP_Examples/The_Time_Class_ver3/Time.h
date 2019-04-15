#ifndef __TIME_H__
#define __TIME_H__

using namespace std;

class invalid_hour : public exception
{
public:
	const char * what () const throw ()
	{
		return "Invalid hour! Hour shall be 0-23.";
	}
};

class invalid_minute : public exception
{
public:
	const char * what () const throw ()
	{
		return "Invalid minute! Minute shall be 0-59.";
	}
};

class invalid_second : public exception
{
public:
	const char * what () const throw ()
	{
		return "Invalid second! Second shall be 0-59.";
	}
};

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int hour = 0, int minute = 0, int second = 0);
	int getHour() const;
	int getMinute() const;
	int getSecond() const;

	Time & setHour(int h);
	Time & setMinute(int m);
	Time & setSecond(int s);

	void setTime(int h, int m, int s);
	void print() const;

	Time & nextSecond();
};

#endif