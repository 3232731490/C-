#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include"Worker.h"
#include<fstream>
#define FILNAME "empFile.text"
using namespace std;
class WorkerManger
{

public:
	WorkerManger();

	void exit_system();

	void show_Menu();
	
	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();
	~WorkerManger();

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��ְ��
	void init_Emp();

	//��ʾְ����Ϣ
	void show();

	//����ְ���Ƿ���� ���ڷ���ְ����ţ������ڷ���-1
	int ISExist(int id);

	//ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	//����ļ�
	void clean_File();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
};

