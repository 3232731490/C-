#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//�ڽ���������  ����ͷ�ļ�  #include<functional>

//1�������º���
//���ܣ� ʵ���������� ����negate (ȡ���º����� ��һԪ���� �������Ƕ�Ԫ����
//plus(�ӷ�����minus����������multiplies(�˷�)��divides(��������modulus(ȡģ����negate (ȡ���º�����
void test01()
{
    //ȡ���º���
    negate<int> n;
    cout << n(50) << endl;

    //plus
    plus<int> p;
    cout<<p(10, 20)<<endl;

}


class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }

};
//2����ϵ�º���
//equal_to(����),not_equal_to(������),greater(����),greater_equal(���ڵ���),less(С��),less_equal(С�ڵ���)
void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    cout << "����ǰ��  " << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //����
   sort(v.begin(), v.end(), MyCompare());
    //����ʹ�ñ������ṩ�ķº���
   //sort(v.begin(), v.end(), greater<int>());
    cout << "�����  " << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


//3���߼��º���
void test03()
{
    //�߼���  logical_not  �߼��� logical_and     �߼���  logical_or
    vector<bool> v;
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);

    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    //�����߼��� ������v ���˵�v2 �� ��ȡ������
    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
        for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
}
int main()
{
  //1�������º���
    test01();

    //2����ϵ�º���
    test02();

    //3���߼��º���
    test03();

    system("pause");
    return 0;
}