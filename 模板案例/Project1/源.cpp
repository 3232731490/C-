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

//����������������
void test01()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.Push_Back(i);
	}
	cout << "array1 �Ĵ�ӡ���Ϊ��  " << endl;
	printIntArray(array1);
	cout << "array1 �Ĵ�С��" << array1.getSize() << endl;
	cout << "array1 ��������" << array1.getCapacity() << endl;
	cout << "-----------------------------------------" << endl;

	MyArray<int> array2(array1);
	array2.Pop_Back();
	cout << "array2 �Ĵ�ӡ�����" << endl;
	printIntArray(array2);
	cout << "array2 �Ĵ�С��" << array2.getSize() << endl;
	cout << "array2 ��������" << array2.getCapacity() << endl;
}

//�����Զ�����������
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
		cout << "������  " << arr[i].m_name << "���䣺  " << arr[i].m_age << endl;
	}
}

void test02()
{
	//��������
	MyArray<person> pArray(10);
	person p1("�����", 999);
	person p2("�����", 998);
	person p3("�����", 997);
	person p4("�����", 996);
	person p5("�����", 995);

	//��������
	pArray.Push_Back(p1);
	pArray.Push_Back(p2);
	pArray.Push_Back(p3);
	pArray.Push_Back(p4);
	pArray.Push_Back(p5);

	//��ӡ���
	printpersonArray(pArray);

	cout << "pArray �Ĵ�С�� " << pArray.getSize() << endl;
	cout << "pArray ��������  " << pArray.getCapacity() << endl;
}
int main()
{
	//����������������
	test01();
	//�����Զ�����������
	test02();

	return 0;
}