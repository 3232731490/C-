#include<iostream>
#include<set>
#include<string>
using namespace std;
//set /multiset 再插入数据时自动排好序   底层是二叉树
//set 不允许有重复数  multiset 允许数据重复

void Print(set<int>& s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//set 容器构造和赋值
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(50);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    
    //所有元素自动排序，不允许插入重复值
    Print(s1);

    set<int> s2(s1);
    Print(s2);
}


//set 大小和交换
void test02()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    //判断是否为空
    if (s1.empty())
    {
        cout << "容器为空！" << endl;
    }
    else
    {
        cout << "容器不为空！" << endl;
        cout << "s1的大小为：  " << s1.size() << endl;
    }


    //交换数据
    set<int> s2;
    s2.insert(100);
    s2.insert(200);
    s2.insert(300);
    s2.insert(400);

    cout << "交换前：  " << endl;
    Print(s1);
    Print(s2);


    s1.swap(s2);
    cout << "交换后" << endl;
    Print(s1);
    Print(s2);

}


//set插入和删除
void test03()
{
    set<int> s1;
    
    //插入
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    Print(s1);

    //删除
    s1.erase(s1.begin());  //删除第一个元素
    Print(s1);

    s1.erase(20);  //删除容器中的 20
    Print(s1);

    //清空
    s1.erase(s1.begin(), s1.end());//删除从开始到末尾所有数据
    Print(s1);

    s1.clear();
}


//set 查找和统计
void test04()
{
    //查找
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    set<int> ::iterator it=s1.find(30);
    if (it != s1.end())
    {
        cout << "找到元素:  " ;
        cout << *it << endl;
    }
    else
    {
        cout << "未找到！" << endl;
    }

    //统计
    int num = s1.count(30);//统计 30 的个数
    cout << "30的个数为： " << num << endl;
}


//set 和 multiset 区别
//
void test05()
{
    set<int> s1;

    //set容器 再插入时同时返回插入成功与否
    pair<set<int>::iterator, bool>ret = s1.insert(10);
    if (ret.second)
    {
        cout << "第一次插入成功！" << endl;

    }
    else
    {
        cout << "第一次插入失败" << endl;
    }

    ret=s1.insert(10);
    if (ret.second)
    {
        cout << "第二次插入成功！" << endl;

    }
    else
    {
        cout << "第二次插入失败" << endl;
    }


    multiset<int>ms;  //在插入数据时 只返回插入数据的位置
    ms.insert(10);
    ms.insert(10);
    for (multiset<int> ::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


//pair 对组创建
void test06()
{
    //第一种创建方式
    pair<string, int>p("TOM", 20);
    cout << "姓名： " << p.first << "年龄：  " << p.second << endl;


    //第二种创建方式
    pair<string, int> p2 = make_pair("Jerry", 18);
    cout << "姓名： " << p2.first << "年龄：  " << p2.second << endl;

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
        //按照年龄降序
        return p1.m_age > p2.m_age;
    }

};
//set 排序
void test07()
{
    //set 存放内置数据类型
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);

    cout << "从小到大排序为：  ";
    Print(s1);  //默认从小到大排序
    
    //有问题
    ////指定排序规则为从大到小
    //set<int,Mycompare>s2;
    //s2.insert(10);
    //s2.insert(20);
    //s2.insert(30);
    //s2.insert(40);
    //s2.insert(50);

    //cout << "从大到小排序为： ";
    //for (set<int, Mycompare>::iterator it = s2.begin(); it != s2.end(); it++)
    //{
    //    cout << *it << " ";
    //}
 

    //这也有相同问题
    ////set 存放自定义数据类型  要自己指定排序规则
    //set<Person, ComparePerson> s3;
    //Person p1("刘备", 24);
    //Person p2("关羽", 28);
    //Person p3("张飞", 25);
    //Person p4("赵云", 21);
    //s3.insert(p1);
    //s3.insert(p2);
    //s3.insert(p3);
    //s3.insert(p4);

    //for (set<Person, ComparePerson> ::iterator it = s3.begin(); it != s3.end(); it++)
    //{
    //    cout << "姓名： " << it->m_name << " 年龄：  " << it->m_age << endl;
    //}
}
int main()
{
    //set 容器构造和赋值
    test01();
    cout << endl << "------------------------------" << endl;

    //set 大小和交换
    test02();
    cout << endl << "------------------------------" << endl;

    //set插入和删除
    test03();
    cout << endl << "------------------------------" << endl;

    //set 查找和统计
    test04();
    cout << endl << "------------------------------" << endl;

    //set 和 multiset 区别
    test05();
    cout << endl << "------------------------------" << endl;

    //pair 对组创建
    test06();
    cout << endl << "------------------------------" << endl;

    //set 排序  //存在问题
    test07();
    cout << endl << "------------------------------" << endl;


    system("pause");
    return 0;
}