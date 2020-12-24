#include<iostream>
#include<list>
#include<algorithm>
#include<string>
using namespace std;

//list容器 排序案例 对于自定义数据类型做排序
//按照年龄进行升序  颗年龄相同则按升高做降序
class Person
{
public:
    Person(string name, int age, int height) :m_name(name), m_age(age), m_height(height) {};

    string m_name; // 姓名
    int m_age;   //年龄
    int m_height;  //身高
};

//指定排序规则
bool myCompare1(Person &p1, Person &p2)
{
    //按照年龄进行升序
    if (p1.m_age == p2.m_age)
    {
        //按照身高进行降序排列
        return p1.m_height > p2.m_height;
    }
    return p1.m_age < p2.m_age;

}

void test01()
{
    list <Person> l;  //创建容器

    //准备数据
    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 190);
    Person p4("赵云", 25, 170);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    //插入数据
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);
    cout << "排序前：" << endl;
    for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "姓名： " << (*it).m_name << "年龄：  " << (*it).m_age << "身高：  " << (*it).m_height << endl;
    }

    cout << "-----------------------------------" << endl;
    //排序
    cout << "排序后：" << endl;
    l.sort(myCompare1);
    for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "姓名： " << (*it).m_name << "年龄：  " << (*it).m_age << "身高：  " << (*it).m_height << endl;
    }

}
int main()
{
    test01();

    return 0;
}