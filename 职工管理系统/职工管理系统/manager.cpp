#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Dep = did;
	this->m_name = name;
}//���캯��
void Manager:: m_show_Info()//��ʾ������Ϣ
{
	cout << "ְ����ţ�  " << this->m_ID
		<< "\tְ������:  " << this->m_name
		<< "\tְ����λ:  " << this->getDeptName()
		<< "\tְ��ְ��  ����ϰ彻���������·������Ա��" << endl;
}
 string Manager::getDeptName()//��ȡ��λ����

{
	 return string("����");
}
