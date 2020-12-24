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
int main()
{
	date d;
	int n,sum=0;
	cout << "请输入年月日：" << endl;
	cin >> d.year>>n>>d.day;
	if (d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0)
	{
		d.month[1] = 29;
	}
	if (n == 1)
		sum = d.day;
	else {
		for (int i = 0; i < n-1; i++)
		{
			sum = sum + d.month[i];
		}
		sum += d.day;
	}
	cout << d.year << "/" << n << "/" << d.day << "在" << d.year << "中是第" << sum << "天" << endl;
	system("pause");
	return 0;
}
