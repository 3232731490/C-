#include<iostream>
#include<string>
using namespace std;
void swap(int& a, int& b,int &c)
{
	int temp;
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (a > c)
	{
		temp = a;
		a = c;
		c = temp;
	}
	if (b > c)
	{
		temp = b;
		b = c;
		c = temp;
	}
}
int main()
{

	cout << "please enter three intengers:" << endl;
	int i, j,k;
	cin >> i >> j>>k;
	cout << "交换前：" << endl;
	cout << i << j <<k<< endl;
	swap(i, j,k);
	cout << "交换后：" << endl;
	cout << i << j <<k<< endl;
		system("pause");
		return 0;
	
}

