#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
struct student//定义学生结构体
{
	int num;
	string name;
	int score[3];
};
int main()
{
	student s[10];
	for (int i = 0; i < 10; i++)//输入学生信息
	{
		cout << "请输入第" << i + 1 << "个学生的学号和姓名：" << endl;
		cin >> s[i].num >> s[i].name;
		cout << "输入他的三科成绩" << endl;
	for (int j = 0; j < 3; j++)
			{
		cin>>s[i].score[j];//输入学生成绩
			}
	}
	float sum = 0; //所有成绩的和
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum = sum + s[i].score[j];
		}
	}
	float score0; //所有成绩的平均成绩
	score0 = sum / 30.0;
	cout << "总平均成绩为：  "<<score0<<endl;//打印总平均成绩
	float grade[3];// 三科的平均成绩
	float sum1 = 0;//单科成绩的总和
	for (int j = 0; j < 3; j++)
	{
		sum1 = 0;
		for (int i = 0; i < 10; i++)
		{
			sum1 = sum1 + s[i].score[j];
		}
		grade[j] = sum1 / 10.0;//三科平均成绩的数组
	}
	cout << "三科的平均成绩为：  ";//打印三科的平均成绩
	for (int i = 0; i < 3; i++)
	{
		cout << grade[i] << "  ";
	}
	int sum2[10];
	for (int i = 0; i < 10; i++)
	{
		int temp=0;//暂时储存每个学生的总分
		for (int j = 0; j < 3; j++)
		{
			temp += s[i].score[j];
		}
		sum2[i] = temp;
	}
	int n = 0;	int max = sum2[0];
	for (int i = 0; i < 10; i++)
	{
		if (sum2[i] > max)
			max = sum2[i]; 
			n = i;
	}
	cout << "分数最高的学生的信息为：" << endl;
	cout << "学号： " << s[n].num << "姓名： " << s[n].name << "三科成绩  ";
	for (int i = 0; i < 3; i++)
	{
		cout << s[n].score[i]<<" ";
	}
	system("pause");
	return 0;
}
