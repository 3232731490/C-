#include"workerManager.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"

WorkerManger::WorkerManger()
{
	//1���ļ�������
	//��ʼ��
	ifstream ifs;
	ifs.open(FILNAME, ios::in);
	if (!ifs.is_open())
	{
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = 0;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//2���ļ����ڣ�������Ϊ��
	
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = 0;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//3���ļ������Ҳ�Ϊ��,���Ҽ�¼����

	int num = this->get_EmpNum();  //��ȡ����ְ������
		this->m_EmpNum = num;
		
		//���ٿռ�
		this->m_EmpArray = new Worker * [this->m_EmpNum];
	
		//���ļ��е����ݴ浽������
		this->init_Emp();
}
void WorkerManger::show_Menu()
{
	cout << "**************************************************" << endl;
	cout << "**************��ӭʹ��ְ������ϵͳ****************" << endl;
	cout << "**************0���˳�����ϵͳ*********************" << endl;
	cout << "**************1������ְ����Ϣ*********************" << endl;
	cout << "**************2����ʾְ����Ϣ*********************" << endl;
	cout << "**************3��ɾ��ְ����Ϣ*********************" << endl;
	cout << "**************4���޸�ְ����Ϣ*********************" << endl;
	cout << "**************5������ְ����Ϣ*********************" << endl;
	cout << "**************6�����ձ������*********************" << endl;
	cout << "**************7����������ĵ�*********************" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}
WorkerManger::~WorkerManger()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
	}
}
void WorkerManger::exit_system()
{
	cout << "��ӭ�´�ʹ�ã�  " << endl;
	system("pause");
	exit(0);//  �˳�����
}

//���ְ��
void  WorkerManger::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//��������µĿռ��С
		int newsize = this->m_EmpNum + addNum;
		//�����¿ռ�
		Worker** newspace=new Worker* [newsize];

		//��ԭ���ռ������ݿ������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��
			cout << "�������" << i + 1 << "����ְ����ţ� " << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ�������� " << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;  //����һ������ָ�룬���ڶ�ָ̬��������
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name,2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			}
			//��������ְ��ָ�뱣�浽������
			newspace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�еĿռ�
		delete[]this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newspace;
		//������ְ������
		this->m_EmpNum = newsize;
		//�����ļ���Ϊ�յı�־
		this->m_FileIsEmpty = false;
		//��ʾ�ɹ����
		cout << "�ɹ����" << addNum << "����Ա��" << endl;

		//�������ݵ��ļ���
		this->save();
	}
	else 
	{
		cout << "��������..." << endl;
	}
	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManger::save()
{
	ofstream ofs(FILNAME,ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)//��ְ��д���ļ�
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_Dep << " "<<endl;
	}
//�ر��ļ�
	ofs.close();
}
//ͳ���ļ�������
int  WorkerManger::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILNAME, ios::in);
	int id; string name; int did;
	int num = 0;//ͳ������
	while (ifs >> id && ifs >> name && ifs >> did)//������ְ������ȡ����˳�ѭ��
	{
		num++;
	}
	ifs.close();
	return num;
}
//��ʼ��ְ��
void WorkerManger::init_Emp()
{
	ifstream ifs;
	ifs.open(FILNAME);
	
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL; //����һ������ָ�룬���ڶ�ָ̬��������

		if (did == 1)//��ְͨ��
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)//����
		{
			worker = new Manager(id, name, did);
		}
		else //�ϰ�
		{
			worker =new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;

	}
	ifs.close();//�ر��ļ�
}

//��ʾְ����Ϣ
void WorkerManger::show()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->m_show_Info();
		}
	}
	system("pause");
	system("cls");
}

//����ְ���Ƿ����
int WorkerManger::ISExist(int ID)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (ID == this->m_EmpArray[i]->m_ID)
		{
			index = i;
			break;
		}
	}
	return index;
}

//ɾ��ְ��
void WorkerManger::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��������Ҫɾ����ְ����" << endl;
		int ID;
		cin >> ID;
		int index = this->ISExist(ID);
		if (index== -1)  
		{
			cout << "��ְ��������" << endl;
			return;
		}
		else
		{
			//����ǰ��
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//���������¼����Ա����
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManger::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else 
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;
		int ret = this->ISExist(id);
		if(ret!=-1)
		{
		//���ҵ��ñ�ŵ�ְ��

			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dselect = 0;
			cout << "�鵽�� " << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newId;
			cout << "��������������" << endl;
			cin >> newName;
			cout << "�������µĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dselect;
			Worker* worker=NULL;  //����һ������ָ�룬���ڶ�ָ̬��������
			switch (dselect)
			{
			case 1:
				worker = new Employee(newId, newName, dselect);
					break;
			case 2:
				worker = new Manager(newId, newName, dselect);
				break;
			case 3:
				worker = new Boss(newId, newName, dselect);
				break;
			}
			this->m_EmpArray[ret] = worker;
			delete worker;
			cout << "�޸ĳɹ�" << endl;
			this->save();//���浽�ļ���
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManger::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1����ְ����Ų��ң�" << endl;
		cout << "2����ְ���������ң�" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//���ձ�Ų�
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			int ret = this->ISExist(id);
			if(ret != -1)
			{
				//�ҵ�ְ��
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->m_show_Info();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			//����������
			cout << "��������Ҫ����ְ��������" << endl;
			string name;
			cin >> name;
			bool flag=false;//  �ж��Ƿ�鵽�ı�־��Ĭ��δ�ҵ�
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" <<this->m_EmpArray[i]->m_ID<<"��ְ����Ϣ���£�"<< endl;
					this->m_EmpArray[i]->m_show_Info();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
		}
		}
		else
		{
			cout << "������ı������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManger::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ���������У�" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "1����ְ���Ž��н���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int min0rMax = i;  //�������ֵ����Сֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[min0rMax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						min0rMax = j;
					}
				}
				else //����
				{
					if (this->m_EmpArray[min0rMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						min0rMax = j;
					}
				}
			}
			if (i != min0rMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[min0rMax];
				this->m_EmpArray[min0rMax] = temp;
		    }
		}
		cout << "����ɹ������������Ľ��Ϊ��" << endl;
		this->save();  //�������Ľ���������ļ���
		this->show();  //չʾ������ְ��
	}
}

//����ļ�
void WorkerManger::clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILNAME, ios::trunc);
		ofs.close();

		//ɾ��������ÿ��ְ������
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}

		//ɾ����������ָ��
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		cout << "��ճɹ�!" << endl;
	}
	system("pause");
	system("cls");
}