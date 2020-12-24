#include <iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	for (int n = 1; n <= 8; n++)
		cout << setw(20 - n) << setfill(' ') << " "        
		<< setw(2 * n - 1) << setfill('B') << "B" << endl;
	system("pause");
	return 0;
}
