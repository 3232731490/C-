#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
struct student
{
	int num;
	string name;
	int score[3];
};
void print (student* s)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "学号： " << s->num << "姓名：  " << s->name;
		cout << " " << "三科成绩： ";
		for (int j = 0; j < 3; j++)
		{
			cout << s->score[j] << " ";
		}
		s++;
		cout << endl;
	}
}
int main()
{
	student s[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的学号和姓名：" << endl;
		cin >> s[i].num >> s[i].name;
		cout << "请输入他的三科成绩：" << endl;
		for (int j = 0; j < 3; j++)
			cin >> s[i].score[j];
	}
	student* p = &s[0];
	print(p);
	system("pause");
	return 0;
}
