#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//ν��
//����ֵΪbool���͵ķº���
//���operator()����һ����������ô����һԪν��
//���operator()����������������ô������Ԫν��

class Greater
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }

};

//һԪν��
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }

    //������������û�д���5������
   vector<int>::iterator it= find_if(v.begin(), v.end(), Greater());
   if (it == v.end())
   {
       cout << "δ�ҵ�����5������" << endl;
 }
   else
   {
       cout << "�ҵ�����5����" << endl;
   }
}


class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }

};
//��Ԫν��
void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    cout << "����ǰ��" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
    cout << "�������У�" << endl;
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;

    cout << "�������У� " << endl;
    sort(v.begin(), v.end(),MyCompare());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}
int main()
{
    //һԪν��
    test01();

    cout << endl << "--------------------------" << endl;
    //��Ԫν��
    test02();

    system("pause");
    return 0;
}