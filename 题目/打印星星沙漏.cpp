#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

void show(int n)
{
	int i = 0;//沙漏上面的行数
	int sum = 0;//记录沙漏上面的*总数
	while ((2 * sum + 1) < n)
	{
		i++;
		sum += 2 * i + 1;

	}
	sum = 0;
	for (int a = 1; a <= i - 1; a++)
	{
		sum += 2 * a + 1;
	}
	for (int j = i - 1, k = 10; k < i + 9, j > 0; j--, k++)
	{
		cout << setw(k) << setfill(' ');
		for (int m = 0; m < 2 * j + 1; m++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << setw(i + 9) << setfill(' ') << "*" << endl;
	for (int j = 1, k = i + 8; k >= 10, j <= i - 1; j++, k--)
	{
		cout << setw(k) << setfill(' ');
		for (int m = 0; m < 2 * j + 1; m++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "剩余:  " << n - 2 * sum - 1;
}
int main()
{
	cout << "请输入最多的 * 数" << endl;
	int n;
	cin >> n;
	show(n);
	return 0;

}