#include<iostream>
#include<vector>
#include<algorithm>//标准算法头文件
#include<string>
using namespace std;
//容器嵌套容器
void test01()
{
	vector<vector<int>> v;

	//创建小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	//向小容器中添加数据
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);  //尾插法插入数据
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	//将小容器添加到大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//通过大容器遍历所有数据
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//(*it)---小容器
		for (vector<int>::iterator t = (*it).begin(); t != (*it).end(); t++)
		{
			cout << (*t) << " ";
		}
		cout << endl;
	}

}
int main()
{
	test01();
	return 0;
}