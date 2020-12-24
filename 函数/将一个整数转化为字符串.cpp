#include <iostream>
using namespace std;
void nl(int p)
{
	char a;
	if (p /10 != 0)
	{
		nl(p / 10);
	}
	a = p%10 + '0';
	cout << a;
}
int main()
{
	cout << "please enter a intenger" << endl;
	int p;
	cin >> p;
	nl(p);
	return 0;
}