#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void nl(int arr[], int n);
int main()
{
	cout << "please enter 10 numbers:" << endl;
	int arr[10];
	for (int i = 0; i <= 9; i++)
		cin >> arr[i];
	cout << "排序前......" << endl;
	for (int i = 0; i <= 9; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "排序后......" << '\n';
	nl(arr, 10);
	for (int i = 0; i <= 9; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
void nl(int arr[], int n)
{
	for (int k = 0; k < n-1; k++)
	{
		int i = k;
		for (int j = i+1; j <n; j++)
		{
			if (arr[j] < arr[i]) i = j;
		}
		int temp;
		temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}

}