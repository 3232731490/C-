#include<iostream>
#include<string>
using namespace std;
//��������  ���º�����


class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

// 1������������ʹ��ʱ��������ͨ����һ�����ã������в�����Ҳ�����з���ֵ
void test01()
{
    MyAdd myadd;
    cout<<myadd(10, 10)<<endl;

}


//2�� �������󳬳���ͨ�����ĸ���������Լ���״̬
class MyPrint
{
public:
    MyPrint()
    {
        count = 0;
    }
    void operator ()(string test)
    {
        cout << test << endl;
        this->count++;
    }
    int count; //�ڲ��Լ���״̬
};

void test02()
{
    MyPrint myprint;
    myprint("hello world");
    myprint("hello world");
    myprint("hello world");
    myprint("hello world");
    cout << "MyPrint �ĵ��ô���Ϊ��  " << myprint.count << endl;
}

//3���������������Ϊ��������
void doPrint(MyPrint &mp,string s)
{
    mp(s);

}
void test03()
{
    MyPrint myprint;
    doPrint(myprint, "hello  world");
}
int main()
{
    test01();

    test02();

    test03();
    system("pause");
    return 0;
}