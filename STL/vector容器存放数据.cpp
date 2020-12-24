#include<iostream>
#include<vector>
#include<algorithm>//标准算法头文件
#include<string>
using namespace std;

//vector存放内置数据类型
void MyPrint(int val)
{
	cout << val << endl;
}
void test01()
{
	vector<int> v;  //创建一个vector容器，相当于一个数组 
	v.push_back(10);//尾插法插入数据
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//遍历容器中的数据
	//第一种方法
	vector<int>::iterator itbegin = v.begin();  //起始迭代器  指向容器中第一个数据
	vector<int>::iterator itEnd = v.end();   //结束迭代器  指向容器中最后一个数据的下一个位置
	while (itbegin != itEnd)
	{
		cout << *itbegin << endl;
		itbegin++;
	}
	cout << "-------------------------------------"<<endl;
	
	//第二种方法
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "-------------------------------------" << endl;
	
	//第三种方法
	//STL提供的遍历算法
	for_each(v.begin(), v.end(), MyPrint);
}


//vector存放自定义数据类型
class person
{
public:
	person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};

void test02()
{
	vector<person> v;
	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);

	//向容器中插入数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//遍历容器中的数据
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << (*it).m_name << "  年龄：  " << (*it).m_age << endl;
		//cout << "姓名： " << it->m_name << "  年龄：  " << it->m_age << endl;
	}
}

//存放自定义类型的指针
void test03()
{
	vector<person*> v;
	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);

	//向容器中插入数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	//遍历容器中的数据
	for (vector<person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << (*it)->m_name << "  年龄：  " << (*it)->m_age << endl;
		//cout << "姓名： " << (*it)->m_name << "  年龄：  " << (*it)->m_age << endl;
	}

}
int main()
{
	test01();
	test02();
	test03();
	return 0;
}