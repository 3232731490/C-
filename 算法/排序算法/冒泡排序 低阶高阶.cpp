#include<iostream>
using namespace std;

void Bubble_sort(int* a ,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}

}

void super_Bubble_sort(int* a, int n)
{
	int flag=1;
	for (int i = 0; i < n&&flag; i++)
	{
		flag = false;
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				flag = true;
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}

}
int main()
{
	cout << "您要输入几个数:" << endl;
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "排序前:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	super_Bubble_sort(a, n);


	cout << "排序后:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}