#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

void show(int n)
{
	int i = 0;//ɳ©���������
	int sum = 0;//��¼ɳ©�����*����
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
	cout << "ʣ��:  " << n - 2 * sum - 1;
}
int main()
{
	cout << "���������� * ��" << endl;
	int n;
	cin >> n;
	show(n);
	return 0;

}