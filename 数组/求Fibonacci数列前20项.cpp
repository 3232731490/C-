﻿#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int i, f[20] = { 1,1 };
	for (i = 2; i < 20; i++)
		f[i] = f[i - 1] + f[i - 2];
	for (i=0;i<20;i++)
	{
		if (i % 5 == 0)
			{ cout << endl;
			}
		cout << setw(8) << f[i];
	}	return 0;
}