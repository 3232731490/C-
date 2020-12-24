#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
struct date
{
	int year;
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int day;
};
int days(date* p, int n)
{
	int sum=0;
	if (p->year % 4 == 0 && p->year % 100 != 0 || p->year % 400 == 0)
	{
		p->month[1] = 29;
	}
	if (n == 1)
		sum = p->day;
	else {
		for (int i = 0; i < n - 1; i++)
		{
			sum = sum + p->month[i];
		}
		sum += p->day;
	}
	return sum;
}
int main()
{
	date d;
	int n,sum=0;
	date* p = &d;
	cout << "请输入年月日：" << endl;
	cin >> d.year>>n>>d.day;
	sum=days(p,n);
	cout << d.year << "/" << n << "/" << d.day << "在" << d.year << "中是第" << sum << "天" << endl;
	system("pause");
	return 0;
}
