#include<iostream>
#include<iomanip>
using namespace std;
int nl(int a)
{
	int i,n,prime=1;
	for (i = 2; i < a; i++)
	{
		n = a % i;
		if (n == 0)
		{
			prime = 0;
			break;
		}
	}
	return prime;
}
int main()
{
	cout << "��������Ҫ�жϵ�����" << endl;
	int a;
	cin >> a;
	if (nl(a))
	{
		cout << "����һ������";
	}
	else cout << "�ⲻ��������" << endl;
	return 0;
}