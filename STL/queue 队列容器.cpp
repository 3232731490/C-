#include<iostream>
#include<queue>
#include<algorithm>  //��׼�㷨ͷ�ļ�
using namespace std;

//queue �������� �Ƚ��ȳ� ��������� ֻ�ж�ͷ����β�ܱ�������

void test()
{
	queue < int> q;
	
	//���
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	cout << "����������ʼ�Ĵ�СΪ��  " << q.size() << endl;

	while (!q.empty())
	{
		//�鿴��ͷ
		cout << "��ʱ��ͷ�� "<<q.front() << endl;
		
		//�鿴��β
		cout <<"��ʱ��β�� "<< q.back() << endl;
		//����
		q.pop();
	}

	//���д�С
	cout << "�������������Ĵ�СΪ��  " << q.size() << endl;
}

int main()
{
	test();
	return 0;
}