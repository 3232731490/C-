#include<iostream>
#include<string>
using namespace std;
int main()
{
	char str[3][80] = {'\0'};
	int a=0, b=0, c=0, d=0, e=0;//分别统计大写字母，小写字母，数字，空格，其他字符。
	cout << "请输入三行字符：" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "please enter string" << i + 1 << endl;
		gets_s(str[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				a++;
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
				b++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				c++;
			else if (str[i][j] == ' ')
				d++;
			else e++;
		}
	}
	cout << "大写字母个数："<<a<<"小写字母个数："<<b<<"数字个数："<<c<<"空格个数："<<d<<"其他字符个数："<<e<<endl;
	
	system("pause");
	return 0;
}
