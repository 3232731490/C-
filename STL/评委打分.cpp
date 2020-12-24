#include<iostream>
#include<vector>
#include<algorithm>  //标准算法头文件
#include<deque>
#include<string>
#include<ctime>
using namespace std;
/*

//案例需求
//有5名选手：ABCDE,10个评委分别对每一个选手打分，去除最高分，最低分，取平均分


class Person
{
public:
	char m_name;
	double m_score;
};
void test01()
{
	vector<Person> v[5];  //定义五个选手
	Person p[5];
	string str = "ABCDE";
	cout << "请评委打分： " << endl;
	for (int i = 0; i < 5; i++)
	{
		p[i].m_name = str[i];
		cout << "第" << i + 1 << "个选手你们给打的分值为：" << endl;
		for (int j= 0; j < 10; j++)
		{
			double score[10];
			cin >> score[j];
			p[i].m_score[j] = score[j];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		v[i].push_back(p[i]);
	}
	deque<double> d[5][10];
	for (int i = 0; i < 5; i++)
	{
		for (vector<Person>::iterator it = v[i].begin(); it != v[i].end(); it++)
		{
			for (int j = 0; j < 10; j++)
			{
				d[i][j].push_back((*it).m_score[j]);
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		sort(d[i]->begin(), d[i]->end());
	}
	for (int i = 0; i < 5; i++)
	{
		d[i]->pop_back();
		d[i]->pop_front();
	}
	double avg[5];
	for (int i = 0; i < 5; i++)
	{
		double sum = 0;
		for (deque<double>::iterator it=d[i]->begin();it!=d[i]->end();it++)
		{
			sum += (*it);
		}
		avg[i] = sum / 8;
	}
	
	for (int i = 0; i < 5; i++)
	{
		vector<Person>::iterator it = v[i].begin();
		cout << "选手姓名：  " << (*it).m_name
			<< "平均成绩：  " << avg[i] << endl;
	}
}
int main()
{
	test01();

	return 0;
}
*/

class Person
{
public:
	Person(string name, double score)
	{
		this->m_name = name;
		this->m_score = score;
	}

	string m_name;// 姓名
	double m_score;// 平均分
};

void creatPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		double score = 0;
		Person p(name, score);

		//将创建的选手放入容器中
		v.push_back(p);
	}
}
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数放入到 deque 容器中
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//60 到100间的随机数
			d.push_back(score);
		}
		
		cout << it->m_name << "   得分：  " << endl;
		for (deque<double>::iterator it = d.begin(); it != d.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		//排序
		sort(d.begin(), d.end());

		//去除最高分和去除最低分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<double>::iterator it = d.begin(); it != d.end(); it++)
		{
			sum += *it;
		}
		double avg = sum / d.size();
		(*it).m_score = avg;
	}

}
void printScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).m_name << " 平均分：  " << it->m_score << endl;
	}
}
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//1、创建5名选手
	vector<Person> v;
	creatPerson(v);
	
	//2、给5名选手打分
	 setScore(v);

	//3、显示最后得分
	 printScore(v);

}