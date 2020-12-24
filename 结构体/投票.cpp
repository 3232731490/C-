#include <iostream>
#include<string>
using namespace std;
struct leder
{
	string name;
		int  cout;
};
int main()
{
	leder l[3] = { "zhang",0 ,"li",0,"wang",0 };
	string name[10];
	for (int i = 0; i < 10; i++)
		cin >> name[i];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (name[i] == l[j].name)l[j].cout++;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		cout << l[i].name <<":"<< l[i].cout << endl;
	}system("pause");
	return 0;
}
void sort(int** pp, int n)
{



}