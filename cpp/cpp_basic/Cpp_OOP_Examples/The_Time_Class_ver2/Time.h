#ifndef __TIME_H__
#define __TIME_H__

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