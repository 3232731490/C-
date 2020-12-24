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
	cout << "请输入两个正整数：" << endl;
	int c, d,r,t;
	cin >> c >> d;
	r = glc(c, d);
	t = gla(c, d);
	cout << c << "与" << d << "的最小公约数为：" << r << "最小公倍数为：" << t << endl;
	return 0;
}