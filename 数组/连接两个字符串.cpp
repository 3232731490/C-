#include<iostream>
#include<string>

using namespace std;
int main()
{
/*	char str1[100], str2[100], str[100];
	cout << "please enter str1 :" << endl;
	cin >> str1;
	cout << " str2 :";
	cin>>str2;
	int a=strlen(str1);
	int b = strlen(str2);
	cout << "替换前str1的字符为：" << endl;
	for (int j = 0; j < a ; j++)
		cout << str1[j];
	cout << endl;
	for (int i = 0; i < a + b; i++)
	{
		if (i < a)
		{
			str[i] = str1[i];
		}
		else {
			str[i] = str[i - a];
		}
	}
	cout << "替换后str1的字符为：" << endl;
	for (int j = 0; j < a + b; j++)
		str1[j] = str[j];
	for (int j = 0; j < a + b; j++)
		cout << str1[j];
	*/

	/*
	char str1[100], str2[100];
	cout << "please enter str 1:" << endl;
	cin >> str1;
	cout << "please enter str2 :" << endl;
	cin >> str2;
	strcat_s(str1, str2);
	cout << endl;
	cout  << str1<< endl;
	*/


	string str1, str2;
	cout << "please enter str1:" << endl;
	cin >> str1 ;
	cout << "please enter str2;";
		cin >> str2;
	str1 = str1 + str2;
	cout << str1<<endl;
	system("pause");
	return 0;
}
