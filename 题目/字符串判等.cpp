#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
����������

�ж������ɴ�Сд��ĸ�Ϳո���ɵ��ַ����ں��Դ�Сд���Һ��Կո���Ƿ���ȡ�

���У�ÿ�а���һ���ַ������ַ������Ȳ����� 100��

�������ַ�����ȣ����"YES"���������"NO"��
*/

int comparestr(char*str1, char* str2 ,int len)
{

    for (int i = 0,j=0; i < len&&j<len; i++,j++)
    {
        while (str1[i] == 32)
        {
            i++;
        }
        while (str2[j] == 32)
        {
            j++;
        }
        if (str1[i] >= 'a' && str1[i] <= 'z')
        {
            str1[i] -= 32;
        }
        if (str2[j] >= 'a' && str2[j] <= 'z')
        {
            str2[j] -= 32;
        }
   


        if (str1[i] != str2[j])
        {
            return -1;
        }
        else continue;
    }
    return 1;
}
int main()
{
    char str1[100],str2[100];
    //����ո��Ҫʹ��getline
    cout << "�������һ���ַ���" << endl;
    cin.getline(str1,100);
    cout << "������ڶ����ַ���" << endl;
    cin.getline(str2,100);
    int i = 0, j = 0;
    while (str1[i] != '/0'&&str1[i]!=0)
    {
        i++;
    }
    while (str2[j] != '/0' && str2[j] != 0)
    {
        j++;
    }
    int len = max(i, j);
    int num = comparestr(str1, str2,len);
    if (num == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}