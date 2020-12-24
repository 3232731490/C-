#include<string>
#include<iostream>
namespace nl2
{

	class Student
	{
	public:
		void set_student(int num, char name[50], int sex, int score)
		{
			m_num = num;
			strcpy_s(m_name, name);
			m_sex = sex;
			m_score = score;
		}
		int get_num()
		{
			return m_num;
		}
		char* get_name()
		{
			return m_name;
		}
		int get_sex()
		{
			return m_sex;
		}
		int get_score()
		{
			return m_score;
		}
	private:
		int m_num;//学号
		char m_name[50];//姓名
		int m_sex;//性别（0--女、1--男）
		int m_score;//成绩
	};

}