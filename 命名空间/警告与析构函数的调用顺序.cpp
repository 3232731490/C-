#include <iostream>
#include <strstream>
#include<cmath>
#include<string>
using namespace std;
class student
{
public:
	student(int n, string name)
	{
		cout << "constuctor-" << n << endl;
		m_num = n; m_name = name;
	}
	~student() { cout << "destuctor-" << m_num << endl; }
	void get_data();
private :
	int m_num;
	string m_name;
};
void student::get_data()
{
	if (m_num == 0) throw m_num;
	else cout << m_num << " " << m_name << endl;
	cout << "in get_data()" << endl;

}

void fun()
{
	student stud1(1101,"tan");
	stud1.get_data();
	try {
		student stud2(0, "Li");
		stud2.get_data();
	}
	catch (int n)
	{
		cout << "num= " << n << " error£¡" << endl;
}
}
int main()
{cout << "main begin" << endl;
cout << "call fun()" << endl;
fun();
cout << "main end" << endl;

	return 0;
}
