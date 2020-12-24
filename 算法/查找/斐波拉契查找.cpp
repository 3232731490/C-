#include<iostream>

using namespace std;

#define maxmize 100
int Fibonacci(int k)
{
	if (k == 1 || k == 0)
	{
		return 1;
	}
	else
	{
		return Fibonacci(k - 1) + Fibonacci(k - 2);
	}
}

int Fibonacci_Search(int* a, int n, int key)
{
	int low = 0, high = n-1;
	int k = 0,mid;
	
	while (n > Fibonacci(k))
	{
		k++;
	}
	for (int i = n; i < Fibonacci(k); i++)
	{
		a[i] = a[n - 1];
	}
	while (low <= high)
	{
		mid = low + Fibonacci(k - 1)- 1;
		if (a[mid] == key)
		{
			if (mid < n)
			{
				return mid;
			}
			else
			{
				return n - 1;
			}
		}
		else if (a[mid] < key)
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			high = mid - 1;
			k = k - 1;
		}
	}

	return 0;
}

int main()
{
	cout << "您要输入几个有序数列：(小于100个)" << endl;
	int n;
	cin >> n;

	int* a = new int[maxmize];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "您要查找那个数" << endl;
	int key;
	cin >> key;
	int index;
	index=Fibonacci_Search(a, n, key);
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