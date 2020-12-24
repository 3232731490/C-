#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
class Student
{
public:
	Student (int n, int h, int s):num(n),age(h),score(s){}
	void total();
	static float averrage();
	
	//	 float averrage();   不将average设置为静态成员函数

private:
	int num;
	int age;
	int score;
	static float sum;
	static int count;
};
void Student::total()
{
	sum += score;
	count++;
}
float Student::averrage()
{
	return (sum / count);
}
float Student::sum = 0;
int Student::count = 0;

int main()
{
	Student stu[3] = {
		Student(1001,18,70),
		Student(1002,19,78),
		Student(1003,20,98)
	};
	int n;
	cout << "please input the number of students" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		stu[i].total();
	}
	cout << "the average score of" << n << "students is" << Student::averrage() << endl;
	
	//	cout << "the average score of" << n << "students is" << stu[1].averrage() << endl;  若它不是静态函数，则做此修改
	
	system("pause");
	return 0;
}
