#include<iostream>
#include<string>
#include<fstream>
#include"workerManager.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
using namespace std;
int main()
{
	WorkerManger wm;
	int choice = 0;
	while (true)
	{
		wm.show_Menu();         //չʾ�˵�
		cout << "����������ѡ��  " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:   //�˳�ϵͳ
			wm.exit_system();
			break;
		case 1:  //����ְ��
			wm.Add_Emp();
			break;
		case 2:  //��ʾְ��
			wm.show();
			break;
		case 3:  //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4:  //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5:  //����ְ��
			wm.Find_Emp();
			break;
		case 6:  //����ְ��
			wm.Sort_Emp();
			break;
		case 7:  //���ְ��
			wm.clean_File();
			break;

		}
	}
	return 0;
}