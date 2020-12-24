#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int arr[][4] = { {11,32,45,67},
	{22,44,66,88},{15,72,43,37} };
	int nl(int arr[][4]);
	int max;
	max = nl(arr);
	cout << "max=" << max;
	return 0;
}
int nl(int arr[][4])
{
	int max = arr[0][0];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] > max)
				max = arr[i][j];
		}
	}
	return max;
}