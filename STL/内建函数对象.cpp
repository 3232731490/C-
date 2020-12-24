#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//内建函数对象  包含头文件  #include<functional>

//1、算数仿函数
//功能： 实现四则运算 其中negate (取反仿函数） 是一元运算 其他都是二元运算
//plus(加法），minus（减法），multiplies(乘法)，divides(除法），modulus(取模），negate (取反仿函数）
void test01()
{
    //取反仿函数
    negate<int> n;
    cout << n(50) << endl;

    //plus
    plus<int> p;
    cout<<p(10, 20)<<endl;

}


class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }

};
//2、关系仿函数
//equal_to(等于),not_equal_to(不等于),greater(大于),greater_equal(大于等于),less(小于),less_equal(小于等于)
void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    cout << "排序前：  " << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //降序
   sort(v.begin(), v.end(), MyCompare());
    //或者使用编译器提供的仿函数
   //sort(v.begin(), v.end(), greater<int>());
    cout << "排序后：  " << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


//3、逻辑仿函数
void test03()
{
    //逻辑非  logical_not  逻辑与 logical_and     逻辑或  logical_or
    vector<bool> v;
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);

    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    //利用逻辑非 将容器v 搬运到v2 中 并取反操作
    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
        for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
}
int main()
{
  //1、算术仿函数
    test01();

    //2、关系仿函数
    test02();

    //3、逻辑仿函数
    test03();

    system("pause");
    return 0;
}