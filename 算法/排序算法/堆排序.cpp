#include<iostream>
using namespace std;

void HeapAdjust(int* a, int s, int m)
{
	int temp,j;
	temp = a[s];
	for (j = 2 * s + 1; j < m; j = 2*j+1)
	{
		if (j < m-1 && a[j] < a[j + 1])
		{
			j++;
		}
		if (temp >= a[j])
			break;

		a[s] = a[j];
		s = j;
	}
	a[s] = temp;
}

void HeapSort( int *a,int n)
{
	//����󶥶�
	for (int i = (n-1) / 2; i >= 0; i--)
	{
		HeapAdjust(a, i, n);
	}

	//����
	for (int i = 1; i < n; i++)
	{
		int temp = a[0];
		a[0] = a[n - i];
		a[n - i] = temp;
		HeapAdjust(a, 0, n - i);
	}
}

int main()
{
	cout << "��Ҫ���뼸����:" << endl;
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "����ǰ:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	HeapSort(a, n);


	cout << "�����:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}