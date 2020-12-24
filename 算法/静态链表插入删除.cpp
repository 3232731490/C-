#include<iostream>
using namespace std;
#define Maxmize 100

struct Node {
	int data;
	int next;
};
Node List[Maxmize];

void initList() {
	List[0].next = 0;
	List[0].data = 0;
	for (int i = 1; i < Maxmize; i++)
	{
		List[i].next = i + 1;
	}
	List[Maxmize - 1].next = 0;
}

void insert(int i) {
	if (List[1].next == 0) {
		cout << "链表已满";
		return;
	}
	
	cout << "输入您要插入的第"<<i<<"数据：" << endl;
	int temp;
	cin >> temp;

	int pos = List[1].next;
	List[1].next = List[pos].next;

	List[pos].next = List[0].next;
	List[0].next = pos;
	List[pos].data = temp;
	List[0].data++;
}

void Delete() {
	cout << "请输入您要删除得数据：" << endl;
	int temp;
	cin >> temp;
	int pre,num=0;
	int pos = List[0].next;
	while (pos != 0&&List[pos].data!=temp)
	{
		num++;
		pre = pos;
		pos = List[pos].next;
	}
	if (num >= List[0].data)
	{
		cout << "未找到该元素！" << endl;
		return;
	}
	List[pre].next = List[pos].next;
	List[0].data--;
}
void display() {
	if (List[0].next == 0)
	{
		cout << "链表为空！" << endl;
		return;
	}
	int pos = 0;
	for (int i = 0; i < List[0].data; i++)
	{
		cout << List[List[pos].next].data << " ";
		pos = List[pos].next;
	}
	cout << endl;
}
int main() {
	initList();
	cout << "您要插入几个节点：" << endl;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		insert(i+1);
	}
	display();
	Delete();
	display();
	system("pause");
	return 0;
}