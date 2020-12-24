#include <iostream>
#include<string>
using namespace std;
void sort(char str[10][30])
{
	char temp[30];
	for (int i = 0; i < 9; i++)
		for (int j = i + 1; j < 10;j++) 
		{
			if (strcmp(str[i], str[j]) < 0)
			{
				strcpy_s(temp, str[i]);
				strcpy_s(str[i],str[j]);
				strcpy_s(str[j], temp);
			}
		}
	for (int i = 0; i < 10; i++)
		cout << str[i] << endl;
}
int main()
{
	char str[10][30];
	char(*p)[30];
	p = str;
	for (int i = 0; i < 10; i++)
		cin >> str[i];
	sort(p);
	system("pause");
	return 0;
}