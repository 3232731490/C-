#include <iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
 char *month[12] = { "January","February","March" ,"April" ,"May" ,"June", "July", "August" ,"September" ,"October" ,"November" ,"December" };
	cout << "请输入月份" << endl;
	int i;
	char* p = month[0];
	cin >> i;
	switch (i)
	{
	case 1:p=month[0]; break;
	case 2:p = month[1]; break;
	case 3:p = month[2]; break;
	case 4:p = month[3]; break;
	case 5:p = month[4]; break;
	case 6:p = month[5]; break;
	case 7:p = month[6]; break;
	case 8:p = month[7]; break;
	case 9:p = month[8]; break;
	case 10:p = month[9]; break;
	case 11:p = month[10]; break;
	case 12:p = month[11]; break;
	}
	cout << i << "月的英文为：" << endl;
	int j = 0;
	while(*(p+j)!='\0')
	cout << *(p+j++) ;
	system("pause");
	return 0;
}
