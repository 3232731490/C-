#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i, n,m,b;
	for (i = 1; i <= 1000; i++)
	{
		b = 0;
		for (n = 1; n <= i - 1; n++)
		{
			if (i % n == 0)
			{
				b = b + n;
			}
		}
			if (b == i)
			{
				cout << i << ',' << "its factors are"<<' ';
				for (m = 1; m < i; m++)
				{
					if (i % m == 0)
					{
						cout << m<<',';
					}
				}
				cout << endl;
			}
		
	}
	return 0;
}