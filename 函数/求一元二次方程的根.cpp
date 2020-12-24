#include<iostream>
#include<cmath>
using namespace std;
double f1(int, int, int);
double f2(int, int, int);
double f3(int, int, int);
double f4(int, int, int);
int main()
{
	cout << "请输入一元二次方程的三个系数：" << endl;
	int a, b, c;
	double n;
	cin >> a >> b >> c;
	n = sqrt(b * b - 4 * a * c);
	if (n > 0)
		cout << "根为：" << f1(a, b, c) <<","<<f4(a,b,c)<< endl;
	else if (n == 0)
		cout << "根为：" << f2(a, b, c) << endl;
	else f3(a, b, c);
	return 0;
}
double f1(int a, int b, int c)
{
	double m, n,p;
	n = sqrt(b * b - 4 * a * c);
	m = (-b + n) / (2*a);
	return(m);
}
double f4(int a, int b, int c)
{
	double m, n, p=1;
	n = sqrt(b * b - 4 * a * c);
	p = (-b - n) / (2 * a);
	return(p);
}
double f2(int a, int b, int c)
{
	double m, n;
	n = sqrt(b * b - 4 * a * c);
	m = -b / (2 * a);
	return m;
}
double f3(int a, int b, int c)
{
	cout << "此时方程没有实根......" << endl;
	return 0;
}