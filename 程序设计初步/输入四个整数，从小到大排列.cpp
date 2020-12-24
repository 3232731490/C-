#include<iostream>
using namespace std;
int min(int x, int y)
{
	int a;
	a = (x > y) ? y : x;
	return a;
}
int main()
{
	cout << "请输入四个整数" << endl;
	int a, b, c, d,e;
	cin >> a >> b >> c >> d;
	if (a > b)
	{
		e = a;
		a = b;
		b = e;
	}
	if (a > c)
	{
		e = a;
		a = c;
		c = e;
	}
	if (b > c)
	{
		e = b;
		b = c;
		c = e;
	}
	if (a > d)
	{
		e = a;
		a = d;
		d = e;
	}
	if (b > d)
	{
		e = b;
		b = d;
		d = e;
	}
	if (c > d)
	{
		e = c;
		c = d;
		d = e;
	}
	cout << a <<' '<< b <<' '<< c <<' '<< d<<endl;
	return 0;
}