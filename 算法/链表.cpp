#include<iostream>
using namespace std;

struct linkNode
{
	int num;
	linkNode* next;

};


//��������
linkNode* creatList(linkNode* head, int n)
{
	linkNode* pointer = head;
	for (int i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "���ڵ������" << endl;
		linkNode* temp = new linkNode;
		cin >> temp->num;
		pointer->next = temp;
		pointer = temp;
	}
	pointer->next = NULL;
	return head;

}


//�������в�������
void insertlist(linkNode* head, int pos,int num)
{
	linkNode* pointer = head;
	int i = 0;
	while (pointer)
	{
		pointer = pointer->next;
		i++;
	}
	if (pos > i)
	{
		cout << "λ�ò��Ϸ�" << endl;
		return;
	}
	else
	{
		pointer = head;
		for (int j = 0; j < pos-1; j++)
		{
			pointer = pointer->next;
		}
		for (int k = 0; k < num; k++)
		{
			linkNode* temp = new linkNode;
			cout << "���������ĵ�" << k + 1 << "������" << endl;
			cin >> temp->num;
			temp->next = pointer->next;
			pointer->next = temp;
			pointer = temp;
		}
	}
}


//ɾ���ڵ�
void deletelist(linkNode* head, int pos ,int num)
{
	linkNode* pointer = head;
	int i = 0;
	while (pointer)
	{
		pointer = pointer->next;
		i++;
	}
	if (pos >= i)
	{
		cout << "λ�ò��Ϸ�" << endl;
		return;
	}
	else if (num > i - pos)
	{
		cout << "ɾ���������Ϸ�" << endl;
		return;
	}
	else
	{
		pointer = head;
		for (int i = 0; i < pos - 1; i++)
		{
			pointer = pointer->next;
		}
		for (int i = 0; i < num; i++)
		{
			pointer->next = pointer->next->next;
			delete pointer->next;
			cout << "��" << pos++ << "���ڵ���ɾ��" << endl;
		}
	}
}
int main()
{
	linkNode* head=new linkNode;
	cout << "��������Ҫ���������ڵ�" << endl;
	int n;
	cin >> n;
	head=creatList(head, n);
	linkNode* p=head->next;
	cout << endl;
	cout << "��������" << endl;
	while (p)
	{
		cout << p->num << " ";
		p = p->next;
	}

	//��������
	cout << "��������Ҫ�������ݵ�λ�ú�Ҫ���뼸������" << endl;
	int pos, num;
	cin >> pos >> num;
	insertlist(head, pos, num);

	cout << endl;
	p = head->next;
	cout << "�������ݺ��������" << endl;
	while (p)
	{
		cout << p->num << " ";
		p = p->next;
	}

	//ɾ��ָ������
	cout << "������Ҫɾ���ڵ��λ�ã��͸���" << endl;
	int dpos, dnum;
	cin >> dpos >> dnum;
	deletelist(head, dpos, dnum);

	p = head->next;
	cout << endl;
	cout << "ɾ�����ݺ��������" << endl;
	while (p)
	{
		cout << p->num << " ";
		p = p->next;
	}

	//ɾ��ʣ���ڶ�������������
	linkNode* pre = head;
	p = pre->next;
	int i = 0;
	cout << endl;
	while (p)
	{
		cout << "��" << i++ << "���ڵ���ɾ��" << endl;
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
	cout << "��" << i++ << "���ڵ���ɾ��" << endl;
	system("pause");
	return 0;
}