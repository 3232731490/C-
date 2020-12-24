#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a[100][100] = {1 };
	int n;
	cout << "请输入你要打印杨辉三角的行数：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << a[i][j]<<"  ";
		}
		cout << endl;
	}

	return 0;
}

