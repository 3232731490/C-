#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;

class Manager :public Worker
{
public:
	Manager(int id, string, int);
	virtual void m_show_Info();//��ʾ������Ϣ
	virtual string getDeptName();//��ȡ��λ����
};