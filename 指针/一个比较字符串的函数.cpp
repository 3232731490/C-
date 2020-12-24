#include <iostream>
#include<string>
#include<stdio.h>
using namespace std;
int strcpy1(char* p1, char* p2);
int main()
{
	char s1[50], s2[50];
	gets_s(s1);
	gets_s(s2);
	char* p1 = &s1[0], * p2 = &s2[0];
	int n=0;
	n=strcpy1(p1, p2);
	cout << n << endl;
	system("pause");
	return 0;
}
int strcpy1(char * p1,char * p2)
{
	int i = 0,n=0;

//我自己的方法
	/*while (*(p1 + i) != '\0' || *(p2 + i) != '\0')
	{
		if (*(p1 + i) == *(p2 + i))i++;
		else {
			n = *(p1 + i) - *(p2 + i);
			break;
		}
	}*/

//网上的方法
	for (; *(p1 + i) != '\0' || *(p2 + i) != '\0'; i++)
	{
		if (*(p1 + i) != *(p2 + i))
		{
			n = *(p1 + i) - *(p2 + i);
			break;
		}
	}
	if (*(p1 + i) == '\0' && *(p2 + i) == '\0')n = 0;
	return n;
}