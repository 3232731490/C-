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
	int count = 0;  //记录淘汰人数
	int i = 0;  //循环报数
	while (count != n - 1)
	{
		if (p->num != 0)
		{
			i++;
			if (i == 3)
			{
				i = 0;
				cout <<"第"<< p->num << "号死了" << endl;
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
	cout << "请输入有几个人在玩约瑟夫" << endl;
	int n;
	cin >> n;
	ysf* head = new ysf;
	head = creatlist(head, n);
	int survivepos = game(head, n);
	cout << "最后存活下来的人是： " << survivepos << endl;

	//释放new 出来的数据
	ysf* p = head;
	ysf* pre = p;
	for (int i = 0; i < n; i++)
	{
		p = p->next;
		delete pre;
		pre = p;
		cout << "第" << i << "个节点已删除" << endl;

	}

	delete pre;
	cout << "最后一个节点已删除" << endl;
	system("pause");
	return 0;
}