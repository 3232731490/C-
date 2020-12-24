#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int i, m[11],j,k;
	cout << "please enter ten intenger:" << endl;
	for (i = 1; i <= 10; i++)
		cin >> m[i];
	for (j = 9; j >= 1; j--)
	{
		for (i = 1; i <= j; i++)
		{
			if (m[i] > m[i + 1])
			{
				k = m[i];
				m[i] = m[i + 1];
				m[i + 1] = k;
			}
		}
	}
	for(i=1;i<=10;i++)
	cout << m[i] << endl;
	return 0;
}