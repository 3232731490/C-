#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

class student
{
	//属性
public:
	int num;//学号
	string name;//姓名

	//行为
	//给学生赋值
	void input()
	{
		cout << "请输入学生学号：" << endl;
		cin >> num;
		cout << "请输入学生姓名：" << endl;
		cin >> name;
	}
	void print()
	{
		cout << "学生学号为：" <<num<<'\t'<< endl;
		cout << "学生姓名为：" << name << '\t' << endl;
	}

};
int main()
{
	student s;
	s.input();
	s.print();
	system("pause");
	return 0;
}
