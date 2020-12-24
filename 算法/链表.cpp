#include<iostream>
using namespace std;

struct linkNode
{
	int num;
	linkNode* next;

};


//创建链表
linkNode* creatList(linkNode* head, int n)
{
	linkNode* pointer = head;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个节点的数字" << endl;
		linkNode* temp = new linkNode;
		cin >> temp->num;
		pointer->next = temp;
		pointer = temp;
	}
	pointer->next = NULL;
	return head;

}


//在链表中插入数据
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
		cout << "位置不合法" << endl;
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
			cout << "请输入插入的第" << k + 1 << "个数据" << endl;
			cin >> temp->num;
			temp->next = pointer->next;
			pointer->next = temp;
			pointer = temp;
		}
	}
}


//删除节点
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
		cout << "位置不合法" << endl;
		return;
	}
	else if (num > i - pos)
	{
		cout << "删除个数不合法" << endl;
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
			cout << "第" << pos++ << "个节点已删除" << endl;
		}
	}
}
int main()
{
	linkNode* head=new linkNode;
	cout << "请输入您要创建几个节点" << endl;
	int n;
	cin >> n;
	head=creatList(head, n);
	linkNode* p=head->next;
	cout << endl;
	cout << "遍历链表" << endl;
	while (p)
	{
		cout << p->num << " ";
		p = p->next;
	}

	//插入数据
	cout << "请输入您要插入数据的位置和要插入几个数据" << endl;
	int pos, num;
	cin >> pos >> num;
	insertlist(head, pos, num);

	cout << endl;
	p = head->next;
	cout << "插入数据后遍历链表" << endl;
	while (p)
	{
		cout << p->num << " ";
		p = p->next;
	}

	//删除指定数据
	cout << "输入你要删除节点的位置，和个数" << endl;
	int dpos, dnum;
	cin >> dpos >> dnum;
	deletelist(head, dpos, dnum);

	p = head->next;
	cout << endl;
	cout << "删除数据后遍历链表" << endl;
	while (p)
	{
		cout << p->num << " ";
		p = p->next;
	}

	//删除剩余在堆区创建的数据
	linkNode* pre = head;
	p = pre->next;
	int i = 0;
	cout << endl;
	while (p)
	{
		cout << "第" << i++ << "个节点已删除" << endl;
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
	cout << "第" << i++ << "个节点已删除" << endl;
	system("pause");
	return 0;
}