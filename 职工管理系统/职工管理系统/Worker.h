#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include<string>
using namespace std;
class Worker   //�����ְ������
{
public:
	virtual void m_show_Info() = 0;
	virtual string getDeptName() = 0;

	int m_ID;  //ְ�����
	string m_name;   //ְ������
	int m_Dep;//ְ����λ
};
