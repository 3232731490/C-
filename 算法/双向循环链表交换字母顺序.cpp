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

	//移动之前遍历链表
	for (int i = 0; i < 26; i++)
	{
		p = p->next;
		cout << p->character;
	}
	p = head;
	cout << endl;
	cout << "请输入您要移动几位字母(可以为负值)" << endl;
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
	//移动之后遍历链表
	for (int i = 0; i < 26; i++)
	{
		p = p->next;
		cout << p->character;
	}
	cout << endl;

	//释放空间
	p = head;
	for (int i = 0; i < 26; i++)
	{
		p = p->next;
		delete head;
		head = p;
		cout << "第" << i << "个节点已删除" << endl;
	}
	delete head;
	cout << "最后一个节点已删除" << endl;
	system("pause");
	return 0;
}