#include<iostream>
#include<string>
using namespace std;

//string�Ĺ��캯��
void test01()
{
	string s1;// Ĭ�Ϲ���
	const char* str = "hello world";
	string s2(str);  //ʹ���ַ�����ʼ��

	string s3(s2);//��������

	string s4(5, 'a');//��5�� a ���г�ʼ��

}

//string �ĸ�ֵ����
void test02()
{
	string str1;
	str1 = "hello world";  //����һ �Ⱥ�ֱ�Ӹ�ֵ

	string str2;
	str2 = str1;  //������

	string str3;
	str3 = 'a';  //������  ��ֵ�����ַ�

	string str4;
	str4.assign("hello C++"); // ������ ����string�ĳ�Ա������ֵ

	string str5;
	str4.assign("hello C++",5); //������  ���ַ���ǰ5���ַ���ֵ��str5;

	string str6;
	str6.assign(str5);  //������ 

	string str7;
	str7.assign(10, 'w');//������  ��ֵ10��w��str7
}

//string�ַ���ƴ��
void test03()
{
	string str1 = "��";
	str1 += "������Ϸ";//����һ ���������

	str1 += ':'; //������ ƴ��һ���ַ�

	string str2 = "LOL";
	str1 += str2;  //������ ƴ��һ���ַ���

	string str3="I";
	str3.append("LOVE");//������ ����string �ĳ�Ա����ƴ��

	str3.append("GAME ", 4);// ������ ���ַ���ǰ4���ַ�ƴ��

	str3.append(str2); //������ ׷��һ���ַ���

	str3.append(str2, 0, 3);//������ ��str2��0����ʼƴ��3���ַ�
	cout << str3;
}


//string �Ĳ��Һ��滻
void test04()
{
	//1������

	string str1 = "abcdefg";
	//find  �������Ҳ���
	int pos= str1.find("de"); //�����ַ������ֵ�λ�� ���ҵ����ص�һ���ַ�λ�ã�û���ҵ�����-1
	//rfind  �����������
	pos = str1.rfind("de");  //�����ַ������ֵ�λ�� ���ҵ����ص�һ���ַ�λ�ã�û���ҵ�����-1

	//2���滻
	string str2="abcdefg";
	str2.replace(1, 3, "1111"); //��һ��λ�ÿ�ʼ��������ַ����滻�� 1111  ��str2="a1111efg"

}


//string �ַ����Ƚ�
void test05()
{
	string str1 = "hello";
	string str2 = "hello";
	if (str1.compare(str2) == 0)  //compare ������Ҫ�����ǱȽ������ַ����Ƿ���� 
	{
		cout << "str1==str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1>str2" << endl;
	}
	else
	{
		cout << "str1<str2" << endl;
	}
}

//string �е����ַ���ȡ
void test06()
{
	string str1 = "hello";

	//1��ͨ��[]���ʵ����ַ�
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << " ";
	}
	cout << endl;

	//2��ͨ��at�������ʵ����ַ�
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i) << " ";
	}
	cout << endl;

	//�޸ĵ����ַ�
	str1[0] = 'x';
	str1.at(0) = 'h';
}

//string �����ɾ��
void test07()
{
	string str1 = "hello";

	//1������
	str1.insert(1, "111");//��һ��λ����"111"�ַ���  str1="h111ello";

	//2��ɾ��
	str1.erase(1, 3);//��һ��λ��ɾ��3���ַ�
}

//���ַ����л�ȡ�Ӵ�
void test08()
{
	string str = "abcdefg";
	string substr = str.substr(1, 3);//��һ��λ��ʼ��ȡ3���ַ���substr


	//Ӧ��
	string email = "nilu@qq.com";
	int pos=email.find("@");
	string username = email.substr(0, pos);//�������н�ȡ�û���
}
int main()
{
	//string �Ĺ��캯��
	test01();

	//string �ĸ�ֵ����
	test02();

	//string �ַ���ƴ��
	test03();

	//string �Ĳ��Һ��滻
	test04();

	//string �ַ����Ƚ�
	test05();

	//string �е����ַ���д
	test06();

	//string �����ɾ��
	test07();

	//���ַ����л�ȡ�Ӵ�
	test08();
	return 0;
}