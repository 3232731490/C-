#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

//list 容器 （双向循环链表容器）  优点：可以对任意位置进行快速插入和删除元素  采用动态存储，不会有内存浪费
//                                缺点：访问元素速度比数组慢  占用空间大

//打印函数
void PrintList(const list<int>& l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//list  构造函数
void test01()
{
    list<int> l1;

    //添加数据
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


//list 容器的赋值和交换
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


//list 大小操作
void test03()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    PrintList(l1);

    if (!l1.empty())
        cout << "list的大小为：  " << l1.size() << endl;
    else
        cout << "list为空！" << endl;

    //重新指定大小
    l1.resize(10);
    PrintList(l1);

    l1.resize(20, 10);
    PrintList(l1);
}


//list 插入和删除
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

    //尾删
    l1.pop_back();
    
    PrintList(l1);

    //头删
    l1.pop_front();

    PrintList(l1);

    //insert 插入
    l1.insert(l1.begin(), 1000);
    PrintList(l1);

    //erase 删除
    l1.erase(l1.begin());
    PrintList(l1);

    list<int>::iterator it = l1.begin();
    it++;
    l1.insert(it, 10);
    PrintList(l1);

    //移除
    l1.remove(10);  //删除所有的10
    PrintList(l1);

    //清空
    l1.clear();
    PrintList(l1);
}


//list 数据存取  不支持[] 和 at 访问元素 因为链表容器的元素地址不连续 所以迭代器也不支持随机访问
void test05()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    cout << "list容器中第一个元素为：  " << l1.front() << endl;

    cout << "list容器中最后一个元素为：  " << l1.back() << endl;


}

bool myCompare(int v1, int v2)
{
    //降序 就让第一个数> 第二个数
    return v1 > v2;
}

//list 反转和排序
void test06()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(40);
    l1.push_back(30);
    l1.push_back(50);
    PrintList(l1);

    //反转
    l1.reverse();
    PrintList(l1);

    //所有不支持随机访问迭代器的都不支持sort标准算法  如下
    //  sort(l1.begin(),l1.end());
   
    //不支持随机访问迭代器内部会提供一些算法
    //排序
    l1.sort();  //默认排序规则 从小到大
    PrintList(l1);

    //降序排列
    l1.sort(myCompare);
    PrintList(l1);
}
int main()
{
    //构造函数  和之前vector，deque 容器都差不多
    test01();
    cout << endl << "------------------------------------" << endl;

    //list 容器的赋值和交换  和之前容器基本一样
    test02();
    cout << endl << "------------------------------------" << endl;

    //list 大小操作   和之前容器基本一样
    test03();
    cout << endl << "------------------------------------" << endl;

    //list 插入和删除
    test04();
    cout << endl << "------------------------------------" << endl;

    //list 数据存取
    test05();
    cout << endl << "------------------------------------" << endl;

    //list 反转和排序
    test06();
    cout << endl << "------------------------------------" << endl;

    return 0;
}