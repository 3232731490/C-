#include <iostream>
#include<vector>
using namespace std;
int main()
{
    /*
    ����������

    ʯͷ�������ǳ����Ĳ�ȭ��Ϸ��ʯͷʤ����������ʤ������ʤʯͷ����������˳�ȭһ�����򲻷�ʤ����
    һ�죬С A ��С B ��������ʯͷ����������֪���ǵĳ�ȭ�����������Թ��ɵģ�
    ���磺��ʯͷ-��-ʯͷ-����-ʯͷ-��-ʯͷ-�����������������ԡ�ʯͷ-��-ʯͷ-������Ϊ���ڲ���ѭ���ġ�
    ���ʣ�С A ��С B ���� N ��֮��˭Ӯ�������ࣿ
    */
    
    int N, NA, NB;
    cout << "0---ʯͷ��2--������5--��" << endl;
    cout << "�������ȭ������A ��ȭ�����ڳ��ȡ�B��ȭ�����ڳ���" << endl;
    int numA = 0, numB = 0;
    cin >> N >> NA >> NB;
    vector<int> vA;
    vector<int> vB;
    cout << "������A ��һ����ȭ����: " << endl;
    for (int i = 0; i < NA; i++)
    {
        int n;
        cin >> n;
        vA.push_back(n);
    }
    cout << "������B ��һ����ȭ����: " << endl;
    for (int i = 0; i < NB; i++)
    {
        int n;
        cin >> n;
        vB.push_back(n);
    }
    vector<int>::iterator itA = vA.begin();
    vector<int>::iterator itB = vB.begin();
    for (int i = 0; i < N; i++)
    {
        if (*itA == 0)
        {
            if (*itB == 2)
            {
                numA++;
            }
            else if (*itB == 5)
            {
                numB++;
            }
        }
        else if (*itA == 2)
        {
            if (*itB == 5)
            {
                numA++;
            }
            else if (*itB == 0)
            {
                numB++;
            }
        }
        else if (*itA == 5)
        {
            if (*itB == 0)
            {
                numA++;
            }
            else if (*itB == 2)
            {
                numB++;
            }
        }
        itA++;
        itB++;
        if (itA == vA.end())
        {
            itA = vA.begin();
        }
        if (itB == vB.end())
        {
            itB = vB.begin();
        }
    }
    if (numA > numB)
    {
        cout << "��ʤ��Ϊ A" << endl;
    }
    else if (numA < numB)
    {
        cout << "��ʤ��Ϊ B" << endl;
    }
    else
    {
        cout << "draw ƽ��" << endl;
    }
    return 0;
}