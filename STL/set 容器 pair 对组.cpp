#include<iostream>
#include<set>
#include<string>
using namespace std;
//set /multiset �ٲ�������ʱ�Զ��ź���   �ײ��Ƕ�����
//set ���������ظ���  multiset ���������ظ�

void Print(set<int>& s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//set ��������͸�ֵ
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(50);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    
    //����Ԫ���Զ����򣬲���������ظ�ֵ
    Print(s1);

    set<int> s2(s1);
    Print(s2);
}


//set ��С�ͽ���
void test02()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    //�ж��Ƿ�Ϊ��
    if (s1.empty())
    {
        cout << "����Ϊ�գ�" << endl;
    }
    else
    {
        cout << "������Ϊ�գ�" << endl;
        cout << "s1�Ĵ�СΪ��  " << s1.size() << endl;
    }


    //��������
    set<int> s2;
    s2.insert(100);
    s2.insert(200);
    s2.insert(300);
    s2.insert(400);

    cout << "����ǰ��  " << endl;
    Print(s1);
    Print(s2);


    s1.swap(s2);
    cout << "������" << endl;
    Print(s1);
    Print(s2);

}


//set�����ɾ��
void test03()
{
    set<int> s1;
    
    //����
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    Print(s1);

    //ɾ��
    s1.erase(s1.begin());  //ɾ����һ��Ԫ��
    Print(s1);

    s1.erase(20);  //ɾ�������е� 20
    Print(s1);

    //���
    s1.erase(s1.begin(), s1.end());//ɾ���ӿ�ʼ��ĩβ��������
    Print(s1);

    s1.clear();
}


//set ���Һ�ͳ��
void test04()
{
    //����
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    set<int> ::iterator it=s1.find(30);
    if (it != s1.end())
    {
        cout << "�ҵ�Ԫ��:  " ;
        cout << *it << endl;
    }
    else
    {
        cout << "δ�ҵ���" << endl;
    }

    //ͳ��
    int num = s1.count(30);//ͳ�� 30 �ĸ���
    cout << "30�ĸ���Ϊ�� " << num << endl;
}


//set �� multiset ����
//
void test05()
{
    set<int> s1;

    //set���� �ٲ���ʱͬʱ���ز���ɹ����
    pair<set<int>::iterator, bool>ret = s1.insert(10);
    if (ret.second)
    {
        cout << "��һ�β���ɹ���" << endl;

    }
    else
    {
        cout << "��һ�β���ʧ��" << endl;
    }

    ret=s1.insert(10);
    if (ret.second)
    {
        cout << "�ڶ��β���ɹ���" << endl;

    }
    else
    {
        cout << "�ڶ��β���ʧ��" << endl;
    }


    multiset<int>ms;  //�ڲ�������ʱ ֻ���ز������ݵ�λ��
    ms.insert(10);
    ms.insert(10);
    for (multiset<int> ::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


//pair ���鴴��
void test06()
{
    //��һ�ִ�����ʽ
    pair<string, int>p("TOM", 20);
    cout << "������ " << p.first << "���䣺  " << p.second << endl;


    //�ڶ��ִ�����ʽ
    pair<string, int> p2 = make_pair("Jerry", 18);
    cout << "������ " << p2.first << "���䣺  " << p2.second << endl;

}


class Mycompare
{
public:
    bool operator()(const int v1,const int v2)
    {
        return v1 > v2;
    }
};

class Person
{
public:
    Person(string name, int age)
    {
        m_age = age;
        m_name = name;
    }

    string m_name;
    int m_age;
};

class ComparePerson
{
public:
    bool operator ()(const Person& p1, const Person& p2)
    {
        //�������併��
        return p1.m_age > p2.m_age;
    }

};
//set ����
void test07()
{
    //set ���������������
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);

    cout << "��С��������Ϊ��  ";
    Print(s1);  //Ĭ�ϴ�С��������
    
    //������
    ////ָ���������Ϊ�Ӵ�С
    //set<int,Mycompare>s2;
    //s2.insert(10);
    //s2.insert(20);
    //s2.insert(30);
    //s2.insert(40);
    //s2.insert(50);

    //cout << "�Ӵ�С����Ϊ�� ";
    //for (set<int, Mycompare>::iterator it = s2.begin(); it != s2.end(); it++)
    //{
    //    cout << *it << " ";
    //}
 

    //��Ҳ����ͬ����
    ////set ����Զ�����������  Ҫ�Լ�ָ���������
    //set<Person, ComparePerson> s3;
    //Person p1("����", 24);
    //Person p2("����", 28);
    //Person p3("�ŷ�", 25);
    //Person p4("����", 21);
    //s3.insert(p1);
    //s3.insert(p2);
    //s3.insert(p3);
    //s3.insert(p4);

    //for (set<Person, ComparePerson> ::iterator it = s3.begin(); it != s3.end(); it++)
    //{
    //    cout << "������ " << it->m_name << " ���䣺  " << it->m_age << endl;
    //}
}
int main()
{
    //set ��������͸�ֵ
    test01();
    cout << endl << "------------------------------" << endl;

    //set ��С�ͽ���
    test02();
    cout << endl << "------------------------------" << endl;

    //set�����ɾ��
    test03();
    cout << endl << "------------------------------" << endl;

    //set ���Һ�ͳ��
    test04();
    cout << endl << "------------------------------" << endl;

    //set �� multiset ����
    test05();
    cout << endl << "------------------------------" << endl;

    //pair ���鴴��
    test06();
    cout << endl << "------------------------------" << endl;

    //set ����  //��������
    test07();
    cout << endl << "------------------------------" << endl;


    system("pause");
    return 0;
}