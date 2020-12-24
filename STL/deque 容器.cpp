#include<iostream>
#include<deque>
#include<algorithm>  //标准算法头文件
using namespace std;

/*
        deque 双端数组  可以对头端和尾端进行插入删除操作  因为其内部有中控器
*/

//打印函数
void print(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//deque 构造函数
void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i + 1);
	}
	print(d1);
	
	deque<int> d2(d1.begin(), d1.end());
	print(d2);

	deque<int> d3(10, 100);
	print(d3);

	deque<int> d4(d3);
	print(d4);
}

//deque 赋值函数
void test02()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i + 1);
	}
	print(d1);

	deque<int> d2;
	d2 = d1;
	print(d2);

	deque<int> d3;
	d3.assign(d1.begin(), d1.end());
	print(d3);

	deque<int> d4;
	d4.assign(10, 100);
	print(d4);
}


//deque 大小操作
void test03()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i + 1);
	}
	print(d1);

	//判断d1是否为空
	if (d1.empty())
	{
		cout << "容器为空 " << endl;
	}
	else
	{
		//d1的大小
		cout << "d1 的大小为： " << d1.size() << endl;

		//重新指定大小
		d1.resize(15);  //比原来长默认用0来填充
		print(d1);

		d1.resize(20, 1);   //比原来长用1来填充
		print(d1);
	}
}


//deque 的插入和删除
void test04()
{
	deque<int> d1;
	d1.push_back(20);//尾插法
	d1.push_back(30);
	d1.push_front(10);//头插法
	d1.push_front(0);
	print(d1);

	d1.pop_back();//尾删法
	print(d1);
	d1.pop_front();//头删法
	print(d1);

	deque<int> d2;
	d2.push_back(20);//尾插法
	d2.push_back(30);
	d2.push_front(10);//头插法
	d2.push_front(0);
	print(d2);

	//insert 插入
	d2.insert(d2.begin(), 1000);  //在开始位置插入1000
	print(d2);

	d2.insert(d2.begin(), 2, 10000); //在开始位置插入两个1000
	print(d2);

	d2.insert(d2.begin(), d1.begin(), d1.end());  //在d2的开始位置插入d1的开始到结尾
	print(d2);

	//删除
	d2.erase(d2.begin());
	print(d2);
	
	d2.erase(d2.begin(), d2.end());// 相当于清除 
	print(d2);

	//清除
	d2.clear();
	print(d2);
}


//deque 数据存取
void test05()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	//通过[]访问元素
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;

	//通过at 来访问元素
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;

	cout << "第一个元素：  " << d1.front() << endl;
	cout << "最后一个元素：  " << d1.back() << endl;
}


//deque 排序
void test06()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	cout << "排序前：  " ;
	print(d1);

	cout << "排序后： " ;
	sort(d1.begin(), d1.end());  //默认升序排序
	print(d1);

}
int main()
{
	//deque 构造函数  与vector 构造函数基本一样
	test01();
	cout <<endl<< "------------------------------------------" << endl<<endl;
	
	//deque 赋值函数  与vector 构造函数基本一样
	test02();
	cout << endl<<"------------------------------------------" << endl<<endl;
	
	//deque 大小操作  与vector 构造函数基本一样
	test03();
	cout << endl<<"------------------------------------------" << endl<<endl;
	
	//deque 的插入和删除
	test04();
	cout << endl << "------------------------------------------" << endl << endl;

	//deque 数据存取
	test05();
	cout << endl << "------------------------------------------" << endl << endl;

	//deque 排序
	test06();
	cout << endl << "------------------------------------------" << endl << endl;

	return 0;
}