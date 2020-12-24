#include<iostream>
#include<vector>
#include<algorithm>  //��׼�㷨ͷ�ļ�
#include<deque>
#include<string>
#include<ctime>
using namespace std;
/*

//��������
//��5��ѡ�֣�ABCDE,10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣���ͷ֣�ȡƽ����


class Person
{
public:
	char m_name;
	double m_score;
};
void test01()
{
	vector<Person> v[5];  //�������ѡ��
	Person p[5];
	string str = "ABCDE";
	cout << "����ί��֣� " << endl;
	for (int i = 0; i < 5; i++)
	{
		p[i].m_name = str[i];
		cout << "��" << i + 1 << "��ѡ�����Ǹ���ķ�ֵΪ��" << endl;
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
		cout << "ѡ��������  " << (*it).m_name
			<< "ƽ���ɼ���  " << avg[i] << endl;
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

	string m_name;// ����
	double m_score;// ƽ����
};

void creatPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		double score = 0;
		Person p(name, score);

		//��������ѡ�ַ���������
		v.push_back(p);
	}
}
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����ί�ķ������뵽 deque ������
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//60 ��100��������
			d.push_back(score);
		}
		
		cout << it->m_name << "   �÷֣�  " << endl;
		for (deque<double>::iterator it = d.begin(); it != d.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		//����
		sort(d.begin(), d.end());

		//ȥ����߷ֺ�ȥ����ͷ�
		d.pop_back();
		d.pop_front();

		//ȡƽ����
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
		cout << (*it).m_name << " ƽ���֣�  " << it->m_score << endl;
	}
}
int main()
{
	//���������
	srand((unsigned int)time(NULL));
	//1������5��ѡ��
	vector<Person> v;
	creatPerson(v);
	
	//2����5��ѡ�ִ��
	 setScore(v);

	//3����ʾ���÷�
	 printScore(v);

}