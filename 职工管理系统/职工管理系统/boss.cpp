#include"boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Dep = did;
	this->m_name = name;
}//���캯��
void Boss::m_show_Info()//��ʾ������Ϣ
{
	cout << "ְ����ţ�  " << this->m_ID
		<< "\tְ������:  " << this->m_name
		<< "\tְ����λ:  " << this->getDeptName()
		<< "\tְ��ְ�� ����˾��������" << endl;
}
string Boss::getDeptName()//��ȡ��λ����

{
	return string("�ϰ�");
}
