#include<iostream>
#include<stack>
#include<algorithm>  //��׼�㷨ͷ�ļ�
using namespace std;

//stack ջ���� �Ƚ���� ��������� ֻ��ջ�����ܱ����ʵ�
void test()
{
	stack<int> s;
	
	//��ջ
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "��ʼջ�Ĵ�С�� " << s.size() << endl;

	//ֻҪջ��Ϊ�գ��鿴ջ��������ִ�г�ջ
	while (!s.empty())
	{
		//�鿴ջ��Ԫ��
		cout << "ջ��Ԫ��  :  " << s.top() << endl;

		//��ջ
		s.pop();
	}

	cout << "����ջ�Ĵ�С�� " << s.size() << endl;
}

int main()
{
	test();
	return 0;
}