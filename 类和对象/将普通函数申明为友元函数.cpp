#include <iostream>
using namespace std;
class Date;
class Time
{
	friend void display(Date& d, Time& t);

public:
	Time(int, int, int);
private:
	int hour;
	int minute;
	int sec;
};
class Date
{
	friend void display(Date& d, Time& t);

public:
	Date(int, int, int);
	
private:
	int month;
	int day;
	int year;
};
Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	sec = s;
}
Date::Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}
void display(Date& d, Time& t)
{
	cout << d.month << "/" << d.day << "/" << d.year << endl;
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}
int main()
{
	Date d(12,25,2004);
	Time t(10,13,56);
	display(d, t);
	system("pause");
	return 0;
}

