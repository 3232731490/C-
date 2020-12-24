#include<iostream>
#include<string>
using namespace std;
int main()
{
	//数组指针....
	/*
	char c[][4] = { "哥","哥","我","岸","上","走" };
	char(*p)[4];
	int i; p = c;
	for (i = 0; i <= 5; i++)
		cout << *(p + i);
	cout << endl;
	for (i = 5; i >= 0; i--)
		cout << *(p + i);
	cout << endl;
	*/


	//指针数组
	int i;
	const char* pch[6] = { "妹","妹","你","坐","船","头" };
	for (i = 0; i < 6; i++)
	{
		cout << pch[i];
	}
	cout << endl;
	for (i = 5; i >= 0; i--)
	{
		cout << pch[i];
	}
	cout << endl;
		system("pause");
		return 0;
	
}

