#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void nl(int (*arr)[3] )
{
	int m = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j =m+ 0; j < 3; j++)
		{
			int temp = *(*(arr+i)+j);
			*(*(arr+i)+j) = *(*(arr+j)+i);
			*(*(arr+j)+i) = temp;
		}
		m++;
	}
}
int main()
{
	int arr[3][3];
	cout << "请按行输入矩阵：" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin>>arr[i][j];
		}
	}
	cout << "转置前：" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<< arr[i][j];
		}
		cout << endl;
	}
	int(*p)[3] = arr;
	nl(p);
	cout << "转置后：" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
