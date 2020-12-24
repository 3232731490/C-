#include<iostream>
using namespace std;

bool search(int a[], int low, int mid,int high,int s)
{
	if (low == high)
	{
		if (a[mid] == s)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (a[mid] > s)
		{
			high = mid - 1;
			mid = (high + low) / 2;
			return search(a, low, mid, high, s);
		}
		else if(a[mid]<s)
		{
			low = mid + 1;
			mid = (low + high) / 2;
			return search(a, low, mid, high, s);
		}
		else
		{
			return true;
		}
	}
}
void merge(int a[], int low, int mid, int high)
{
	int len = high - low + 1;
	int* b = new int[len];
	int left = low, right = mid + 1,i=0;
	while (left <= mid && right <= high)
	{
		b[i++] = (a[left] > a[right]) ? a[right++] : a[left++];
	}
	while (left <= mid)
	{
		b[i++] = a[left++];
	}
	while (right <= high)
	{
		b[i++] = a[right++];
	}
	for (int j = 0; j < len; j++)
	{
		a[low+j] = b[j];
	}
	delete[]b;
}

void mergesort(int a[],int low,int high)
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
	cout << "��Ҫ����һ������Ϊ���ٵ����У�" << endl;
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "�������" <<i+1<< "������" << endl;
		cin >> a[i];
	}

	//����ǰ��ӡ
	cout << "����ǰ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	//���򡪡��鲢����
	mergesort(a, 0, n - 1);

	//������ӡ
	cout << "�����" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	int low = 0, high = n - 1, mid = (low + high) / 2;
	cout << "��������Ҫ���ҵ����֣�" << endl;
	int s;
	cin >> s;
	bool result = search(a, low, mid, high, s);
	if (result)
	{
		cout << "���ҵ�Ŀ������!" << endl;
	}
	else
	{
		cout << "δ�ҵ�Ŀ�����֣�" << endl;
	}
	delete[]a;
	cout << "����ռ����ͷ�" << endl;
	system("pause");
	return 0;
}