#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
struct student
{
	int num;
	string name;
	student* next;
};
student *creat()//动态输入链表
{
	student* head ;
	student* p1, * p2;
	p1 = p2 = new student;
	int n=0;
	cout << "请输入学生学号姓名：" << endl;
	cin >> p1->num >> p1->name;
	head = 0;
	while (p1->num != 0)
	{
		cout << "请输入学生学号姓名：" << endl;
		n++;
		if (n == 1)
			head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = new student;
		cin >> p1->num >> p1->name;
	}
	p2->next = 0;
	return (head);
}
void print(student* head)//打印链表的数据
{
	student* p;
	p = head;
	if (head != 0)
	{
		do {
			cout << p->num << p->name << endl;
			p = p->next;
		} while (p != 0);
	}
}
student* del(student* head, int num)
{
	student* p1, * p2;
	p1 =p2= head;
	if (head == 0)
		cout << "此链表为空..." << endl;
	if (num == head->num)
		head = p1->next;
	while (p1->num!= num&&p1->next!=0)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (num = p1->num)
	{
		p2->next = p1->next;
	}
	else cout << "未找到该节点...." << endl;
	return(head);
}
/*不知哪里出了问题
student* insert(student* head, student* stud)
{
	student* p0, * p1, * p2;
	p1 = head;                          //使p1指向第一个结点
	p0 = stud;                          //指向要插入的结点
	if (head == NULL)                    //原来的链表是空表
	{
		head = p0; p0->next = NULL;  //使p0指向的结点作为头结点
	}        
	else
	{
		while ((p0->num > p1->num) && (p1->next != NULL))
		{
			p2 = p1;                       //使p2指向刚才p1指向的结点
			p1 = p1->next;//p1后移一个结点
		}                
		if (p0->num <= p1->num)
		{
			if (head == p1) head = p0;        //插到原来第一个结点之前
			else p2->next = p0;            //插到p2指向的结点之后
			p0->next = p1;
		}
		else
		{
			p1->next = p0; p0->next = 0;  //插到最后的结点之后
		}
	}
	return (head);
}
*/
int main()
{
	student *head= creat();
	print(head);
	int n;
	cout << "输入您要删除的节点：" << endl;
	cin >> n;
	head=del(head, n);
	cout << "删除节点后：" << endl;
	print(head);
	system("pause");
	return 0;
}
