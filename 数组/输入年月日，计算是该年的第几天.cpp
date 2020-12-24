#include<iostream>
#include<string>
using namespace std;
int main()
{
	int year, a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, day,month;
	cout << "please enter year,month,day" << endl;
	cin >> year>>month>>day ;
	cout << year << "/" << month << "/" << day << "/" << endl;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		a[2] = 29;
	}
	int sum=0;
	if (month <= 0 || month >= 13)
		cout << "erroy,please enter again..." << endl;
	else
	{
		for (int i = 1; i <= month - 1; i++)
		{
			sum += a[i];
		}
		sum += day;
		cout << sum;
	}
	return 0;
}
