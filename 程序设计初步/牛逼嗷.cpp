#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	cout << "请输入一个不多于5位的正整数:" << endl;
	cin >> a;
	if (a / 10000 != 0)
	{
		cout << "这是一个五位数。" << endl;
		b = a / 10000;//最高位
		c = a / 1000 % 10;//倒数第二位
		d = a / 100 % 10;//倒数第三位
		e = a / 10 % 10;//倒数第四位
		f = a % 10;//最后一位
		cout << "这个五位数从高到低的数字分别为：" << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f<<endl;
		cout << "逆序打印为：" << f << e << d << c << b << endl;
	}
	else if (a / 1000 != 0)
	{
		cout << "这是一个四位数。" << endl;
		c = a / 1000 % 10;//倒数第二位
		d = a / 100 % 10;//倒数第三位
		e = a / 10 % 10;//倒数第四位
		f = a % 10;//最后一位
		cout << "这个四位数从高到低的数字分别为："  << c << ' ' << d << ' ' << e << ' ' << f << endl;
		cout << "逆序打印为：" << f << e << d << c << endl;
	}
	else if (a / 100 != 0)
	{
		cout << "这是一个三位数。" << endl;
		d = a / 100 % 10;//倒数第三位
		e = a / 10 % 10;//倒数第四位
		f = a % 10;//最后一位
		cout << "这个三位数从高到低的数字分别为："  << d << ' ' << e << ' ' << f << endl;
		cout << "逆序打印为：" << f << e << d << endl;
	}
	else if (a / 10 != 0)
	{
		cout << "这是一个两位数。" << endl;
		e = a / 10 % 10;//倒数第四位
		f = a % 10;//最后一位
		cout << "这个两位数从高到低的数字分别为："  << e << ' ' << f << endl;
		cout << "逆序打印为：" << f << e << endl;
	}
	else
	{
		cout << "这是一个一位数。" << endl;
		cout << "这个数字打印为：" << a << endl;;
		cout << "逆序排布为：" << a << endl;
	}
	return 0;
}
