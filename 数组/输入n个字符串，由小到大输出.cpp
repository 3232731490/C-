#include<iostream>
#include<string>

using namespace std;
int main()
{
	string str[100];
	cout << "请输入有几个字符串：" << endl;
	int n;
	cin >> n;
	cout << "请输入" << n << "个字符串" << endl;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (str[i] > str[j])
			{
				string temp;
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	cout << "字符串由小到大排序为：" << endl;
	for (int i = 0; i < n; i++)
		cout << str[i] << endl;

	system("pause");
	return 0;
}
