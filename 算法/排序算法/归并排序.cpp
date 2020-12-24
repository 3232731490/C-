#include<iostream>
using namespace std;
void merge(int a[], int low, int mid, int high)
{
	int N=high-low+1;
	int* b = new int[N];
	int left = low;
	int right = mid+1;
	int i = 0;
	while (left <= mid&&right<=high)
	{
		b[i++] = (a[left] > a[right]) ? a[right++] : a[left++];
	}
	while(left <= mid)
	{
		b[i++] = a[left++];
	}
	while (right <= high)
	{
		b[i++] = a[right++];
	}
	for (int i = 0; i < N; i++)
	{
		a[low + i] = b[i];
	}
	delete[] b;
}
void mergesort(int a[], int low ,int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		merge(a, low, mid, high);
	}

}

int main()
{
	int n;
	cout << "��������Ҫ��������鳤��" << endl;
	cin >> n;
	int* arr = new int [n];
	cout << "������" << n << "����" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "����ǰ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	mergesort(arr, 0, n-1);
	cout << "�����" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
	return 0;
}