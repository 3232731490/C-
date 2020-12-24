#include <iostream>
#include<string>
using namespace std;
void sort( char * p[])
{
	char* temp;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9-i; j++)
		{
			if (strcmp(*(p + j), *(p +1+ j)) > 0)
			{
				temp = *(p + j);
				*(p + j) = *(p + 1 + j);
				*(p + 1 + j) = temp;
			}
		}
	}
}
int main()
{
	char* p[10];
	for (int i = 0; i < 10; i++)
		p[i] = (char*)malloc(sizeof(char) * 30);
	cout << "输入10个字符串：" << endl;
	for (int i = 0; i < 10; i++)
		cin >> p[i];
	for (int i = 0; i < 10; i++)
		cout << p[i] << endl;
	sort(p);
	cout << endl;
	for (int i = 0; i < 10; i++)
		cout << p[i]<<endl;
	system("pause");
	return 0;
}