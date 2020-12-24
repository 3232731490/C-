#include<iostream>
#include<list>
#include<algorithm>
#include<string>
using namespace std;

//list���� ������ �����Զ�����������������
//���������������  ��������ͬ������������
class Person
{
public:
    Person(string name, int age, int height) :m_name(name), m_age(age), m_height(height) {};

    string m_name; // ����
    int m_age;   //����
    int m_height;  //���
};

//ָ���������
bool myCompare1(Person &p1, Person &p2)
{
    //���������������
    if (p1.m_age == p2.m_age)
    {
        //������߽��н�������
        return p1.m_height > p2.m_height;
    }
    return p1.m_age < p2.m_age;

}

void test01()
{
    list <Person> l;  //��������

    //׼������
    Person p1("����", 35, 175);
    Person p2("�ܲ�", 45, 180);
    Person p3("��Ȩ", 40, 190);
    Person p4("����", 25, 170);
    Person p5("�ŷ�", 35, 160);
    Person p6("����", 35, 200);

    //��������
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);
    cout << "����ǰ��" << endl;
    for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "������ " << (*it).m_name << "���䣺  " << (*it).m_age << "��ߣ�  " << (*it).m_height << endl;
    }

    cout << "-----------------------------------" << endl;
    //����
    cout << "�����" << endl;
    l.sort(myCompare1);
    for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "������ " << (*it).m_name << "���䣺  " << (*it).m_age << "��ߣ�  " << (*it).m_height << endl;
    }

}
int main()
{
    test01();

    return 0;
}