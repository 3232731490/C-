#include<iostream>
#include<iomanip>
using namespace std;

int  prime(int a)
{
	int i,m,prime=1;
	for (i = 2; i <a; i++)
	{
		m = a % i;
		if (m == 0)
		{
			prime = 0;
			break;
		}
	}
	return prime;
}
int gotbaha(int a)
{
	int i,m;
	for (i = 3; i < a; i++)
	{
		if (prime(i))
		{
			m = a - i;
			if (prime(m))
			{
				cout << a << "=" << m << "+" << i << endl; break;
			}
		}
	}
	return 0;
}
int main()
{
	cout << "������һ������6��ż����" << endl;
	int a;
	cin >> a;
	if (a < 6 || a % 2 != 0)
		cout << "����������������������......" << endl;
	else gotbaha(a);
	return 0;
}