#include<iostream>
#include<string>
using namespace std;
int main()
{
	cout << "please enter three string:" << endl;
	string str[3];
	cin >> str;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i+1; j < 3; j++)
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
	for (i = 0; i < 3; i++)
	{
		cout << str[i] << endl;
	}
	return 0;
}
