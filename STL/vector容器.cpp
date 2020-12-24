#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
vector 与数组十分类似，被称为 单端数组
vector与普通数组区别 vector1可以动态扩展
vector动态扩展并不是在原有空间后续接新空间，而是找更大的内存空间，然后将原数据拷贝进新空间，释放原空间
vector容器的迭代器是支持随机访问的迭代器
*/


//打印函数
void print(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


//vector的构造函数
void test01()
{
	vector <int> v1;// 默认构造

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);//尾插法插入数据
	}
	print(v1);  //打印vector里的数据

	//通过区间方式进行构造
	vector<int> v2(v1.begin(), v1.end());  //将v1中区间[v1.begin(),v1.end())中数据赋给v2
	print(v2);  //打印vector里的数据

	//n个Elam方式构造
	vector<int> v3(10, 100); //给v3 赋10个100
	print(v3);  //打印vector里的数据

	//拷贝构造
	vector<int> v4(v3);
	print(v4);  //打印vector里的数据
}


//vector的赋值
void test02()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	print(v1);

	//赋值
	vector<int> v2 = v1;  //直接 = 赋值
	print(v2);
	
	vector<int> v3;
	v3.assign(v1.begin(), v1.end()); //将v1中区间[v1.begin(),v1.end())中数据赋给v3
	print(v3);

	vector<int> v4;
	v4.assign(10, 100); //给v4 赋10个100
	print(v4);
}


//vector 的容量和大小
void test03()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	print(v1);

	if (v1.empty())  //为真，代表容器为空
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空" << endl;
	}

	cout<<"vector的容量：  "<<v1.capacity()<<endl;//vector的容量；
	cout<<"vector的大小：  " << v1.size()<<endl; //vector的大小；
	v1.resize(15); //重新指定大小  如果指定的比原来长了，默认以0填充
	print(v1);
	v1.resize(20, 100);//重新指定大小  如果指定的比原来长了，则以100填充
	print(v1);
	v1.resize(10);// 重新指定大小  如果指定的比原来短了，超出部分删除
	print(v1);
}


//vector的插入和删除
void test04()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	print(v1);

	v1.pop_back();//尾删法 删除尾部的一个数据
	print(v1);

	//插入
	v1.insert(v1.begin(), 100);//第一个参数是迭代器 在起始数据前插入100
	print(v1);

	v1.insert(v1.begin(), 2, 1000);//在起始数据前插入；两个1000
	print(v1);

	//删除
	v1.erase(v1.begin());//参数是迭代器 删除起始的第一个数据
	print(v1);

	//清空
	v1.erase(v1.begin(), v1.end()); //删除区间[v1.begin(),v1.end())间的所有数据 即清空
	print(v1);
	
	v1.clear();
}


//vector 数据存取
void test05()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i]<<" "; //利用[]访问容器内元素
	}
	cout << endl;

	//利用at 访问元素
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " "; //利用at访问容器内元素
	}
	cout << endl;

	//获取第一个元素
	cout << "第一个元素为： " << v1.front() << endl;

	//获取最后一个元素
	cout << "最后一个元素为：  " << v1.back() << endl;
}


//vector互换容器
//实现元素内元素互换
void test06()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	cout << " 交换前："<<endl;
	cout << "v1: ";
	print(v1);

	vector<int> v2;
	for (int i = 10; i >0; i--)
	{
		v2.push_back(i);
	}
	cout << "v2: ";
	print(v2);
	v1.swap(v2);  //将v1,v2数据交换
	cout << "v1与v2交换后： "<<endl;
	cout << "v1: ";
	print(v1);
	cout << "v2: ";
	print(v2);


	//该函数的实际用途
	//巧用swap来收缩内存
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i + 1);
	}
	cout << "v的容量：  " << v.capacity() << endl;//vector的容量； //容量大于100000
	cout << "的大小：  " << v.size() << endl; //vector的大小；  大小此时为100000 
	
	v.resize(3);  //将容器大小重新指定为3，但容器容量仍然大于100000，造成空间浪费
	
	cout << "vector的容量：  " << v.capacity() << endl;//vector的容量； //容量大于100000
	cout << "vector的大小：  " << v.size() << endl; //vector的大小；  大小此时为3
	
	//巧用swap来收缩内存
	vector<int>(v).swap(v);//创建一个匿名对象，并用现在v的大小赋值给它，然后再与v进行交换，实现内存收缩
	
	cout << "vector的容量：  " << v.capacity() << endl;
	cout << "vector的大小：  " << v.size() << endl;
}


//vector 预留空间
//减少vector在动态扩展时的扩展次数
void test07()
{

	int num = 0;//统计在给容器插入数据时容器总共开辟空间的次数
	int* p = NULL;
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i + 1);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num= " << num << endl; //num=30,即开辟了30次内存  （动态扩展了30次）


	//利用reserve来预留空间，减少开辟内存次数
	vector<int> v1;
	
	v1.reserve(100000);  //给容器预留出100000的空间

	int num1 = 0;//统计在给容器插入数据时容器总共开辟空间的次数
	int* p1 = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i + 1);
		if (p1 != &v[0])
		{
			p1 = &v[0];
			num1++;
		}
	}
	cout << "num1= " << num1 << endl; //num=1,即只开辟一次空间
}

int main()
{
	//vector构造函数
	test01();

	//vector的赋值
	test02();

	//vector 的容量和大小
	test03();

	//vector的插入和删除
	test04();

	//vector 数据存取
	test05();

	//vector互换容器
	test06();

	//vector 预留空间
	test07();

	return 0;
}