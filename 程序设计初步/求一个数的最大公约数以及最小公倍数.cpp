#include<iostream>
using namespace std;
	int glc(int x, int y)
	{
		int m,n;
		if (y > x)
		{
			m = y;
			y = x;
			x = m;
		}
		while (m != 0)
		{
			m = x % y;
			x = y;
			y = m;
		}
		return x;
	}
	int gla(int x, int y)
	{
		int m, n,a;
		a = x * y;
		if (y > x)
		{
			m = y;
			y = x;
			x = m;
		}
		while (m != 0)
		{
			m = x % y;
			x = y;
			y = m;
		}
		int b;
		b = a / m;
		return b;
	}
	int main()
	{
	cout << "������������������" << endl;
	int c, d,r,t;
	cin >> c >> d;
	r = glc(c, d);
	t = gla(c, d);
	cout << c << "��" << d << "����С��Լ��Ϊ��" << r << "��С������Ϊ��" << t << endl;
	return 0;
}