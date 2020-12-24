#include<iostream>
using namespace std;

void Shell_sort(int* a, int n)
{
	int temp,j=0;
	int increment = n;
	
	do {
		increment = increment / 3 + 1;
		for (int i = increment; i < n; i++)
		{
			if (a[i] < a[i - increment])
			{
				temp = a[i];
				for (j = i - increment; a[j] > temp; j-=increment)
				{
					a[j + increment] = a[j];
				}
				a[j + increment] = temp;
			}
		}
	} while (increment > 1);
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
	Shell_sort(a, n);


	cout << "排序后:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}