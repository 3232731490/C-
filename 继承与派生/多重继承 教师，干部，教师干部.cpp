#include <iostream>
using namespace std;
#include<string>
class Base
{
public:
	Base(string name, int age, int sex, string addr, string phone)
	{
		m_name = name;
		m_age = age;
		m_sex = sex;
		m_addr = addr;
		m_phone = phone;
 }
	void display();

private:

	string m_name;
	int m_age;
	int m_sex;
	string m_addr;
	string m_phone;
};
class Teacher: public Base
{
public:
	Teacher(string name, int age, int sex, string addr, string phone, string title) :Base(name, age, sex, addr, phone) { m_title = title; }
	void display();

private:
	string m_title;
};


class Cader : public Base
{
public:
	Cader(string name, int age, int sex, string addr, string phone, string post) :Base(name, age, sex, addr, phone) { m_post=post; }
	void display();

	 string m_post;
};

class Teacher_Cader :public Teacher, public Cader
{
public:
	Teacher_Cader(string name, int age, int sex, string addr, string phone, string post, string title, int wages) :Cader(name, age, sex, addr, phone, post), Teacher(name, age, sex, addr, phone, title) { m_wages = wages; }
	void show();
private:
	int m_wages;
};
void Base::display()
{
	cout << "name=  " << m_name << endl;
	cout << "age=  " << m_age << endl;
	cout << "sex=  " << ((m_sex == 1) ? "男" : "女") << endl;
	cout << "addr=  " << m_addr << endl;
	cout << "phone=  " << m_phone << endl;
}
void Teacher::display()
{
	Base::display();
}
void Cader::display()
{
	Base::display();
	cout << "post=  " << m_post << endl;
}
void Teacher_Cader::show()
{
	Teacher::display();
	cout <<  "post=   " << m_post <<endl<< "wages=  " << m_wages <<  endl;
}
int main()
{
	Teacher_Cader tc("倪路", 18,1,"内江","18582699881","学生会","干事",0);
	tc.show();
	system("pause");
	return 0;
}

