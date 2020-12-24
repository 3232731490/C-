#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	char c;
	int n=0, m=0, k=0, l=0;//n为字母个数，m为空格个数，k为数字个数，l为其他字符个数。
	cout << "请输入一段字符：" << endl;
	while ((c = getchar()) != '\n')
	{
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
			n = n + 1;
		else if (c >= '0' && c <= '9')
			k = k + 1;
		else if (c == ' ')
			m = m + 1;
		else l++;
	}
	cout << "字母个数为：" << n <<endl<< "空格个数为：" << m <<endl<< "数字个数为：" << k <<endl<< "其他字符个数为：" << l << endl;
	return 0;
}