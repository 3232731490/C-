#include <iostream>
#include<iomanip>
using namespace std;
double nl(double, double);
int main()
{
	cout << "��������Ҫ�󼸽����õ¶���ʽ��ֵ��" << endl;
	int a, n;
	cin >> n;
	cout << "������x��ֵ��" << endl;
	cin >> a;
	cout << a << "��" << n << "�����õ¶���ʽ��ֵΪ��" << nl(a, n) << endl;

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