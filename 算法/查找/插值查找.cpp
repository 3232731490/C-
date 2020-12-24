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
	cout << "����n���������У�" << endl;
	int n;
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "��Ҫ�����Ǹ���" << endl;
	int key;
	cin >> key;
	int index;
	index=search(a, n, key);
	if (index == 0)
	{
		cout << "û���ҵ�������" << endl;
	}
	else
	{
		cout << "�ҵ�������" << a[index] << endl;;
	}
	system("pause");
	return 0;
}