#include<iostream>
using namespace std;
struct ysf
{
	int num;
	ysf* next;

};

ysf* creatlist(ysf* head, int n)
{
	ysf* p = head;
	for (int i = 0; i < n; i++)
	{
		ysf* temp = new ysf;
		temp->num = i+1;
		p->next = temp;
		p = temp;
	}
	p->next = head->next;
	return head;
}

int game(ysf* head,int n)
{
	ysf* p = head->next;
	int count = 0;  //��¼��̭����
	int i = 0;  //ѭ������
	while (count != n - 1)
	{
		if (p->num != 0)
		{
			i++;
			if (i == 3)
			{
				i = 0;
				cout <<"��"<< p->num << "������" << endl;
				p->num = 0;
				count++;
				
			}
			p = p->next;
		}
		while (p->num == 0)
		{
			p = p->next;
		}
	}
	return p->num;
}
int main()
{
	cout << "�������м���������Լɪ��" << endl;
	int n;
	cin >> n;
	ysf* head = new ysf;
	head = creatlist(head, n);
	int survivepos = game(head, n);
	cout << "��������������ǣ� " << survivepos << endl;

	//�ͷ�new ����������
	ysf* p = head;
	ysf* pre = p;
	for (int i = 0; i < n; i++)
	{
		p = p->next;
		delete pre;
		pre = p;
		cout << "��" << i << "���ڵ���ɾ��" << endl;

	}

	delete pre;
	cout << "���һ���ڵ���ɾ��" << endl;
	system("pause");
	return 0;
}