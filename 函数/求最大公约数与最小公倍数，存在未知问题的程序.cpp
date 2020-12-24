#include<iostream>
#include<iomanip>
using namespace std;
int gla(int, int);
int glc(int, int);
int main()
{
	cout << "please enter two number" << endl;
	int a, b;
	cin >> a >> b;
	cout << "最大公约数为：" << gla(a, b) << endl;
	cout << "最小公倍数为：" << glc(a, b) << endl;
	return 0;
}
int gla(int a, int b)
{
	int m, n = 1;
	if (a < b)
	{
		m = b;
		a = b;
		b = m;
	}
	while (n != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}
int glc(int a, int b)
{
	int l;
	l = gla(a, b);
	return a * b / l;
}