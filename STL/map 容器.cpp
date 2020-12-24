#include<iostream>
#include<map>
#include<string>
using namespace std;
//map ������Ԫ�ض���pair  
//pair ��һ��Ԫ��Ϊkey ���������ã� �ڶ���Ԫ��Ϊvalue(ʵֵ)
//����Ԫ�ض������keyֵ�Զ�����
//���ڹ���ʽ���� �ײ�ṹ�ɶ�����ʵ��
//�ŵ㣺  ���Ը���keyֵ�����ҵ�value ֵ
//multimap ���������ظ�ֵ /map���������ظ�ֵ

void Printmap(map<int, int>& m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key ֵ��" << it->first << " value ֵ��  " << it->second << endl;
    }
    cout << endl;
}

//map ����͸�ֵ
void test01()
{
    //����map ����
    map<int,int> m;

    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));

    Printmap(m);


    map<int, int> m2(m);
    Printmap(m2);


    map<int, int> m3;
    m3 = m2;
    Printmap(m3);
}


//map ��С�ͽ���
void test02()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(4, 40));

    if (m1.empty())
    {
        cout << "m1 Ϊ�գ�" << endl;
    }
    else
    {
        cout << "m1 ��Ϊ�գ�" << endl;
        cout << "m1 �Ĵ�СΪ��  " << m1.size() << endl;
    }

    map<int, int> m2;
    m2.insert(pair<int, int>(5, 100));
    m2.insert(pair<int, int>(6, 200));
    m2.insert(pair<int, int>(7, 300));
    m2.insert(pair<int, int>(8, 400));
    
    cout << "m1 m2 ����ǰ��  " << endl;
    Printmap(m1);
    Printmap(m2);


    m1.swap(m2);
    cout << "m1 m2 ������  " << endl;
    Printmap(m1);
    Printmap(m2);

}


//map �����ɾ��
void test03()
{
    map<int, int> m1;
  //����
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    
    m1.insert(make_pair(3, 30));
    
    m1.insert(map<int,int>::value_type(4,40));


    //��̫�����������ʽ��������
    //�������������ʽ����key����value
    m1[5] = 50;

    Printmap(m1);

    //ɾ��
    m1.erase(m1.begin());
    Printmap(m1);

    m1.erase(3); //ɾ��keyֵΪ3������
    Printmap(m1);

    //���
    m1.erase(m1.begin(), m1.end());

    m1.clear();
    Printmap(m1);
}


//map ���Һ�ͳ��
void test04()
{
    //����
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(4, 40));
    
    map<int,int>::iterator it=m1.find(3);
    if (it != m1.end())
    {
        cout << "�ҵ�Ԫ��:  key= " << (*it).first << "     vaule= " << (*it).second << endl;
    }
    else
    {
        cout << "δ�ҵ�Ԫ�أ�" << endl;
    }

    //ͳ��
    int num=m1.count(3);
    cout << "num =  " << num << endl;
}


class mycompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }

};
//map  ��������
void test05()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(4, 40));
    m1.insert(pair<int, int>(5, 50));
   
    //Ĭ�� ��������
    Printmap(m1);

    //����������  ��set ����������һ��
    //map<int, int,mycompare> m2;
    //m2.insert(pair<int, int>(5, 100));
    //m2.insert(pair<int, int>(6, 200));
    //m2.insert(pair<int, int>(7, 300));
    //m2.insert(pair<int, int>(8, 400));

    //    for (map<int, int, mycompare>::iterator it = m2.begin(); it != m2.end(); it++)
    //    {
    //        cout << "key ֵ��" << it->first << " value ֵ��  " << it->second << endl;
    //    }
    //    cout << endl;
   

}
int main()
{
    //map ����͸�ֵ
    test01();
    cout << endl << "-----------------------------" << endl;

    //map ��С�ͽ���
    test02();
    cout << endl << "-----------------------------" << endl;

    //map �����ɾ��
    test03();
    cout << endl << "-----------------------------" << endl;

    //map ���Һ�ͳ��
    test04();
    cout << endl << "-----------------------------" << endl;

    //map  ��������
    test05();
    cout << endl << "-----------------------------" << endl;

    system("pause");
    return 0;
}