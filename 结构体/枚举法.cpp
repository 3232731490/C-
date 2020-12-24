#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
	enum color{red,yellow,blue,white,black };
	color nl;
	int n=0;
	for (int i=red; i <= black; i++)
	{
		for (int j = red; j <= black; j++)
		{
			if (i!= j)
			{
				for (int k = red; k <= black; k++)
				{
					if (k != i && k != j)
					{
						n++;
						cout << setw(3) << n;
						for (int a = 0; a < 3; a++)
						{
							switch (a)
							{
							case 0:nl = color(i); break;
							case 1:nl = color(j); break;
							case 2:nl = color(k); break;
							}
							switch (nl)
							{
							case red:cout << setw(8) << "red" << "  "; break;
							case yellow:cout << setw(8) << "yellow" << "   "; break;
							case blue:cout << setw(8) << "blue" << "   "; break;
							case white:cout << setw(8) << "white" << "   "; break;
							case black:cout << setw(8) << "black "<< "   "; break;
							}
						}
					}
					cout << endl;
				}
			}
		}
	}
	cout << "total :   " << n<<endl;
	system("pause");
	return 0;
}
