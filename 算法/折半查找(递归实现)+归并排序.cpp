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
	cout << "您要输入一个长度为多少的数列：" << endl;
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" <<i+1<< "个数字" << endl;
		cin >> a[i];
	}

	//排序前打印
	cout << "排序前：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	//排序——归并排序
	mergesort(a, 0, n - 1);

	//排序后打印
	cout << "排序后：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	int low = 0, high = n - 1, mid = (low + high) / 2;
	cout << "请输入您要查找的数字：" << endl;
	int s;
	cin >> s;
	bool result = search(a, low, mid, high, s);
	if (result)
	{
		cout << "查找到目标数字!" << endl;
	}
	else
	{
		cout << "未找到目标数字！" << endl;
	}
	delete[]a;
	cout << "数组空间已释放" << endl;
	system("pause");
	return 0;
}