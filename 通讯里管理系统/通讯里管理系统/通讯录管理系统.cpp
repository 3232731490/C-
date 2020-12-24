#include<iostream>
#include<string>
using namespace std;

//************************************�˵�����************************************

void showMeau()
{
	cout << "*************************" << endl;
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****5���޸���ϵ��*****" << endl;
	cout << "*****6�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ¼*****" << endl;
	cout << "*************************" << endl;
}

//***************************��ϵ�˽ṹ��*****************************

struct person
{
	string name;     //����
	int m_sex;       //�Ա�1���У�2��Ů
	int m_Age;       //����
	string m_phone;  //�绰
	string m_addr;   //סַ
};

//*******************************ͨѶ¼�ṹ��***********************************

struct addressbooks
{
	person personArray [1000];
	int m_size;      //��¼ͨѶ¼���м�����
};

//*****************************************���ͨѶ¼**************************************

void addperson(addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_size == 1000)
	{
		cout << "ͨѶ¼����..." << endl;
		return;
	}
	else
	{
		//����

		string name;    
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].name = name;
		cout << "�������Ա�" << endl;
		cout << "1����  2��Ů" << endl;
		
		//�Ա�

		int sex = 0;  
		while (true)  
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "������������������..." << endl;
		}
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;
		
		//��ϵ�绰

		cout << "������绰��" << endl;
		string num;
		cin >> num;
		abs->personArray[abs->m_size].m_phone = num;
		
		//סַ

		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;

		//����ͨѶ¼����
		abs->m_size++;
		cout << "��ӳɹ�..." << endl;

		system("pause");
		system("cls");    //��������
	}
}

//*******************************************8��ʾ��ϵ��**************************************

void showperson(addressbooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾΪ��
	if (abs->m_size == 0)
		cout << "��ǰͨѶ¼Ϊ��..." << endl;
	else {
		for (int i = 0; i < abs->m_size; i++)
			cout << "������" << abs->personArray[i].name << '\t'
			     << "�Ա�" << (abs->personArray[i].m_sex==1?"��":"Ů") << '\t'
			     << "���䣺" << abs->personArray[i].m_Age << '\t'
			     << "�绰��" << abs->personArray[i].m_phone << '\t'
			     << "סַ��" << abs->personArray[i].m_addr << endl;
		system("pause");
		system("cls");
	}
}

//�����ϵ���Ƿ���ڣ�������ڣ����ظ���ϵ���������е�λ�ã������ڷ���-1

int isExist(addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].name == name)
			return i;     //�ҵ��� ���������±���
	}
	return -1;  //δ�ҵ�������-1
}


//***********************************ɾ����ϵ��*************************************

void deleteperson(addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	//��ѯ��ϵ�����Ƿ��д���...
    int ret = isExist(abs, name);
	
	if (ret == -1)
		cout << "���޴���" << endl;
	else
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];   //ʹ��Ҫɾ������ϵ�˺����ϵ�˶���ǰ��һλ
		}
		abs->m_size--;    //����ͨѶ¼����...
	}
	system("pause");
	system("cls");
}

//������ϵ��

void findperson(addressbooks* abs )
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);   //�ж���ϵ���Ƿ����ͨѶ¼��
	if (ret == -1)
		cout << "���޴���" << endl;
	else
	{
		cout << "������" << abs->personArray[ret].name << '\t'
			<< "�Ա�" << (abs->personArray[ret].m_sex == 1 ? "��" : "Ů") << '\t'
			<< "���䣺" << abs->personArray[ret].m_Age << '\t'
			<< "�绰��" << abs->personArray[ret].m_phone << '\t'
			<< "סַ��" << abs->personArray[ret].m_addr << endl;
	}
	system("pause");
	system("cls");
}

//********************************�޸���ϵ��*****************************************

void modifyperson(addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret =isExist(abs, name);//�ж�ͨѶ¼���Ƿ��д���
	if (ret == -1)
		cout << "���޴���" << endl;
	
	else
	{
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].name = name;
		
		cout << "�������Ա�" << endl;
		int sex;
		cin >> sex;
		while(true)
		{
			cout << "1����   2��Ů" << endl;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			else cout << "������������������" << endl;
		}
		
		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		
		cout << "��������ϵ�绰��" << endl;
		string num;
		cin >> num;
		abs->personArray[ret].m_phone;
		
		cout << "�������ͥסַ��" << endl;
		string add;
		cin >> add;
		abs->personArray[ret].m_addr = add;
	}
	system("pause");
		system("cls");
}

//***************************�����ϵ��*****************************

void cleanperson(addressbooks* abs)
{
	cout << "���Ƿ����Ҫ���...." << endl;
	cout << "1��  ȷ��    2��   ȡ��" << endl;
	int i;
	cin >> i;
	if (i == 1)
	{
		abs->m_size = 0;    //��ͨѶ¼��Ա������Ϊ0
		cout << "ͨѶ¼�����..." << endl;
	}
	else if(i==2)
	{
		cout << "��ȡ����ղ���..." << endl;
	}
	system("pause");
	system("cls");
}
int main()
{
	//����ͨѶ¼�ṹ�����
	addressbooks abs;
	abs.m_size = 0;
	while (true) 
	{//�˵�����
		showMeau();
		int select = 0;//����һ���û�ѡ������ı���
		cin >> select;
		switch (select)
		{
		case 1: //�����ϵ��
			addperson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://ɾ����ϵ��
    	deleteperson(&abs);
		break;
		case 4://������ϵ��
			findperson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyperson(&abs);
			break;
		case 6://�����ϵ��
			cleanperson( & abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		}
}
	system("pause");
	return 0;
}