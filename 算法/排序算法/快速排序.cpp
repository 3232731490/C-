#include<iostream>
using namespace std;
void quicksort(int a[],int low, int high)
{
	if (low >= high)
		return;
	int left = low;
	int right = high;
	
		int p = a[high];
		while (left < right)
		{
			while (left<right&&a[left] < p)
			{
				left++;
			}
			a[right] = a[left];
			while (left<right&&a[right] > p)
			{
				right--;
			}
			a[left] = a[right];
		}
                               if(left>=right)
		{
		    a[left] = p;
		}
	quicksort(a, low, right-1);
	quicksort(a, right+1, high);
}


int main()
{
	int n;
	cout << "请输入您要排序的数组长度" << endl;
	cin >> n;
	int* arr = new int [n];
	cout << "请输入" << n << "个数" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "排序前：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	quicksort(arr, 0, n - 1);
	cout << "排序后：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
	return 0;
}