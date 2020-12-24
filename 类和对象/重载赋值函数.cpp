#include <iostream>
using namespace std;
#include<string>
class Student
{
	friend class Teacher;
public:
	Student()
	{
		num = 0;
		name = "李四";
		sex = 1;
	};
	Student(int n, string s, int m) :num(n), name(s), sex(m) {};//给属性赋初值

private:
	int num;
	string name;
	int sex;      //1--男、0--女
};
class Teacher
{
public:
	Teacher()
	{
		num = 0;
		name = "张三";
		sex = 0;
	};
	Teacher(int n, string s, int m) :num(n), name(s), sex(m) {};//给属性赋初值
	Teacher& operator=(Student& s)
	{
		this->name = s.name;
		this->num = s.num;
		this->sex = s.sex;
		return *this;
	}
	void displayTeacher()
	{
		cout << "教师姓名：  " << this->name << "  教师号码：  " << this->num << "  教师性别： ";
		if (this->sex == 0)
		{
			cout << "女" << endl;
		}
		cout << "男" << endl;
	}
private:
	int num;
	string name;
	int sex;      //1--男、0--女
};

int main()
{
	int n1;
	string s1;
	int x1;
	cout << "请输入学生信息：(学号、姓名、性别（0--女、1--男）)" << endl;
	cin >>n1>>s1>>x1;
	Teacher teacher;
	Student student(n1,s1,x1);
	cout << "学生变成老师后：" << endl;
	(teacher = student).displayTeacher();
	system("pause");
	return 0;
}

