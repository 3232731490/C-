#include<iostream>
#include<deque>
#include<algorithm>  //��׼�㷨ͷ�ļ�
using namespace std;

/*
        deque ˫������  ���Զ�ͷ�˺�β�˽��в���ɾ������  ��Ϊ���ڲ����п���
*/

//��ӡ����
void print(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//deque ���캯��
void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i + 1);
	}
	print(d1);
	
	deque<int> d2(d1.begin(), d1.end());
	print(d2);

	deque<int> d3(10, 100);
	print(d3);

	deque<int> d4(d3);
	print(d4);
}

//deque ��ֵ����
void test02()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i + 1);
	}
	print(d1);

	deque<int> d2;
	d2 = d1;
	print(d2);

	deque<int> d3;
	d3.assign(d1.begin(), d1.end());
	print(d3);

	deque<int> d4;
	d4.assign(10, 100);
	print(d4);
}


//deque ��С����
void test03()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i + 1);
	}
	print(d1);

	//�ж�d1�Ƿ�Ϊ��
	if (d1.empty())
	{
		cout << "����Ϊ�� " << endl;
	}
	else
	{
		//d1�Ĵ�С
		cout << "d1 �Ĵ�СΪ�� " << d1.size() << endl;

		//����ָ����С
		d1.resize(15);  //��ԭ����Ĭ����0�����
		print(d1);

		d1.resize(20, 1);   //��ԭ������1�����
		print(d1);
	}
}


//deque �Ĳ����ɾ��
void test04()
{
	deque<int> d1;
	d1.push_back(20);//β�巨
	d1.push_back(30);
	d1.push_front(10);//ͷ�巨
	d1.push_front(0);
	print(d1);

	d1.pop_back();//βɾ��
	print(d1);
	d1.pop_front();//ͷɾ��
	print(d1);

	deque<int> d2;
	d2.push_back(20);//β�巨
	d2.push_back(30);
	d2.push_front(10);//ͷ�巨
	d2.push_front(0);
	print(d2);

	//insert ����
	d2.insert(d2.begin(), 1000);  //�ڿ�ʼλ�ò���1000
	print(d2);

	d2.insert(d2.begin(), 2, 10000); //�ڿ�ʼλ�ò�������1000
	print(d2);

	d2.insert(d2.begin(), d1.begin(), d1.end());  //��d2�Ŀ�ʼλ�ò���d1�Ŀ�ʼ����β
	print(d2);

	//ɾ��
	d2.erase(d2.begin());
	print(d2);
	
	d2.erase(d2.begin(), d2.end());// �൱����� 
	print(d2);

	//���
	d2.clear();
	print(d2);
}


//deque ���ݴ�ȡ
void test05()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	//ͨ��[]����Ԫ��
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;

	//ͨ��at ������Ԫ��
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;

	cout << "��һ��Ԫ�أ�  " << d1.front() << endl;
	cout << "���һ��Ԫ�أ�  " << d1.back() << endl;
}


//deque ����
void test06()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	cout << "����ǰ��  " ;
	print(d1);

	cout << "����� " ;
	sort(d1.begin(), d1.end());  //Ĭ����������
	print(d1);

}
int main()
{
	//deque ���캯��  ��vector ���캯������һ��
	test01();
	cout <<endl<< "------------------------------------------" << endl<<endl;
	
	//deque ��ֵ����  ��vector ���캯������һ��
	test02();
	cout << endl<<"------------------------------------------" << endl<<endl;
	
	//deque ��С����  ��vector ���캯������һ��
	test03();
	cout << endl<<"------------------------------------------" << endl<<endl;
	
	//deque �Ĳ����ɾ��
	test04();
	cout << endl << "------------------------------------------" << endl << endl;

	//deque ���ݴ�ȡ
	test05();
	cout << endl << "------------------------------------------" << endl << endl;

	//deque ����
	test06();
	cout << endl << "------------------------------------------" << endl << endl;

	return 0;
}