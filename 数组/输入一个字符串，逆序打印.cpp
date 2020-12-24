#include<iostream>
#include<string>

using namespace std;
int main()
{
	
	//字符数组。。。。。
	/*char str[80];
	cout << "请输入您要输入几个字符：" << endl;
	int n;
	cin >> n;
	cout<<"请输入一个有"<<n<<"个字符的字符串："<<endl;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	cout << "逆序排列前为：" << endl;
	for (int i = 0; i < n; i++)
		cout << str[i];
	for (int i = 0, j = n - 1; i < j; i++,j--)
	{
		char temp = str[i];
		str[i] = str[j];
			str[j]=temp;
	}
	cout << "逆序排列后为：" << endl;
	for (int i = 0; i < n; i++)
		cout << str[i];*/

	//string
	char str[80];
	cout << "请输入一个字符串" << endl;
	cin >> str;
	int a = strlen(str);
	for (int i = a - 1; i >= 0; i--)
		cout << str[i];
	system("pause");
	return 0;
}
