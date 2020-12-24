#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int a[3][4] =
	{ {5,12,23,56},
	{19,28,37,46},
	{-12,99,6,8}};
	int row, colum;
	int max = a[0][0];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			 if (a[i][j] > max)
			 {
				 int temp = max;
				 max = a[i][j];
				 row = i;
				 colum = j;
			 }
		}
	}
	cout << "max=" << max << "   在第" << row << "行" << colum << "列" << endl;
	return 0;
}