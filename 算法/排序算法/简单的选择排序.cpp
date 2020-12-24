#include<iostream>
using namespace std;

void select_sort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			
			}	
		}
		if (i != min)
		{
			int temp = a[min];
			a[min] = a[i];
			a[i] = temp;
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
	select_sort(a, n);


	cout << "排序后:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}