#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	int i, n,m;
		for (n = 1; n <= 7; n += 2)
		{
			for (m = 1; m <= n; m++)
			{
				cout << '\*' << ' ';
			}
			cout << endl;
		}
		for (n = 5; n >= 1; n -= 2)
		{
			for (m = 1; m <= n; m++)
			{
				cout << '\*' << ' ';
			}
			cout << endl;
		}
	return 0;
}