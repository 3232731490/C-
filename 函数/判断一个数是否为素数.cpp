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
	cout << "请输入您要判断的数：" << endl;
	int a;
	cin >> a;
	if (nl(a))
	{
		cout << "这是一个素数";
	}
	else cout << "这不是素数。" << endl;
	return 0;
}