#include <iostream>
using namespace std;
#include<string>
class Student
{
public:
	void get_value(int num, string name, char sex)
	{
		this->num = num;
		this->name = name;
		this->sex = sex;
		cout << endl;
	}
	void display()
	{
		cout << "num= " << num << endl;
		cout << "name= " << name << endl;
		cout << "sex= " << sex << endl;
	}

private:
	int num;
	string name;
	char sex;
};
class Student1 :private Student
{
public:
	Student1(int num, string name, char sex, int age,string addr)
	{
		get_value(num,name,sex);
		this->age = age;
		this->addr = addr;
}
	void display_1()
	{
		display();
		cout << "age= " << age << endl;
		cout << "addr= " << addr << endl;
	}
private:
	int age;
	string addr;
};
int main()
{
	int num;
	string name;
	char sex;
	int age;
	string addr;
	cout << "请输入学号、姓名、性别" << endl;
	cin >> num >> name >> sex;
	cout << "请输入年龄和地址：" << endl;
	cin >> age >> addr;
	Student1 s(num,name,sex,age,addr);
	s.display_1();
	system("pause");
	return 0;
}

