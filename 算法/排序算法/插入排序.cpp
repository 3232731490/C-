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
	cout << "��������Ҫ��������鳤��" << endl;
	cin >> n;
	int* arr = new int [n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "����ǰ:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	selectsort(arr, n);
	cout << "�����:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
	delete[] arr;
	return 0;
}