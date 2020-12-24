#include <iostream>
#include<iomanip>
using namespace std;
double nl(double, double);
int main()
{
	cout << "请输入你要求几阶勒让德多项式的值：" << endl;
	int a, n;
	cin >> n;
	cout << "请输入x的值：" << endl;
	cin >> a;
	cout << a << "的" << n << "阶勒让德多项式的值为：" << nl(a, n) << endl;

	return 0;
}
double nl(double a, double n)
{
	double m,p,c,l;
	m = a;
	for (; n >= 0; n--)
	{
		c = nl(a, n - 1);
			l = nl(a, n - 2);
			if (n == 1)
				p = a;
			else if (n == 0)
				p = 1;
			else 
				p = ((2 * n - 1) * a - c - (n - 1)*l) / n;
			return p;
	}

}