#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	char i, j, k;
	for (i = 'X'; i <= 'Z'; i++)
	{
		for (j = 'X'; j <= 'Z'; j++)
		{
			for (k = 'X'; k <= 'Z'; k++)
			{
				if (i != 'X' && k = 'Y' && i!j && i != k && j != k)
					cout << "A" << "-" << i << endl << "B" << "-" << j << endl << "C" << "-" << k << endl;
			}
		}
	}
	return 0;
}