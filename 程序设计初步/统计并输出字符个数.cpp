#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	char c;
	int n=0, m=0, k=0, l=0;//nΪ��ĸ������mΪ�ո������kΪ���ָ�����lΪ�����ַ�������
	cout << "������һ���ַ���" << endl;
	while ((c = getchar()) != '\n')
	{
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
			n = n + 1;
		else if (c >= '0' && c <= '9')
			k = k + 1;
		else if (c == ' ')
			m = m + 1;
		else l++;
	}
	cout << "��ĸ����Ϊ��" << n <<endl<< "�ո����Ϊ��" << m <<endl<< "���ָ���Ϊ��" << k <<endl<< "�����ַ�����Ϊ��" << l << endl;
	return 0;
}