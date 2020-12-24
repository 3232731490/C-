#include<iostream>
#include<vector>
#include<algorithm>//��׼�㷨ͷ�ļ�
#include<string>
using namespace std;

//vector���������������
void MyPrint(int val)
{
	cout << val << endl;
}
void test01()
{
	vector<int> v;  //����һ��vector�������൱��һ������ 
	v.push_back(10);//β�巨��������
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//���������е�����
	//��һ�ַ���
	vector<int>::iterator itbegin = v.begin();  //��ʼ������  ָ�������е�һ������
	vector<int>::iterator itEnd = v.end();   //����������  ָ�����������һ�����ݵ���һ��λ��
	while (itbegin != itEnd)
	{
		cout << *itbegin << endl;
		itbegin++;
	}
	cout << "-------------------------------------"<<endl;
	
	//�ڶ��ַ���
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "-------------------------------------" << endl;
	
	//�����ַ���
	//STL�ṩ�ı����㷨
	for_each(v.begin(), v.end(), MyPrint);
}


//vector����Զ�����������
class person
{
public:
	person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};

void test02()
{
	vector<person> v;
	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);

	//�������в�������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//���������е�����
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������ " << (*it).m_name << "  ���䣺  " << (*it).m_age << endl;
		//cout << "������ " << it->m_name << "  ���䣺  " << it->m_age << endl;
	}
}

//����Զ������͵�ָ��
void test03()
{
	vector<person*> v;
	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);

	//�������в�������
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	//���������е�����
	for (vector<person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������ " << (*it)->m_name << "  ���䣺  " << (*it)->m_age << endl;
		//cout << "������ " << (*it)->m_name << "  ���䣺  " << (*it)->m_age << endl;
	}

}
int main()
{
	test01();
	test02();
	test03();
	return 0;
}