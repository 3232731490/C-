#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
#define N 100
void nl(char* str, int n,int* a, int* b, int* c, int* d, int* e)
{
	for (int i = 0; i < n; i++)
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*a+=1;
		else if (*(str + i) >='a' && *(str + i) <= 'z')
			*b+=1;
		else if (*(str + i) >= '0' && *(str + i) <= '9')
			*d+=1;
		else if (*(str + i) == ' ')
			*c+=1;
		else
			*e+=1;
	}
}
int main()
{
	char str[N];
	cout << "please enter a string:" << endl;
	gets_s( str);
	int n = strlen(str);
	int a=0, b=0, c=0, d=0,e=0;//a-大写字母数，b-小写字母数，c-空格数，d-数字，e-其他
	nl(str, n, &a, &b, &c, &d, &e);
	cout << "大写字母数:" << a << endl;
	cout << "小写字母数:" << b << endl;
	cout << "空格数:" << c<< endl;
	cout << "数字数:" << d<< endl;
	cout << "其他字符数:" << e << endl;
	system("pause");
	return 0;
}
