#include<vector>
#include<iostream>
#include<string>
using namespace std;

/*
����������

ҽ������дҩƷ����ʱ�򾭳���ע���Сд����ʽ�Ƚϻ��ҡ�
��Ҫ����дһ������ҽ����д���ҵ�ҩƷ�������ͳһ�淶�ĸ�ʽ��
��ҩƷ���ĵ�һ���ַ��������ĸҪ��д��������ĸСд���罫"ASPIRIN"��"aspirin"�����"Aspirin"��


��һ��һ������ n����ʾ�� n ��ҩƷ��Ҫ����n ������ 100��

������ n �У�ÿ��һ�����ʣ����Ȳ����� 20����ʾҽ�������ҩƷ����ҩƷ������ĸ�����ֺ�-��ɡ�
*/

/*
�������룺
4
AspiRin
cisapride
2-PENICILLIN
Cefradine-6
*/
int main()
{
    vector<string> v;
    int n;
    cout << "�������м���ҩ����Ҫ���� " << endl;
    cin >> n;
    cout << "����������ҩ����" << endl;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
    {
        int len = (*it).size();
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
            {
                if ((*it)[i] >= 'a' && (*it)[i] <= 'z')
                {
                    (*it)[i] -= 32;
                }
            }
            else
            {
                if ((*it)[i] >= 'A' && (*it)[i] <= 'Z')
                {
                    (*it)[i] += 32;
                }
            }
        }
    }
    cout << "ҩ������������£� " << endl;
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}