#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

//list ���� ��˫��ѭ������������  �ŵ㣺���Զ�����λ�ý��п��ٲ����ɾ��Ԫ��  ���ö�̬�洢���������ڴ��˷�
//                                ȱ�㣺����Ԫ���ٶȱ�������  ռ�ÿռ��

//��ӡ����
void PrintList(const list<int>& l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//list  ���캯��
void test01()
{
    list<int> l1;

    //�������
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    PrintList(l1);

    list<int> l2(l1.begin(),l1.end());
    PrintList(l2);

    list<int> l3(l2);
    PrintList(l3);

    list<int> l4(10, 1000);
    PrintList(l4);
}


//list �����ĸ�ֵ�ͽ���
void test02()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    PrintList(l1);

    list<int> l2 = l1;
    PrintList(l2);
    
    list<int>l3;
    l3.assign(l2.begin(), l2.end());
    PrintList(l3);

    list<int>l4;
    l4.assign(10, 100);
    PrintList(l4);

    l4.swap(l2);
    PrintList(l2);
    PrintList(l4);
}


//list ��С����
void test03()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    PrintList(l1);

    if (!l1.empty())
        cout << "list�Ĵ�СΪ��  " << l1.size() << endl;
    else
        cout << "listΪ�գ�" << endl;

    //����ָ����С
    l1.resize(10);
    PrintList(l1);

    l1.resize(20, 10);
    PrintList(l1);
}


//list �����ɾ��
void test04()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);
    l1.push_front(400);
    
    PrintList(l1);

    //βɾ
    l1.pop_back();
    
    PrintList(l1);

    //ͷɾ
    l1.pop_front();

    PrintList(l1);

    //insert ����
    l1.insert(l1.begin(), 1000);
    PrintList(l1);

    //erase ɾ��
    l1.erase(l1.begin());
    PrintList(l1);

    list<int>::iterator it = l1.begin();
    it++;
    l1.insert(it, 10);
    PrintList(l1);

    //�Ƴ�
    l1.remove(10);  //ɾ�����е�10
    PrintList(l1);

    //���
    l1.clear();
    PrintList(l1);
}


//list ���ݴ�ȡ  ��֧��[] �� at ����Ԫ�� ��Ϊ����������Ԫ�ص�ַ������ ���Ե�����Ҳ��֧���������
void test05()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    cout << "list�����е�һ��Ԫ��Ϊ��  " << l1.front() << endl;

    cout << "list���������һ��Ԫ��Ϊ��  " << l1.back() << endl;


}

bool myCompare(int v1, int v2)
{
    //���� ���õ�һ����> �ڶ�����
    return v1 > v2;
}

//list ��ת������
void test06()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(40);
    l1.push_back(30);
    l1.push_back(50);
    PrintList(l1);

    //��ת
    l1.reverse();
    PrintList(l1);

    //���в�֧��������ʵ������Ķ���֧��sort��׼�㷨  ����
    //  sort(l1.begin(),l1.end());
   
    //��֧��������ʵ������ڲ����ṩһЩ�㷨
    //����
    l1.sort();  //Ĭ��������� ��С����
    PrintList(l1);

    //��������
    l1.sort(myCompare);
    PrintList(l1);
}
int main()
{
    //���캯��  ��֮ǰvector��deque ���������
    test01();
    cout << endl << "------------------------------------" << endl;

    //list �����ĸ�ֵ�ͽ���  ��֮ǰ��������һ��
    test02();
    cout << endl << "------------------------------------" << endl;

    //list ��С����   ��֮ǰ��������һ��
    test03();
    cout << endl << "------------------------------------" << endl;

    //list �����ɾ��
    test04();
    cout << endl << "------------------------------------" << endl;

    //list ���ݴ�ȡ
    test05();
    cout << endl << "------------------------------------" << endl;

    //list ��ת������
    test06();
    cout << endl << "------------------------------------" << endl;

    return 0;
}