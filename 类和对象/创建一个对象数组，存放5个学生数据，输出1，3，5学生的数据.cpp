#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
class Student
{
public:
	void input(Student&);
	void output(Student&);
private :
	int m_num;    //学号
	int m_score;  //成绩
};

int main()
{
	Student stu[5];
	Student* p;
	p = stu;
	for (int i = 0; i < 5; i++)
	{
		cout << "请输入第" << i+1 << "个学生的信息：（学号，成绩）";
		(*p).input(stu[i]);
		p++;
	}
	p = stu;
	for (int i = 0; i < 5; i++, p++)
	{
		cout << "第" << i+1 << "个学生：";
		(*p).output(stu[i]);
		p++; i++;
		cout << endl;
	}
	system("pause");
	return 0;
}

void Student::input(Student &s)
{
	int num, score;
	cout << "please input num & score : " << endl;
	cin >> num >> score;
	s.m_num = num;
	s.m_score = score;
}

void Student::output(Student &s)
{
	cout <<"学号："<< s.m_num <<"分数："<< s.m_score << endl;
}
