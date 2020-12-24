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
		cout << "��������";
		return;
	}
	
	cout << "������Ҫ����ĵ�"<<i<<"���ݣ�" << endl;
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
	cout << "��������Ҫɾ�������ݣ�" << endl;
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
		cout << "δ�ҵ���Ԫ�أ�" << endl;
		return;
	}
	List[pre].next = List[pos].next;
	List[0].data--;
}
void display() {
	if (List[0].next == 0)
	{
		cout << "����Ϊ�գ�" << endl;
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
	cout << "��Ҫ���뼸���ڵ㣺" << endl;
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