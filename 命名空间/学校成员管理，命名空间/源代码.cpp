#include <iostream>
#include<string>
#include"jiaoyubumen.h"
#include"renshibumen.h"
using namespace std;
int main()
{
	nl1::Student s1;
	nl2::Student s2;
	cout << "���������²��Ŵ����ѧ����Ϣ��" << endl;
	int num1, num2;
	char name1[50], name2[50],addr1[50];
	int age1, sex2, score2;
	cin >> num1 >> name1 >> age1 >> addr1;
	s1.set_student(num1, name1, age1, addr1);
	cout << "������������Ŵ����ѧ����Ϣ��" << endl;
	cin >> num2 >> name2 >> sex2 >> score2;
	s2.set_student(num2, name2, sex2, score2);
	cout << endl;
	cout << "���������������ѧ����Ϣ��" << endl;
	cout << "ѧ�ţ�" << s2.get_num() << endl;
	cout << "������" ;
	char* p = s2.get_name();
	while (*p!= '\0')
	{
		cout << *p;
		p++;
	}
	cout << endl;
	cout << "�Ա�" << ((s2.get_sex() == 1) ? "��" : "Ů") << endl;
	cout << "�ɼ���" << s2.get_score() << endl;
	cout << "������������������������������������������������" << endl;
	cout << "���²����������ѧ����Ϣ��" << endl;
	cout << "ѧ�ţ�" << s1.get_num() << endl;
	cout << "������" ;
	 p = s2.get_name();
	while (*p != '\0')
	{
		cout << *p;
		p++;
	}
	cout << endl;
	cout << "���䣺" << s1.get_age()<< endl;
	cout << "��ַ��" ;
	p = s1.get_addr();
	while (*p != '\0')
	{
		cout << *p;
		p++;
	}
	return 0;
}
