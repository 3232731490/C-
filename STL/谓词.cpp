#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//谓词
//返回值为bool类型的仿函数
//如果operator()接受一个参数，那么叫做一元谓词
//如果operator()接受两个参数，那么叫做二元谓词

class Greater
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }

};

//一元谓词
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }

    //查找容器中有没有大于5的数字
   vector<int>::iterator it= find_if(v.begin(), v.end(), Greater());
   if (it == v.end())
   {
       cout << "未找到大于5的数字" << endl;
 }
   else
   {
       cout << "找到大于5的数" << endl;
   }
}


class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }

};
//二元谓词
void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    cout << "排序前：" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
    cout << "升序排列：" << endl;
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;

    cout << "降序排列： " << endl;
    sort(v.begin(), v.end(),MyCompare());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}
int main()
{
    //一元谓词
    test01();

    cout << endl << "--------------------------" << endl;
    //二元谓词
    test02();

    system("pause");
    return 0;
}