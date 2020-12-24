#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
class Student
{
public:
	void input(Student &s)  //输入学生信息
	{
		int num, score;
		cin >> num >> score;
		s.m_num = num;
		s.m_score = score;
	}

	int max(Student *p)
	{
		int max = p->m_score;
		int num = p->m_num;
		for (int i = 0; i < 5; i++)
		{
			if (p->m_score > max)
			{
				num = p->m_num;
			}
			p++;
		}
		return num;
	}
private:
	int m_num;  //学号
	int m_score;  //成绩
};

int main()
{
	Student stu[5];
	Student* p = stu;
	for (int i = 0; i < 5; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的学号和成绩：" << endl;
		p->input(stu[i]);
	}
	int max=p->max(p);
	cout << "五个学生成绩最高的学生学号是：" << max << endl;
	system("pause");
	return 0;
}
