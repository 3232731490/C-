#include <iostream>
#include<string>
#include"jiaoyubumen.h"
#include"renshibumen.h"
using namespace std;
int main()
{
	nl1::Student s1;
	nl2::Student s2;
	cout << "请输入人事部门储存的学生信息：" << endl;
	int num1, num2;
	char name1[50], name2[50],addr1[50];
	int age1, sex2, score2;
	cin >> num1 >> name1 >> age1 >> addr1;
	s1.set_student(num1, name1, age1, addr1);
	cout << "请输入教育部门储存的学生信息：" << endl;
	cin >> num2 >> name2 >> sex2 >> score2;
	s2.set_student(num2, name2, sex2, score2);
	cout << endl;
	cout << "教育部门所储存的学生信息：" << endl;
	cout << "学号：" << s2.get_num() << endl;
	cout << "姓名：" ;
	char* p = s2.get_name();
	while (*p!= '\0')
	{
		cout << *p;
		p++;
	}
	cout << endl;
	cout << "性别：" << ((s2.get_sex() == 1) ? "男" : "女") << endl;
	cout << "成绩：" << s2.get_score() << endl;
	cout << "————————————————————————" << endl;
	cout << "人事部门所储存的学生信息：" << endl;
	cout << "学号：" << s1.get_num() << endl;
	cout << "姓名：" ;
	 p = s2.get_name();
	while (*p != '\0')
	{
		cout << *p;
		p++;
	}
	cout << endl;
	cout << "年龄：" << s1.get_age()<< endl;
	cout << "地址：" ;
	p = s1.get_addr();
	while (*p != '\0')
	{
		cout << *p;
		p++;
	}
	return 0;
}
