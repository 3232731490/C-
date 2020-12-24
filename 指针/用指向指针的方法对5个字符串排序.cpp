#include <iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
	char* a[5], b[5][99];
		for (int i = 0; i < 5; i++)
			a[i] = b[i];
		cout << "请输入5个字符串：" << endl;
		for (int i = 0; i < 5; i++)
			cin >> a[i];
		char** p,*temp;
		p = a;
		for (int i = 0; i < 4; i++)
		{
			for(int k=i+1;k<5;k++)
			for (int j = 0; j < 99; j++)
			{
				if ((**(p + i) + j) > (**(p + k) + j))
				{
					temp = *(p + i);
					*(p + i) = *(p + k);
					*(p + k) = temp;
					break;
				}
			}
		}
		cout << "排序后的字符串为：" << endl;
		for (int i = 0; i < 5; i++)
			cout << *(p + i)<<endl;
	system("pause");
	return 0;
}
