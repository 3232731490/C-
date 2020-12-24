#include<iostream>
using namespace std;
void selectsort(int a[], int len)
{
	int j = 0;
	int temp = 0;
	for (int i = 0; i < len-1; i++)
	{
		 j = i + 1;
		 temp = a[j];
		 for (; j > 0 && temp < a[j - 1]; j--)
		 {
			 a[j] = a[j - 1];
			 a[j - 1] = temp;
		 }
	}
}

int main()
{
	int n;
	cout << "请输入您要排序的数组长度" << endl;
	cin >> n;
	int* arr = new int [n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "排序前:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	selectsort(arr, n);
	cout << "排序后:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
	delete[] arr;
	return 0;
}