#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void min(int(*arr)[5], int s, int* m);
void nl(int (*arr)[5] )
{
	int *max = *(arr+2)+2,*min1=*arr, *min2 = *arr+4, *min3 = *(arr+4)+4, *min4 =*(arr+4);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (*(*(arr + i) + j) > *max)
			{
				int temp = *max;
				*max = *(*(arr + i) + j);
				*(*(arr + i) + j) = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (*(*(arr + i) + j)<*min1)
			{
				int temp = *min1;
				*min1 = *(*(arr + i) + j);
				*(*(arr + i) + j) = temp;
			}
		}
	}
	min(arr, *min1, min2);
	min(arr, *min2, min3);
	min(arr, *min3, min4);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << *(*(arr+i)+j)<<" ";
		}
		cout << endl;
	}
}
void min(int (*arr)[5], int s,int * m)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (*(*(arr + i) + j) < *m && *(*(arr + i) + j) > s)
			{
				int temp = *m;
				*m = *(*(arr + i) + j);
				*(*(arr + i) + j) = temp;
			}
		}
	}
}
int main()
{
	cout << "请按行输入矩阵元素：" << endl;
	int arr[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
		}
	}
	nl(arr);
	system("pause");
	return 0;
}
