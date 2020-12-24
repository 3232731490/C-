#include<iostream>
#include<iomanip>
using namespace std;
void nl(int,char,char,char);
int main()
{
	cout << "请输入盘子个数：" << endl;
	int a;
	cin >> a;
	nl(a, 'A', 'B', 'C');
	return 0;
}
void move(int a, char A, char B)
{
	cout << A << "--->" <<B << endl;
}
void nl(int a,char A,char B,char C)
{
	if (a == 1)
		move(1, A,  C);
	else if(a>1)
	{
		nl(a - 1, A, C, B);
		move(a, A, C);
		nl(a - 1, B, A, C);
	}
}