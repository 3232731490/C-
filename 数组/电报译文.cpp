#include<iostream>
#include<string>

using namespace std;
int main()
{
	int I=0;
	char nl[100];
	cout << "请输入电文：" << endl;
	cin.get( nl,100);
	for (int i = 0; i < I; i++)
		cout << nl[i] << ",";
	I = strlen(nl);
	for (int i = 0; i < I; i++)
	{
		if (nl[i] >= 'A' && nl[i] <= 'Z' )
		{
			nl[i] = (nl[i] - 'A' + 25) % 26 + 'A';
		}
		else if (nl[i]>= 'a' && nl[i]<= 'z')
		{
			nl[i] = (nl[i] - 'a' + 25) % 26 + 'a';
		}
	}
	for (int i = 0; i < I; i++)
		cout << nl[i];
	cout << endl;
	system("pause");
	return 0;
}
