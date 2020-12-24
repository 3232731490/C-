#include<iostream>
#include<string>
#include<iomanip>
#define N 100
using namespace std;
void len(char* str , int* len)
{
	int i = 0;
	int s=0;
	while (str[i] != '\0')
	{
		i++;
		s++;
	}
	*len = s;
}
int main()
{
	char str[N] ;
	cout << "please enter string:" << endl;
	cin >> str;
	char* p = str;
	int n;
	len(str, &n);
	cout << "请输入你要从第几个字符开始复制：" << endl;
	int m;
	cin >> m;
	if (m > n)
	{
		while (m > n)
		{
			cout << "您输入的数字大于字符串总长度，请重新输入："
			cin >> m;
		}
	}
	cout << "初始字符串为：" << endl;
	for (i = 0; i < n; i++)
		cout << str[i];
	char scpy[];
	strcpy(str, n, m, scpy);
	cout << "复制后的字符串为：" << endl;
	for (int i = 0; i < n - m; i++)
		cout << scpy[i];
	system("pause");
	return 0;
}
void strcpy_s(char* s, int n, int m, char * scpy)
{
	for(int i=m-1;m<n;i++)
	*(scpy+i-m+1)=*(s+m)
}