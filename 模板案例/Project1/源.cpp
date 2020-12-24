#include<iostream>
#include"MyArray.hpp"
#include<string>
using namespace std;

void printIntArray(MyArray<int> &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//测试内置数据类型
void test01()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.Push_Back(i);
	}
	cout << "array1 的打印输出为：  " << endl;
	printIntArray(array1);
	cout << "array1 的大小：" << array1.getSize() << endl;
	cout << "array1 的容量：" << array1.getCapacity() << endl;
	cout << "-----------------------------------------" << endl;

	MyArray<int> array2(array1);
	array2.Pop_Back();
	cout << "array2 的打印输出：" << endl;
	printIntArray(array2);
	cout << "array2 的大小：" << array2.getSize() << endl;
	cout << "array2 的容量：" << array2.getCapacity() << endl;
}

//测试自定义数据类型
class person
{
public:
	person() {};
	person(string name, int age) :m_age(age), m_name(name) {};


	string m_name;
	int m_age;;
};

void printpersonArray(MyArray<person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：  " << arr[i].m_name << "年龄：  " << arr[i].m_age << endl;
	}
}

void test02()
{
	//创建数组
	MyArray<person> pArray(10);
	person p1("孙悟空", 999);
	person p2("孙悟空", 998);
	person p3("孙悟空", 997);
	person p4("孙悟空", 996);
	person p5("孙悟空", 995);

	//插入数据
	pArray.Push_Back(p1);
	pArray.Push_Back(p2);
	pArray.Push_Back(p3);
	pArray.Push_Back(p4);
	pArray.Push_Back(p5);

	//打印输出
	printpersonArray(pArray);

	cout << "pArray 的大小： " << pArray.getSize() << endl;
	cout << "pArray 的容量：  " << pArray.getCapacity() << endl;
}
int main()
{
	//测试内置数据类型
	test01();
	//测试自定义数据类型
	test02();

	return 0;
}