#include"employee.h"
Employee::Employee(int id, string name ,int did)
{
    this->m_ID = id;
    this->m_name = name;
    this->m_Dep = did;
}
void Employee::m_show_Info()//��ʾ������Ϣ
{
    cout << "ְ����ţ�  " << this->m_ID
        << "\tְ������:  " << this->m_name
        << "\tְ����λ:  " << this->getDeptName()
        << "\tְ��ְ��  ��ɾ�����������" << endl;
}
string Employee::getDeptName()//��ȡ��λ����
{
    return string("Ա��");
}