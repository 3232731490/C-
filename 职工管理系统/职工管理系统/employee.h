#pragma once
#include"Worker.h"
#include<iostream>
using namespace std;

class Employee :public Worker
{
public:
	Employee(int id,string name ,int did);//���캯��
	virtual void m_show_Info();//��ʾ������Ϣ
	virtual string getDeptName();//��ȡ��λ����

};