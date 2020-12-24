#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
#include<ctime>
#include<numeric>
using namespace std;
//�����㷨
//<algorithm>  �����㷨�࣬��Χ�� 
//<numeric> ���С��ֻ���������������Ͻ��м���ѧ�����ģ�庯��  
//<functional> ������һЩģ���࣬����������������

//���ñ����㷨
//1��  for_each
void func(int v)
{
    cout << v << " ";
}

class print
{
public:
    void operator()(int v)
    {
        cout << v << " ";
    }
};
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }

    for_each(v.begin(), v.end(), func);
    cout << endl;

    //�º���ʵ��
    for_each (v.begin(), v.end(), print());
    cout << endl;
}


class Transform
{
public:
    int operator()(int v)
    {
        return v;
    }
};

void print(int v)
{
    cout << v << " ";
}


//2�� transform 
void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }

    vector<int> vTarget;
    
    //Ŀ��������Ҫ��ǰ���ٿռ�
    vTarget.resize(v.size());

    transform(v.begin(), v.end(), vTarget.begin(), Transform());

    for_each(vTarget.begin(), vTarget.end(), print);
    cout << endl;
}


class Person
{
public:
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }

    //����==���õײ�����֪����ζԱ�
     // �β� ����� const �޶�
    bool operator==(const Person& p)
    {
        if (this->m_name == p.m_name && this->m_age == p.m_age)
            return true;
        else return false;
    }
    string m_name;
    int m_age;
};
//���ò����㷨
//1�� find
void test03()
{
    //����������������
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }


   vector<int>::iterator it= find(v.begin(), v.end(), 5);  //�����������Ƿ���5 ���Ԫ�� �ҵ��ͷ��ص����� û�ҵ�����v.end()

   if (it == v.end())
   {
       cout << "δ�ҵ���Ԫ�أ�" << endl;
   }
   else
   {
       cout << "�ҵ���Ԫ�أ�  " << *it << endl;
   }

    //�����Զ�����������
   vector<Person> v2;
   Person p1("A", 30);
   Person p2("B", 20);
   Person p3("C", 10);
   Person p4("D", 90);

   v2.push_back(p1);
   v2.push_back(p2);
   v2.push_back(p3);
   v2.push_back(p4);

   vector<Person>::iterator p=find(v2.begin(), v2.end(), p2);

   //����==���õײ�����֪����ζԱ�
   if (p==v2.end())
   {
       cout << "δ�ҵ���Ԫ�أ�" << endl;
   }
   else
   {
       cout << "�ҵ���Ԫ�أ�  " << "������ " << p->m_name << " ���䣺 " << p->m_age << endl;
   }
}


class greaterfive
{
public:
    bool operator()(int v)
    {
        return v > 5;
    }

};

class greaterPerson
{
public:
    bool operator()(Person p1)
    {
        return p1.m_age > 20;
    }
};
//2�� find_if
void test04()
{
    //1�� ������������
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }
   vector<int>::iterator it= find_if(v.begin(), v.end(), greaterfive());
   if (it == v.end())
   {
       cout << "δ�ҵ���Ԫ�أ�" << endl;
}
   else
   {
       cout << "�ҵ�����5������ " << *it << endl;
   }


   //�Զ�����������
   vector<Person> v2;
   Person p1("A", 30);
   Person p2("B", 20);
   Person p3("C", 10);
   Person p4("D", 90);

   v2.push_back(p1);
   v2.push_back(p2);
   v2.push_back(p3);
   v2.push_back(p4);

   //���������20����
   vector<Person>::iterator itPerson = find_if(v2.begin(), v2.end(), greaterPerson());

   if (itPerson == v2.end())
   {
       cout << "û���ҵ��������20���ˣ�" << endl;
   }
   else
   {
       cout << "�ҵ����ˣ�" << "���䣺 " << itPerson->m_age << "  ������ " << itPerson->m_name << endl;
   }
}


//3��adjacent_find  ���ڲ��������ظ�����
void test05()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);
    v.push_back(0);
    v.push_back(3);

    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end())
    {
        cout << "δ�ҵ������ظ�Ԫ�أ�" << endl;
    }
    else
    {
        cout << "�ҵ������ظ�Ԫ�أ� " << *it << endl;
    }

}


//4��binary_search  ����ָ��Ԫ�أ��ҵ�����true�� ���� ����false  ���кܸ�Ч
//�����������в���ʹ��
void test06()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }
    
    //������������� ����δ֪

   bool ret= binary_search(v.begin(), v.end(), 3);
   if (ret)
   {
       cout << "�ҵ���Ԫ�أ�" << endl;
   }
   else
   {
       cout << "δ�ҵ���Ԫ�أ�" << endl;
   }
}

class PersonCount
{
public:
    PersonCount(string name, int age)
    {
        m_name = name;
        m_age = age;
    }

    //����==���õײ�����֪����ζԱ�
    // �β� ����� const �޶�
    bool operator==(const PersonCount& p)
    {
        if (this->m_age == p.m_age)
            return true;
        else return false;
    }
    string m_name;
    int m_age;
};
//5�� count
void test07()
{
    //ͳ��������������
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);

   int num= count(v.begin(), v.end(), 40);
   cout << "40 ��Ԫ�ظ���Ϊ ��" << num << endl;
   
   
   //ͳ���Զ�����������
   vector<PersonCount> v2;
   PersonCount p1("A", 30);
   PersonCount p2("B", 30);
   PersonCount p3("C", 30);
   PersonCount p4("D", 35);
   PersonCount p5("E", 40);

   PersonCount p("F", 30);

   v2.push_back(p1);
   v2.push_back(p2);
   v2.push_back(p3);
   v2.push_back(p4);
   v2.push_back(p5);

   int num2= count(v2.begin(), v2.end(), p);

   cout << "����Ϊ 30 ������Ϊ�� " << num2 << endl;
}


class greater20
{
public:
    bool operator()(int v)
    {
        return v > 20;
    }
};
class greaterPerson20
{
public:
    bool operator()(const PersonCount &p)
    {
        return p.m_age > 20;
    }
};
//6�� count_if
void test08()
{
    //������������
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);

    //ͳ�ƴ���20����
    int num=count_if(v.begin(), v.end(), greater20());
    cout << "����20�����У� " << num << " ��" << endl;

    
    //�Զ�����������
    vector<PersonCount> v2;
    PersonCount p1("A", 30);
    PersonCount p2("B", 30);
    PersonCount p3("C", 30);
    PersonCount p4("D", 35);
    PersonCount p5("E", 40);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    v2.push_back(p5);

    //ͳ���������20����
    int num2 = count_if(v2.begin(), v2.end(), greaterPerson20());
    cout << "�������20������ ��" << num2 << "��" << endl;
}

//���������㷨

//1�� sort

void printsort(int v)
{
    cout << v << " ";
}
class f
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
void test09()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(30);
    v.push_back(50);
   
    cout << "�������Ϊ��" << endl;
    for_each(v.begin(), v.end(), printsort);
    cout << endl;

    //Ĭ����������
    sort(v.begin(), v.end());
    cout << "Ĭ������Ϊ��" << endl;
    for_each(v.begin(), v.end(), printsort);
    cout << endl;

    //��������
    sort(v.begin(), v.end(), f());
    //���� ʹ���ڽ��������� ��Ҫ����ͷ�ļ�<functional>
    //sort(v.begin(), v.end(), greater<int>());
    cout << "��������Ϊ��" << endl;
    for_each(v.begin(), v.end(), printsort);
    cout << endl;
}


//2�� random_shuffle  ��������Ԫ���������
void test10()
{
    srand((unsigned int)time(NULL));  //���������
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }
    cout << "����ǰ��" << endl;
    for_each(v.begin(), v.end(), print);
    cout << endl;
    random_shuffle(v.begin(), v.end());
    cout << "���Һ�" << endl;
    for_each(v.begin(), v.end(), print);
}


//3�� merge  
//���������������ϲ���ŵ���һ��������
void test11()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }

    vector<int> vTarget;
    
    //��Ҫ��ǰ���ٿռ�
    vTarget.resize(v1.size() + v2.size());
    
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for (vector<int>::iterator it = vTarget.begin(); it != vTarget.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


//4�� reverse  
//��������Ԫ����λ��ת
void test12()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "��תǰ��" << endl;
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    reverse(v1.begin(), v1.end());
    cout << "��ת��" << endl;
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
}


//���ÿ������滻�㷨

//1�� copy
//������ָ����ΧԪ�ؿ�������һ��������
void test13()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }
    vector<int> v2;
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());
    for_each(v2.begin(), v2.end(), print);
    cout << endl;
}


//2�� replace  
void test14()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }

    cout << "�滻ǰ��  " << endl;
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    replace(v1.begin(), v1.end(), 5, 1000);  //�������е� 5 �滻Ϊ 1000
    cout << "�滻��" << endl;
    for_each(v1.begin(), v1.end(), print);
}


//3�� replace_if 
class greater5
{
public:
    bool operator()(int v)
    {
        return v > 5;
    }
};
void test15()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }

    cout << "�滻ǰ��" << endl;
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    replace_if(v1.begin(), v1.end(), greater5(), 300);  //�������д���5���滻Ϊ300
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
}


//4�� swap  ��������ͬ������
void test16()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }
    cout << "����ǰ�� " << endl;
    cout << "v1: ";
    for_each(v1.begin(), v1.end(), print);
    cout << endl<<"v2: ";
    for_each(v2.begin(), v2.end(), print);
    cout << endl;
    swap(v1, v2);
    cout << endl;
    cout << "������ " << endl;
    cout << "v1: ";
    for_each(v1.begin(), v1.end(), print);
    cout << endl << "v2: ";
    for_each(v2.begin(), v2.end(), print);
    cout << endl;
}


//�������������㷨  �����ͷ�ļ�<numeric>

//1�� accumulate
void test17()
{
    vector<int> v1;
    for (int i = 0; i <= 100; i++)
    {
        v1.push_back(i);
    }
    int num= accumulate(v1.begin(), v1.end(),0);  //0Ϊ��ʼ�ۼ�ֵ 

    cout << "����������Ԫ�صĺ�Ϊ�� " << num << endl;
}


//2�� fill
void test18()
{
    vector<int> v;
    v.resize(10);

    //��ʼ�Զ����0
    for_each(v.begin(), v.end(), print);
    cout << endl;
    
    //�ֶ����10
    fill(v.begin(), v.end(), 10);
    for_each(v.begin(), v.end(), print);
}


//���ü����㷨

//1�� set_intersection   �����������Ľ����������Ŀ��������  
//����������������������
void test19()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> vTarget;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    //Ŀ��������Ҫ���𿪱ٿռ�
    //ȡС�����ռ��ֵ
   // vTarget.resize((v1.size() > v2.size()) ? v2.size() : v1.size());  
    vTarget.resize(min(v1.size(), v2.size()));


    //��ȡ����  
    //���ؽ������һ�����ݵĵ�����
   vector<int>::iterator it= set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

   //Ҫʹ�÷��صĵ���������Ҫʹ��vTarget.end()
   for_each(vTarget.begin(), it, print);

}


//2�� set_union  ���������Ĳ������ŵ�Ŀ��������
void test20()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> vTarget;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vTarget.resize(v1.size() + v2.size());

    //ȡ����  ���ز��������һ�����ݵĵ�����
    vector<int>::iterator it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), it, print);
    cout << endl;

}


//3�� set_difference  ���������ϵĲ�����ص�Ŀ������
void test21()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> vTarget;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vTarget.resize(max(v1.size(), v2.size()));

    //��v1 �� v2 �Ĳ  �������һ�����ݵĵ�����
    cout << "v1 �� v2 �ĲΪ��  " << endl;
    vector<int>::iterator it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), it, print);
    cout << endl;
    
    cout << "v2 �� v1 �ĲΪ��  " << endl;
    vector<int>::iterator it2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
    for_each(vTarget.begin(), it2, print);
    cout << endl;
}
int main()
{
    //���ñ����㷨
    //1�� for_each
    test01();
    cout << endl << "---------------------------" << endl;

    //2 ��transform
    test02();
    cout << endl << "---------------------------" << endl;

    //-----------------------------------------------------------//

    //���ò����㷨
    //1�� find
    test03();
    cout << endl << "---------------------------" << endl;

    //2�� find_if
    test04();
    cout << endl << "---------------------------" << endl;

    //3�� adjacent_find
    test05();
    cout << endl << "---------------------------" << endl;

    //4�� binary_search 
    test06();
    cout << endl << "---------------------------" << endl;

    //5�� count
    test07();
    cout << endl << "---------------------------" << endl;

    //6�� count_if
    test08();
    cout << endl << "---------------------------" << endl;

    //-----------------------------------------------------------//

    //���������㷨
    //1�� sort 
    test09();
    cout << endl << "---------------------------" << endl;

    //2�� random_shuffle
    test10();
    cout << endl << "---------------------------" << endl;

    //3�� merge
    test11();
    cout << endl << "---------------------------" << endl;

    //4�� reverse
    test12();
    cout << endl << "---------------------------" << endl;

    //-----------------------------------------------------------//

    //���ÿ������滻�㷨
    //1�� copy
    test13();
    cout << endl << "---------------------------" << endl;

    //2�� replace
    test14();
    cout << endl << "---------------------------" << endl;

    //3�� replace_if
    test15();
    cout << endl << "---------------------------" << endl;

    //4�� swap
    test16();
    cout << endl << "---------------------------" << endl;

    //-----------------------------------------------------------//
    
    //�������������㷨
    //1�� accumulate
    test17();
    cout << endl << "---------------------------" << endl;

    //2�� fill
    test18();
    cout << endl << "---------------------------" << endl;

    //-----------------------------------------------------------//

    //���ü����㷨
    //1�� set_intersection
    test19();
    cout << endl << "---------------------------" << endl;

    //2�� set_union
    test20();
    cout << endl << "---------------------------" << endl;

    //3�� set_difference
    test21();
    cout << endl << "---------------------------" << endl;

    return 0;
}