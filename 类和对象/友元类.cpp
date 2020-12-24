#include <iostream>
using namespace std;
class Date;
class Time
{
public:
	Time(int, int, int);
	void display(Date &);
private:
	int hour;
	int minute;
	int sec;
};
class Date
{
	friend Time;
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
void Time::display(Date &d)
{
	cout << d.month << "/" << d.day << "/" << d.year<<endl;
	cout << hour <<":"<< minute <<":"<< sec << endl;
}
int main()
{
	Date d(12,25,2004);
	Time t(10,13,56);
	t.display(d);
	system("pause");
	return 0;
}

