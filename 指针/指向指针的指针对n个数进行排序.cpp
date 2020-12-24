#include <iostream>
#include<string>
using namespace std;
int main()
{
	void sort(int** pp, int n);
	int  arr[100];
	cout << "您要输入多少个整数：" << endl;
	int n;
	cin >> n;
	cout << "请输入" << n << "个整数：" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int **pp;
	int* p = arr;
	pp = &p;
	cout << "排序前的顺序为：" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";
	cout << endl;
	sort(pp,n);
	cout << "排序后的顺序为：" << endl;
	for (int i = 0; i < n; i++)
		cout << *(*pp+i) << "  ";
	system("pause");
	return 0;
}
void sort(int** pp, int n)
{
	int temp;
	for(int i=0;i<n-1;i++)
		for (int j = i + 1; j < n; j++)
		{
			if ((*(*pp + i)) > (*(*pp + j)))
			{
				temp = *(*pp + i);
				*(*pp + i) = *(*pp + j);
				*(*pp + j) = temp;
			}
		}
}