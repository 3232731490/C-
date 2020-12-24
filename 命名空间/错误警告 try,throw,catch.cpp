#include <iostream>
#include <strstream>
#include<cmath>
using namespace std;
void fun1(double, double, double);
void fun(double a, double b, double c)
{
	try 
	{
		fun1(a, b, c);
	}
	catch (int)
	{
		cerr << b << "*" << b << "- 4*" << a << "*" << c << "< 0" << endl;
		cout << "error!" << endl;
		return;
	}
}
void fun1(double a, double b, double c)
{
	double x1, x2;
	if ((b * b - 4 * a * c) < 0)
		throw 0;
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	cout << "x1=  " << x1 << endl;
	cout << "x2=  " << x2 << endl;
}

int main()
{
	cout << "请输入一元二次方程的三个系数：  " << endl;
	int a, b, c;
	cin >> a >> b >> c;
	fun(a, b, c);
	return 0;
}
