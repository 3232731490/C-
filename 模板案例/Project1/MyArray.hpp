#pragma once
#include<iostream>
using namespace std;
template <class T>
class MyArray
{
public:
	//有参构造
	MyArray(int capacity)
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_capacity];
	}
	//拷贝构造
	MyArray(const MyArray& a)
	{
		this->m_capacity = a.m_capacity;
		this->m_size = a.m_size;


		//深拷贝
		this->pAddress = new T[this->m_capacity];

		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = a.pAddress[i];
		}

	}

	//=运算符重载
	MyArray& operator=(const MyArray& arr)
	{
		//先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
			this->m_size = 0;
			this->m_capacity = 0;
		}
		this->m_size = arr.m_size;
		this->m_capacity = arr.m_capacity;
		this->pAddress = new MyArray[arr.m_capacity];
			for (int i = 0; i <this->m_size; i++)
			{
				this->pAddress[i] = arr.pAddress[i];
			}
			return *this;
	}


	//尾插法

	void Push_Back(const T & val)
	{
		//判断容量是否等于大小
		if (this->m_capacity == this->m_size)
		{
			return;
		}
		this->pAddress[this->m_size] = val; //在数组末尾插入数据
		this->m_size++;//更新数组大小
	}


	//尾删法

	void Pop_Back()
	{
		//让用户访问不到最后一个元素，即逻辑删除
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;
	}

	//通过下标方式访问数组元素
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity()
	{
		return this->m_capacity;
	}

	//返回数组大小
	int getSize()
	{
		return this->m_size;
	}
	//析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;  //指针指向堆区开辟的真实数组
	
	int m_capacity;//数组容量
	
	int m_size;//数组大小
};