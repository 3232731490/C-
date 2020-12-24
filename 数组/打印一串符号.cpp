#include<iostream>
#include<string>
using namespace std;
int main()
{
	/*string lh = "* * * * *";
	string nl = { ' ',' ' };
	for (int i = 0; i < 5; i++)
	{
		cout << lh << endl;
		lh = nl+lh;
	}*/

	char lh[10] = "* * * * *", nl[2] = { ' ',' ' };
	for (int i = 0, i < 5; i++)
	{
		cout << lh << endl;
		lh = strcat_s(lh, nl);
	}
	system("pause");
	return 0;
}
