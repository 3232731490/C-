#include<iostream>
#include<string>
using namespace std;
int main()
{
    /*
    СӢ��ҩѧרҵ������ѧ��������ڼ�����ȥҽԺҩ��ʵϰ�Ļ��ᡣ

    ��ҩ��ʵϰ�ڼ䣬СӢ��ʵ��רҵ���������ҽ����һ�º�������֪СӢ�ڼ��������ȡ�ù��óɼ��������ֶ��⽻����һ�����񣬽��ܿ�սʱ�ڱ����ܹ���һЩ��Ա��������

    �����о���СӢ���������¼��ܹ��ɣ���������һ�� "ԭ�� -> ����" �����ӣ�

    ԭ�������е��ַ�������ĸ���б�ѭ��
    ����������λ�ã� abz -> dec ��
    ����洢��abcd -> dcba ��
    ��Сд��ת��abXY -> ABxy��
   
   */
    cout << "���������ģ� " << endl;
    string key;
    cin >> key;
    int len = key.size();
    for (int i = 0; i < len; i++)
    {
        if (key[i] <= 'Z' && key[i] >= 'A')
        {
            key[i] += 32;
        }
        else if (key[i] >= 'a' && key[i] <= 'z')
        {
            key[i] -= 32;
        }
    }
    for (int i = 0; i < len; i++)
    {
        char temp = key[i];
        key[i] = key[len - i - 1];
        key[len - i - 1] = temp;
        if (i+1 >= (len / 2) )
        {
            break;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (key[i] - 'a' > 2)
        {
            key[i] -= 3;
        }
        else if (key[i] <= 'Z' && key[i] >= 'A' && key[i] - 'A' > 2)
        {
            key[i] -= 3;
        }
        else
        {
            if (key[i] <= 'Z' && key[i] >= 'A')
            {
                key[i] = 'Z' - (2 - key[i] + 'A');
            }
            else if (key[i] >= 'a' && key[i] <= 'z')
            {
                key[i] = 'z' - (2 - key[i] + 'a');
            }
        }
    }
    cout << "ԭ��Ϊ�� " << endl;
    cout << key << endl;
    return 0;
}