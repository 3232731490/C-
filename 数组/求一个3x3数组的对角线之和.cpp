#include<iostream>
#include<string>
using namespace std;
int main()
{
	int num[3][3];
	cout << "请输入矩阵的各个元素：" << endl;
	for (int i = 0; i < 3; i++)//输入数组元素
	{
		for(int j=0;j<3;j++)
		cin >> num[i][j];
	}
	int sum1=0,sum2=0,sum;
	for (int i = 0,j=0; i < 3; i++)
	{
		sum1 = sum1 + num[i][j];
		j++;
	}
	for (int i = 0, j = 2; i < 3; i++)
	{
		sum2 = sum2 + num[i][j];
		j--;
	}
	sum = sum1 + sum2 - num[1][1];
	cout << "矩阵对角线之和为：" << sum << endl;
	return 0;
}
