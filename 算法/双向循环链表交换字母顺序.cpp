#include<iostream>
using namespace std;
struct test
{
	char character;
	test* prinor;
	test* next;
};

test* createList()
{
	char m = 'A';
	test* head = new test;
	test* p = head;
	for (int i = 0; i < 26; i++)
	{
		test* temp = new test;
		p->next = temp;
		temp->character = m++;
		temp->prinor = p;
		p = temp;
	}
	p->next = head;
	head->prinor = p;
	return head;
}
int main()
{
	test* head=createList();
	test* p = head;

	//�ƶ�֮ǰ��������
	for (int i = 0; i < 26; i++)
	{
		p = p->next;
		cout << p->character;
	}
	p = head;
	cout << endl;
	cout << "��������Ҫ�ƶ���λ��ĸ(����Ϊ��ֵ)" << endl;
	int n;
	cin >> n;

	if (n < 0)
	{
		n = -n;
		for (int i = 0; i < n; i++)
		{
			p = p->prinor;
		}
	
		p->prinor->next = head;
		head->prinor->next = head->next;
		head->next->prinor = head->prinor;
		head->next = p;
		head->prinor = p->prinor;

		p->prinor = head;
	}
	else if(n>0)
	{
		for (int i = 0; i < n; i++)
		{
			p = p->next;
		}
		head->prinor->next = head->next;
		head->next = p->next;
		p->next->prinor = head;
		head->prinor = p;
		p->next = head;
	}

	p = head;
	//�ƶ�֮���������
	for (int i = 0; i < 26; i++)
	{
		p = p->next;
		cout << p->character;
	}
	cout << endl;

	//�ͷſռ�
	p = head;
	for (int i = 0; i < 26; i++)
	{
		p = p->next;
		delete head;
		head = p;
		cout << "��" << i << "���ڵ���ɾ��" << endl;
	}
	delete head;
	cout << "���һ���ڵ���ɾ��" << endl;
	system("pause");
	return 0;
}