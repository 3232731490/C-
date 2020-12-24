#include <iostream>
using namespace std;
#include<string>
class Teacher
{
public:
	Teacher(string name, int num, char sex)
	{
		m_name = name;
		m_num = num;
		m_sex = sex;
	}
	void display()
	{
		cout << "name:  " << m_name << endl;
		cout << "num:  " << m_num << endl;
		cout << "sex:  " << m_sex << endl;
	}
protected:
	string m_name;
	int m_num;
	char m_sex;
};
class BirthDate
{
public:
	BirthDate(int year, int month, int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	void display()
	{
		cout <<"birthday:  "<< m_year << "/" << m_month << "/" << m_day << endl;
	}
	void change(int year,int month,int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
private:
	int m_year;
	int m_month;
	int m_day;
};
class Professor:public Teacher
{
public:
	Professor(int year, int month, int day, string name, int num, char sex) :birthday(year, month, day), Teacher(name, num, sex) {};
	void show()
	{
		Teacher::display();
		birthday.display();
	}
	void change()
	{
		cout << "请输入修改后的生日时间" << endl;
		int year, month, day;
		cin >> year >> month >> day;
		birthday.change(year, month, day);
	}
protected:
	BirthDate birthday;
};
int main()
{
	Professor pro(2003,11,12,"倪路",731,'f');
	cout << "当前教授的信息为：" << endl;
	pro.show();
	pro.change();
	cout << "修正信息后的教授信息为：" << endl;
	pro.show();
	system("pause");
	return 0;
}

