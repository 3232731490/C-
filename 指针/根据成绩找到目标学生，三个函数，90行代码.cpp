#include <iostream>
#include<string>
using namespace std;
void grade_(int (*p)[5] ,double *n)
{
	*n = 0;
	int sum=0;
	for (int i = 0; i < 4; i++)
	{
		sum = **(p + i) + sum;
	}
	*n = sum / 4;
}
void find(int(*p)[5], int *num)
{
	for (int i = 0; i < 4; i++)
	{
		int k = 0;//记录不及格科目的数目
		float a = 0, sum = 0;//a为学生的平均成绩，sum为每个学生的成绩总和
		for (int j = 0; j < 5; j++)
		{
			if (*(*(p + i) + j) < 60)
				k++;
		}
		if (k > 2)
		{
			cout << "有两科以上成绩不及格的学生有：" << endl;
			cout << "学号：" << num[i];
			cout << endl;
			for (int b = 0; b < 5; b++)
			{
				cout << *(*(p + i) + b) << "  ";
			}
			cout << endl;
			for (int j = 0; j < 5; j++)
			{
				sum = *(*(p + i)+j) + sum;
			}
			a= sum / 5;
			cout << "平均成绩" <<a<< endl;
		}
	}
}
void good(int(*p)[5],int *num, string *name)
{
	for (int i = 0; i < 4; i++)
	{
		float a = 0, sum = 0;//a平均成绩,sum每个学生的总成绩
		int k = 0;//k记录学生成绩在85分以上的科目数
		for (int j = 0; j < 5; j++)
		{
			if (*(*(p + i) + j) > 85)
				k++;
			sum = *(*(p + i) + j) + sum;
		}
		a = sum / 5;
		if (a > 90 || k == 5)
		{
			cout << "平均成绩在90分以上或全部成绩大于85分的学生有：" << endl;
			cout << "学生的学号为：" << num[i] << "该学生的姓名为：" << name[i] << endl;
		}
	}
}
int main()
{
	string name[4];//学生姓名
	int num[4];
	for (int i = 0; i < 4; i++)
	{
		cout << "请输入第"<<i+1<<"个学生的学号和姓名：" << endl;
		cin >> num[i] >> name[i];
	}
	int grade[4][5]; //学生成绩
	int(*p)[5];
	p = grade;
	for (int i = 0; i < 4; i++)
	{
		cout << "请输入第"<<i+1<<"个学生的五门成绩：" << endl; 
		for (int j = 0; j < 5; j++)
			cin >> grade[i][j];
	}
	double n;//平均成绩
	grade_(p, &n);
	cout << "第一科的平均成绩为：" <<n<< endl;
	find(p, num);
	cout << endl;
	good(p, num, name);
	cout << endl;
	system("pause");
	return 0;
}