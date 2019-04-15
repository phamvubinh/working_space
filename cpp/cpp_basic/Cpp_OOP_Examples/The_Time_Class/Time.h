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

	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);

	void setTime(int h, int m, int s);
	void print() const;
	void nextSecond();
};

#endif