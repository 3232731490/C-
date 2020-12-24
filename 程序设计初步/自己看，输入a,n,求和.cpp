#include<iostream>
using namespace std;
int main()
{
	cout << "请输入a和n的值：" << endl;
	int a, n,i,sum=0,c;
	cin >> a >> n;
	c = a;
	for (i = 1; i <= n; i++)
	{
		sum = a + sum;
		a = 10 * a + c;
	}
	cout << "Sn=" << ' ' << sum << endl;
	return 0;
}