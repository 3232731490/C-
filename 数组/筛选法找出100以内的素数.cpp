#include<iostream>
#include<string>
using namespace std;
int num[50];
int main()
{
	int l = 0;
	int k = 0;
	for (int j = 3; j <= 100; j++)
	{
		bool flag = false;
		for (int i = 2; i < j; i++)
		{
			if (j % i == 0)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
				num[k] = j;
				l++;
				k++;
		}
	}
	for (int m = 0; m < l; m++)
		cout << num[m] << endl;
	return 0;
}
