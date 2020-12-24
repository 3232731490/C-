#include<iostream>
#include<string>
using namespace std;
string name[50], num[50];
int n;
int main()
{
	void find(string);
	void input();
	cout << "please enter students' number:" << endl;
	cin >> n;
	input();
	string find_name;
	cout << "please enter student's name" << endl;
	cin >> find_name;
	find(find_name);
	return 0;
}
void input( )
{
	for (int i = 0; i < n; i++)
	{
		cout << "please enter student's name and number" << endl;
		cin >> name[i] >> num[i];
	}
}
void find( string find_name )
{
	bool flag =false;
	for (int i = 0;i<n ; i++)
	{
		if (find_name == name[i])
		{
			cout << "the student has been find:" << endl;
			cout << "his name is:" << name[i] << "his number is" << num[i];
			flag=true; break;
		}
	}
	if (flag==false) { cout << "the student hasn't been find"; }
}