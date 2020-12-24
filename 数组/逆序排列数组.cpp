#include<iostream>
#include<string>
using namespace std;
int num[30];
int main()
{
	cout << "请输入数组元素总个数：" << endl;
	int n;
	cin >> n;
	cout << "请输入数组各个元素：" << endl;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	cout << "初始顺序为：" << endl;
	for (int i = 0; i < n; i++)
		cout << num[i]<<",";
	int i, j;
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		int temp=num[i];
		num[i] = num[j];
		num[j] = temp;

	}
	cout << "逆序后排列为：" << endl;
	for (int k = 0; k < n; k++)
		cout << num[k] << ",";
	return 0;
}

