#include<iostream>
#include<string>

using namespace std;
int main()
{
	string str[80];
	cout << "请输入你想输入几个字符串：" << endl;
	int n;
	cin >> n;
	cout << "请输入" << n << "个字符串" << endl;
	for (int i = 0; i < n; i++)
     cin>>str[i];
	for (int i = 0; i < n; i++)
	{
		if (str[i][0] == 'A')
		{
			cout << str[i] << endl;
		}
	}
	system("pause");
	return 0;
}
