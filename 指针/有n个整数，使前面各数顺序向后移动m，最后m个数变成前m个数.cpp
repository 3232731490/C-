#include<iostream>
#include<string>
using namespace std;
void input(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "please enter " << i + 1 << "th  intenger" << endl;
		cin >> arr[i];
	}
}
void swap(int* arr, int n, int m)
{
	int t[50];
	for (int i = 0; i < n; i++)
		t[i] = arr[i];
	for (int i = 0; i<n-m; i++)
	{
		arr[i + m] = t[i];
	}
	for (int i = 0; i < m; i++)
		arr[i] = t[n-m+i];
}
void output(int* arr,int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
int main()
{
	int arr[50], n, m;
	cout << "请输入您要输入几个整数：" << endl;
	cin >> n;
	cout << "请输入您要往后移动几位：" << endl;
	cin >> m;
	input(arr, n);
	swap(arr, n, m);
	output(arr, n);
		system("pause");
		return 0;
	
}

