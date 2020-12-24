#include<iostream>
#include<string>
using namespace std;
int main()
{
	void nl(int arr[], int, int, int arr1[]);
	cout << "请输入数组元素个数：" << endl;
	int n,arr[30],arr1[31];
	cin >> n;
	cout << "请输入数组各个元素:" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "插入数字前由小到大排序：" << endl;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1+i; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << arr[i];
	cout << '\n';
	cout << "请输入您要插入的数字：" << endl;
	int m;
	cin >> m;
	nl(arr, n, m, arr1);
	return 0;
}
void nl(int arr[],int n,int m, int arr1[])
{
	int a=0;
	for (int k = 1; k < n; k++)
	{
		if (m < arr[0])
			a = 0;
		else if (m > arr[n - 1])
			a = n;
		else if (m <= arr[k] && m >= arr[k - 1])
		{
			a = k;
			break;
		}
	}
	for (int i = 0; i < a; i++)
	{
		arr1[i] = arr[i];
	}
	arr1[a] = m;
	for (int i = a ; i < n; i++)
	{
		arr1[i+1] = arr[i];
	}
	cout << "插入数字后新排序为：" << endl;
	for (int i = 0; i <= n; i++)
		cout << arr1[i] << ",";
}
