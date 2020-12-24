#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
vector ������ʮ�����ƣ�����Ϊ ��������
vector����ͨ�������� vector1���Զ�̬��չ
vector��̬��չ��������ԭ�пռ�������¿ռ䣬�����Ҹ�����ڴ�ռ䣬Ȼ��ԭ���ݿ������¿ռ䣬�ͷ�ԭ�ռ�
vector�����ĵ�������֧��������ʵĵ�����
*/


//��ӡ����
void print(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


//vector�Ĺ��캯��
void test01()
{
	vector <int> v1;// Ĭ�Ϲ���

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);//β�巨��������
	}
	print(v1);  //��ӡvector�������

	//ͨ�����䷽ʽ���й���
	vector<int> v2(v1.begin(), v1.end());  //��v1������[v1.begin(),v1.end())�����ݸ���v2
	print(v2);  //��ӡvector�������

	//n��Elam��ʽ����
	vector<int> v3(10, 100); //��v3 ��10��100
	print(v3);  //��ӡvector�������

	//��������
	vector<int> v4(v3);
	print(v4);  //��ӡvector�������
}


//vector�ĸ�ֵ
void test02()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	print(v1);

	//��ֵ
	vector<int> v2 = v1;  //ֱ�� = ��ֵ
	print(v2);
	
	vector<int> v3;
	v3.assign(v1.begin(), v1.end()); //��v1������[v1.begin(),v1.end())�����ݸ���v3
	print(v3);

	vector<int> v4;
	v4.assign(10, 100); //��v4 ��10��100
	print(v4);
}


//vector �������ʹ�С
void test03()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	print(v1);

	if (v1.empty())  //Ϊ�棬��������Ϊ��
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "������Ϊ��" << endl;
	}

	cout<<"vector��������  "<<v1.capacity()<<endl;//vector��������
	cout<<"vector�Ĵ�С��  " << v1.size()<<endl; //vector�Ĵ�С��
	v1.resize(15); //����ָ����С  ���ָ���ı�ԭ�����ˣ�Ĭ����0���
	print(v1);
	v1.resize(20, 100);//����ָ����С  ���ָ���ı�ԭ�����ˣ�����100���
	print(v1);
	v1.resize(10);// ����ָ����С  ���ָ���ı�ԭ�����ˣ���������ɾ��
	print(v1);
}


//vector�Ĳ����ɾ��
void test04()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	print(v1);

	v1.pop_back();//βɾ�� ɾ��β����һ������
	print(v1);

	//����
	v1.insert(v1.begin(), 100);//��һ�������ǵ����� ����ʼ����ǰ����100
	print(v1);

	v1.insert(v1.begin(), 2, 1000);//����ʼ����ǰ���룻����1000
	print(v1);

	//ɾ��
	v1.erase(v1.begin());//�����ǵ����� ɾ����ʼ�ĵ�һ������
	print(v1);

	//���
	v1.erase(v1.begin(), v1.end()); //ɾ������[v1.begin(),v1.end())����������� �����
	print(v1);
	
	v1.clear();
}


//vector ���ݴ�ȡ
void test05()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i]<<" "; //����[]����������Ԫ��
	}
	cout << endl;

	//����at ����Ԫ��
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " "; //����at����������Ԫ��
	}
	cout << endl;

	//��ȡ��һ��Ԫ��
	cout << "��һ��Ԫ��Ϊ�� " << v1.front() << endl;

	//��ȡ���һ��Ԫ��
	cout << "���һ��Ԫ��Ϊ��  " << v1.back() << endl;
}


//vector��������
//ʵ��Ԫ����Ԫ�ػ���
void test06()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	cout << " ����ǰ��"<<endl;
	cout << "v1: ";
	print(v1);

	vector<int> v2;
	for (int i = 10; i >0; i--)
	{
		v2.push_back(i);
	}
	cout << "v2: ";
	print(v2);
	v1.swap(v2);  //��v1,v2���ݽ���
	cout << "v1��v2������ "<<endl;
	cout << "v1: ";
	print(v1);
	cout << "v2: ";
	print(v2);


	//�ú�����ʵ����;
	//����swap�������ڴ�
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i + 1);
	}
	cout << "v��������  " << v.capacity() << endl;//vector�������� //��������100000
	cout << "�Ĵ�С��  " << v.size() << endl; //vector�Ĵ�С��  ��С��ʱΪ100000 
	
	v.resize(3);  //��������С����ָ��Ϊ3��������������Ȼ����100000����ɿռ��˷�
	
	cout << "vector��������  " << v.capacity() << endl;//vector�������� //��������100000
	cout << "vector�Ĵ�С��  " << v.size() << endl; //vector�Ĵ�С��  ��С��ʱΪ3
	
	//����swap�������ڴ�
	vector<int>(v).swap(v);//����һ���������󣬲�������v�Ĵ�С��ֵ������Ȼ������v���н�����ʵ���ڴ�����
	
	cout << "vector��������  " << v.capacity() << endl;
	cout << "vector�Ĵ�С��  " << v.size() << endl;
}


//vector Ԥ���ռ�
//����vector�ڶ�̬��չʱ����չ����
void test07()
{

	int num = 0;//ͳ���ڸ�������������ʱ�����ܹ����ٿռ�Ĵ���
	int* p = NULL;
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i + 1);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num= " << num << endl; //num=30,��������30���ڴ�  ����̬��չ��30�Σ�


	//����reserve��Ԥ���ռ䣬���ٿ����ڴ����
	vector<int> v1;
	
	v1.reserve(100000);  //������Ԥ����100000�Ŀռ�

	int num1 = 0;//ͳ���ڸ�������������ʱ�����ܹ����ٿռ�Ĵ���
	int* p1 = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i + 1);
		if (p1 != &v[0])
		{
			p1 = &v[0];
			num1++;
		}
	}
	cout << "num1= " << num1 << endl; //num=1,��ֻ����һ�οռ�
}

int main()
{
	//vector���캯��
	test01();

	//vector�ĸ�ֵ
	test02();

	//vector �������ʹ�С
	test03();

	//vector�Ĳ����ɾ��
	test04();

	//vector ���ݴ�ȡ
	test05();

	//vector��������
	test06();

	//vector Ԥ���ռ�
	test07();

	return 0;
}