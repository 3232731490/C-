#include<iostream>
#include<iomanip>
using namespace std;
int nl( int n)
{
	static  int f = 1;
	f = f * n;
	return f;
}
int main()
{
	cout << "��������Ҫ�󵽼��Ľ׳ˣ�" << endl;
	int n,i;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << i << "!=" << nl(i) << endl;
	}
	return 0;
}
