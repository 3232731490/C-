#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
#include<ctime>
#include<numeric>
using namespace std;
//常用算法
//<algorithm>  包含算法多，范围广 
//<numeric> 体积小，只包括几个在序列上进行简单数学运算的模板函数  
//<functional> 定义了一些模板类，用以声明函数对象

//常用遍历算法
//1、  for_each
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

    //仿函数实现
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


//2、 transform 
void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }

    vector<int> vTarget;
    
    //目标容器需要提前开辟空间
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

    //重载==，让底层数据知道如何对比
     // 形参 必须加 const 限定
    bool operator==(const Person& p)
    {
        if (this->m_name == p.m_name && this->m_age == p.m_age)
            return true;
        else return false;
    }
    string m_name;
    int m_age;
};
//常用查找算法
//1、 find
void test03()
{
    //查找内置数据类型
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }


   vector<int>::iterator it= find(v.begin(), v.end(), 5);  //查找容器中是否有5 这个元素 找到就返回迭代器 没找到返回v.end()

   if (it == v.end())
   {
       cout << "未找到该元素！" << endl;
   }
   else
   {
       cout << "找到该元素：  " << *it << endl;
   }

    //查找自定义数据类型
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

   //重载==，让底层数据知道如何对比
   if (p==v2.end())
   {
       cout << "未找到该元素！" << endl;
   }
   else
   {
       cout << "找到该元素：  " << "姓名： " << p->m_name << " 年龄： " << p->m_age << endl;
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
//2、 find_if
void test04()
{
    //1、 内置数据类型
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }
   vector<int>::iterator it= find_if(v.begin(), v.end(), greaterfive());
   if (it == v.end())
   {
       cout << "未找到该元素！" << endl;
}
   else
   {
       cout << "找到大于5的数： " << *it << endl;
   }


   //自定义数据类型
   vector<Person> v2;
   Person p1("A", 30);
   Person p2("B", 20);
   Person p3("C", 10);
   Person p4("D", 90);

   v2.push_back(p1);
   v2.push_back(p2);
   v2.push_back(p3);
   v2.push_back(p4);

   //找年龄大于20的人
   vector<Person>::iterator itPerson = find_if(v2.begin(), v2.end(), greaterPerson());

   if (itPerson == v2.end())
   {
       cout << "没有找到年龄大于20的人！" << endl;
   }
   else
   {
       cout << "找到该人：" << "年龄： " << itPerson->m_age << "  姓名： " << itPerson->m_name << endl;
   }
}


//3、adjacent_find  用于查找相邻重复数据
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
        cout << "未找到相邻重复元素！" << endl;
    }
    else
    {
        cout << "找到相邻重复元素： " << *it << endl;
    }

}


//4、binary_search  查找指定元素，找到返回true， 否则 返回false  运行很高效
//在无序序列中不可使用
void test06()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }
    
    //如果是无序序列 则结果未知

   bool ret= binary_search(v.begin(), v.end(), 3);
   if (ret)
   {
       cout << "找到该元素！" << endl;
   }
   else
   {
       cout << "未找到该元素！" << endl;
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

    //重载==，让底层数据知道如何对比
    // 形参 必须加 const 限定
    bool operator==(const PersonCount& p)
    {
        if (this->m_age == p.m_age)
            return true;
        else return false;
    }
    string m_name;
    int m_age;
};
//5、 count
void test07()
{
    //统计内置数据类型
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);

   int num= count(v.begin(), v.end(), 40);
   cout << "40 的元素个数为 ：" << num << endl;
   
   
   //统计自定义数据类型
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

   cout << "年龄为 30 的人数为： " << num2 << endl;
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
//6、 count_if
void test08()
{
    //内置数据类型
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);

    //统计大于20的数
    int num=count_if(v.begin(), v.end(), greater20());
    cout << "大于20的数有： " << num << " 个" << endl;

    
    //自定义数据类型
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

    //统计年龄大于20的人
    int num2 = count_if(v2.begin(), v2.end(), greaterPerson20());
    cout << "年龄大于20的人有 ：" << num2 << "个" << endl;
}

//常用排序算法

//1、 sort

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
   
    cout << "最初排序为：" << endl;
    for_each(v.begin(), v.end(), printsort);
    cout << endl;

    //默认升序排列
    sort(v.begin(), v.end());
    cout << "默认排序为：" << endl;
    for_each(v.begin(), v.end(), printsort);
    cout << endl;

    //降序排列
    sort(v.begin(), v.end(), f());
    //或者 使用内建函数对象 需要包含头文件<functional>
    //sort(v.begin(), v.end(), greater<int>());
    cout << "降序排序为：" << endl;
    for_each(v.begin(), v.end(), printsort);
    cout << endl;
}


//2、 random_shuffle  将容器中元素随机打乱
void test10()
{
    srand((unsigned int)time(NULL));  //随机数种子
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }
    cout << "打乱前：" << endl;
    for_each(v.begin(), v.end(), print);
    cout << endl;
    random_shuffle(v.begin(), v.end());
    cout << "打乱后：" << endl;
    for_each(v.begin(), v.end(), print);
}


//3、 merge  
//将两个有序容器合并存放到另一个容器中
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
    
    //需要提前开辟空间
    vTarget.resize(v1.size() + v2.size());
    
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for (vector<int>::iterator it = vTarget.begin(); it != vTarget.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


//4、 reverse  
//将容器中元素首位反转
void test12()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "反转前：" << endl;
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    reverse(v1.begin(), v1.end());
    cout << "反转后：" << endl;
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
}


//常用拷贝和替换算法

//1、 copy
//容器内指定范围元素拷贝到另一个容器中
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


//2、 replace  
void test14()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i + 1);
    }

    cout << "替换前：  " << endl;
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    replace(v1.begin(), v1.end(), 5, 1000);  //将容器中的 5 替换为 1000
    cout << "替换后" << endl;
    for_each(v1.begin(), v1.end(), print);
}


//3、 replace_if 
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

    cout << "替换前：" << endl;
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    replace_if(v1.begin(), v1.end(), greater5(), 300);  //将容器中大于5的替换为300
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
}


//4、 swap  互换两个同种容器
void test16()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }
    cout << "交换前： " << endl;
    cout << "v1: ";
    for_each(v1.begin(), v1.end(), print);
    cout << endl<<"v2: ";
    for_each(v2.begin(), v2.end(), print);
    cout << endl;
    swap(v1, v2);
    cout << endl;
    cout << "交换后： " << endl;
    cout << "v1: ";
    for_each(v1.begin(), v1.end(), print);
    cout << endl << "v2: ";
    for_each(v2.begin(), v2.end(), print);
    cout << endl;
}


//常用算数生成算法  需包含头文件<numeric>

//1、 accumulate
void test17()
{
    vector<int> v1;
    for (int i = 0; i <= 100; i++)
    {
        v1.push_back(i);
    }
    int num= accumulate(v1.begin(), v1.end(),0);  //0为初始累加值 

    cout << "容器中所有元素的和为： " << num << endl;
}


//2、 fill
void test18()
{
    vector<int> v;
    v.resize(10);

    //初始自动填充0
    for_each(v.begin(), v.end(), print);
    cout << endl;
    
    //手动填充10
    fill(v.begin(), v.end(), 10);
    for_each(v.begin(), v.end(), print);
}


//常用集合算法

//1、 set_intersection   求两个容器的交集并存放在目标容器中  
//两个容器必须是有序序列
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

    //目标容器需要提起开辟空间
    //取小容器空间的值
   // vTarget.resize((v1.size() > v2.size()) ? v2.size() : v1.size());  
    vTarget.resize(min(v1.size(), v2.size()));


    //获取交集  
    //返回交集最后一个数据的迭代器
   vector<int>::iterator it= set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

   //要使用返回的迭代器，不要使用vTarget.end()
   for_each(vTarget.begin(), it, print);

}


//2、 set_union  求两容器的并集并放到目标容器中
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

    //取并集  返回并集中最后一个数据的迭代器
    vector<int>::iterator it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), it, print);
    cout << endl;

}


//3、 set_difference  求两个集合的差集并返回到目标容器
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

    //求v1 和 v2 的差集  返回最后一个数据的迭代器
    cout << "v1 和 v2 的差集为：  " << endl;
    vector<int>::iterator it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), it, print);
    cout << endl;
    
    cout << "v2 和 v1 的差集为：  " << endl;
    vector<int>::iterator it2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
    for_each(vTarget.begin(), it2, print);
    cout << endl;
}
int main()
{
    //常用遍历算法
    //1、 for_each
    test01();
    cout << endl << "---------------------------" << endl;

    //2 、transform
    test02();
    cout << endl << "---------------------------" << endl;

    //-----------------------------------------------------------//

    //常用查找算法
    //1、 find
    test03();
    cout << endl << "---------------------------" << endl;

    //2、 find_if
    test04();
    cout << endl << "---------------------------" << endl;

    //3、 adjacent_find
    test05();
    cout << endl << "---------------------------" << endl;

    //4、 binary_search 
    test06();
    cout << endl << "---------------------------" << endl;

    //5、 count
    test07();
    cout << endl << "---------------------------" << endl;

    //6、 count_if
    test08();
    cout << endl << "---------------------------" << endl;

    //-----------------------------------------------------------//

    //常用排序算法
    //1、 sort 
    test09();
    cout << endl << "---------------------------" << endl;

    //2、 random_shuffle
    test10();
    cout << endl << "---------------------------" << endl;

    //3、 merge
    test11();
    cout << endl << "---------------------------" << endl;

    //4、 reverse
    test12();
    cout << endl << "---------------------------" << endl;

    //-----------------------------------------------------------//

    //常用拷贝和替换算法
    //1、 copy
    test13();
    cout << endl << "---------------------------" << endl;

    //2、 replace
    test14();
    cout << endl << "---------------------------" << endl;

    //3、 replace_if
    test15();
    cout << endl << "---------------------------" << endl;

    //4、 swap
    test16();
    cout << endl << "---------------------------" << endl;

    //-----------------------------------------------------------//
    
    //常用算数生成算法
    //1、 accumulate
    test17();
    cout << endl << "---------------------------" << endl;

    //2、 fill
    test18();
    cout << endl << "---------------------------" << endl;

    //-----------------------------------------------------------//

    //常用集合算法
    //1、 set_intersection
    test19();
    cout << endl << "---------------------------" << endl;

    //2、 set_union
    test20();
    cout << endl << "---------------------------" << endl;

    //3、 set_difference
    test21();
    cout << endl << "---------------------------" << endl;

    return 0;
}