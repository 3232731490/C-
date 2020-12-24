#include<iostream>
using namespace std;
long nl(int n)
{
	long sum=0;
	if (n == 1)
		sum = 1;
	else {
		sum = n * n + nl(n-1);
	}
	return sum;
}

int main()
{
	cout << "请输入您想加到几的平方和：" << endl;
	int n;
	cin >> n;
	if (n >= 1)
		cout << "最终平方和为" << nl(n) << endl;
	else cout << "please enter again" << endl;
		return 0;
}