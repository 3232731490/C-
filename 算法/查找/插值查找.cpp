#include<iostream>

using namespace std;

int search(int* a, int n, int key)
{
	int low = 0, high = n-1;
	int mid = low + (key - a[low]) / (a[high] - a[low]) * (high - low);
	while (low <= high)
	{
		if (a[mid] == key)
		{
			return mid;
		}
		else if (a[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
		mid = low + (key - a[low]) / (a[high] - a[low]) * (high - low);
	}

	return 0;
}

int main()
{
	cout << "输入n个有序数列：" << endl;
	int n;
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "您要查找那个数" << endl;
	int key;
	cin >> key;
	int index;
	index=search(a, n, key);
	if (index == 0)
	{
		cout << "没有找到该数！" << endl;
	}
	else
	{
		cout << "找到该数：" << a[index] << endl;;
	}
	system("pause");
	return 0;
}