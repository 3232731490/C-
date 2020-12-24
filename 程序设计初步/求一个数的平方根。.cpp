#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double x1=1, x2=1,a,b,c;
	cout << "请输入您要求平方根的数" << endl;
	cin >> a;
	for (; 1;)
	{
		b = a / x1;
		x2 = (x1 + b) / 2;
		c = x1;
		x1 = x2;
		if (fabs(x2 - c) < 1e-5)
		{		cout << "所求平方根的值为：" << x1 << endl; break;
	     }
	}

	return 0;
}