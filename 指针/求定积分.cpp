#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
void fsinx(double m, double n, double i, double* sum)
{
	*sum = 0;
	double t = (m - n) / i;
	double l = n;
	for (double j = 0; j < i; j++)
	{
		*sum = *sum + t * sin(l);
		l = l + t ;
	}
}
void fcosx(double m, double n, double i, double* sum)
{
	*sum = 0;
	double t = (m - n) / i;
	double l = n + t;
	for (double j = 0; j < i; j++)
	{
		*sum = *sum + t * cos(l);
		l = l + t;
	}
}
void fe(double m, double n, double i, double* sum)
{
	*sum = 0;
	double t = (m - n) / i;
	double l = n + t;
	for (double j = 0; j < i; j++)
	{
		*sum = *sum + t * exp(l);
		l = l + t ;
	}
}
int main()
{
	double m, n;//m，n为积分上下限
	void(*p) (double m, double n, double i, double* sum);
	cout << "请输入上下限：" << endl;
	cin >> m >> n;
	cout << "请问您要算哪个函数的积分值：" << endl;
	cout << "1、Sinx,2、cosx，3、e^x" << endl;
	int i;
	cin >> i;
	p = fsinx;
	double  sum;
	switch (i)
	{
	case 1:p = fsinx; break;
	case 2:p = fcosx; break;
	case 3:p = fe; break;
	}
	p(m, n, 2000000, &sum);
	cout << "积分的值为：" << endl;
	cout << sum << endl;
	system("pause");
	return 0;
}