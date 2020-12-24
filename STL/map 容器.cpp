#include<iostream>
#include<map>
#include<string>
using namespace std;
//map 中所有元素都是pair  
//pair 第一个元素为key 起到索引作用， 第二个元素为value(实值)
//所有元素都会根据key值自动排序
//属于关联式容器 底层结构由二叉树实现
//优点：  可以根据key值快速找到value 值
//multimap 可以允许重复值 /map不允许有重复值

void Printmap(map<int, int>& m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key 值：" << it->first << " value 值：  " << it->second << endl;
    }
    cout << endl;
}

//map 构造和赋值
void test01()
{
    //创建map 容器
    map<int,int> m;

    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));

    Printmap(m);


    map<int, int> m2(m);
    Printmap(m2);


    map<int, int> m3;
    m3 = m2;
    Printmap(m3);
}


//map 大小和交换
void test02()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(4, 40));

    if (m1.empty())
    {
        cout << "m1 为空！" << endl;
    }
    else
    {
        cout << "m1 不为空！" << endl;
        cout << "m1 的大小为：  " << m1.size() << endl;
    }

    map<int, int> m2;
    m2.insert(pair<int, int>(5, 100));
    m2.insert(pair<int, int>(6, 200));
    m2.insert(pair<int, int>(7, 300));
    m2.insert(pair<int, int>(8, 400));
    
    cout << "m1 m2 交换前：  " << endl;
    Printmap(m1);
    Printmap(m2);


    m1.swap(m2);
    cout << "m1 m2 交换后：  " << endl;
    Printmap(m1);
    Printmap(m2);

}


//map 插入和删除
void test03()
{
    map<int, int> m1;
  //插入
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    
    m1.insert(make_pair(3, 30));
    
    m1.insert(map<int,int>::value_type(4,40));


    //不太建议用这个方式插入数据
    //可以利用这个方式利用key访问value
    m1[5] = 50;

    Printmap(m1);

    //删除
    m1.erase(m1.begin());
    Printmap(m1);

    m1.erase(3); //删除key值为3的数据
    Printmap(m1);

    //清空
    m1.erase(m1.begin(), m1.end());

    m1.clear();
    Printmap(m1);
}


//map 查找和统计
void test04()
{
    //查找
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(4, 40));
    
    map<int,int>::iterator it=m1.find(3);
    if (it != m1.end())
    {
        cout << "找到元素:  key= " << (*it).first << "     vaule= " << (*it).second << endl;
    }
    else
    {
        cout << "未找到元素！" << endl;
    }

    //统计
    int num=m1.count(3);
    cout << "num =  " << num << endl;
}


class mycompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }

};
//map  容器排序
void test05()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(4, 40));
    m1.insert(pair<int, int>(5, 50));
   
    //默认 升序排序
    Printmap(m1);

    //还是有问题  和set 容器的问题一样
    //map<int, int,mycompare> m2;
    //m2.insert(pair<int, int>(5, 100));
    //m2.insert(pair<int, int>(6, 200));
    //m2.insert(pair<int, int>(7, 300));
    //m2.insert(pair<int, int>(8, 400));

    //    for (map<int, int, mycompare>::iterator it = m2.begin(); it != m2.end(); it++)
    //    {
    //        cout << "key 值：" << it->first << " value 值：  " << it->second << endl;
    //    }
    //    cout << endl;
   

}
int main()
{
    //map 构造和赋值
    test01();
    cout << endl << "-----------------------------" << endl;

    //map 大小和交换
    test02();
    cout << endl << "-----------------------------" << endl;

    //map 插入和删除
    test03();
    cout << endl << "-----------------------------" << endl;

    //map 查找和统计
    test04();
    cout << endl << "-----------------------------" << endl;

    //map  容器排序
    test05();
    cout << endl << "-----------------------------" << endl;

    system("pause");
    return 0;
}