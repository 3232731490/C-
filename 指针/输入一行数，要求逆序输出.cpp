#include <iostream>
#include<string>
using namespace std;
void sort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (2 * (i+1) > n)break;
		else {
			int temp = arr[i];
			arr[i] = arr[n - i-1];
			arr[n - i-1] = temp;
		}
	}
}
int main()
{
	int arr[100];
	cout << "您要输入几个数：" << endl;
	int n;
	cin >> n;
	cout << "请输入" << n << "个数" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr,n);
	for (int i = 0; i < n; i++)
		cout << arr[i]<<" ";
	system("pause");
	return 0;
}