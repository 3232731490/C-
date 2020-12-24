#include<iostream>
using namespace std;

void insert_sort(int* a, int n)
{
	int temp,j=0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			temp = a[i];
			for ( j = i-1;a[j]>temp; j--)
			{
				a[j+1] = a[j];
			}
			a[j + 1] = temp;
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
	insert_sort(a, n);


	cout << "排序后:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}