#pragma once
#include<iostream>
using namespace std;
template <class T>
class MyArray
{
public:
	//�вι���
	MyArray(int capacity)
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_capacity];
	}
	//��������
	MyArray(const MyArray& a)
	{
		this->m_capacity = a.m_capacity;
		this->m_size = a.m_size;


		//���
		this->pAddress = new T[this->m_capacity];

		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = a.pAddress[i];
		}

	}

	//=���������
	MyArray& operator=(const MyArray& arr)
	{
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
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


	//β�巨

	void Push_Back(const T & val)
	{
		//�ж������Ƿ���ڴ�С
		if (this->m_capacity == this->m_size)
		{
			return;
		}
		this->pAddress[this->m_size] = val; //������ĩβ��������
		this->m_size++;//���������С
	}


	//βɾ��

	void Pop_Back()
	{
		//���û����ʲ������һ��Ԫ�أ����߼�ɾ��
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;
	}

	//ͨ���±귽ʽ��������Ԫ��
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//������������
	int getCapacity()
	{
		return this->m_capacity;
	}

	//���������С
	int getSize()
	{
		return this->m_size;
	}
	//��������
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;  //ָ��ָ��������ٵ���ʵ����
	
	int m_capacity;//��������
	
	int m_size;//�����С
};