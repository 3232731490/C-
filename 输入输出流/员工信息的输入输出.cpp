//�Լ�д�ģ�fun1,fun2,fun3����ʹ�ã�fun4������

//#include <iostream>
//#include <fstream>
//#include<string>
//using namespace std;                
//
//class epoloyee
//{
//    friend istream& operator>>(istream& cin, epoloyee& p);//">>"����
//public:
//    epoloyee() {};
//    epoloyee(int a, string name, int age, float w) :m_num(a), m_name(name), m_age(age), m_wages(w) {};
//    void set_num(int n)
//    {
//        m_num = n;
//    }
//    void set_name(string name)
//    {
//        m_name = name;
//    }
//    void set_age(int age)
//    {
//        m_age = age;
//    }
//    void set_wages(float wages)
//    {
//        m_wages = wages;
//    }
//    int get_num()
//    {
//        return m_num;
//    }
//    string get_name()
//    {
//        return m_name;
//    }
//    int get_age()
//    {
//        return m_age;
//    }
//    float get_wages()
//    {
//        return m_wages;
//    }
//
//private:
//    int m_num;//����
//    string m_name;//����
//    int m_age;//����
//    float m_wages;//����
//};
//void fun1()  //�����Ա�����ݷ����ļ��б���
//{
//    epoloyee e[5] = { { 1001,"��·",18,0 },
//                  {1002, "���", 18, 10},
//                  {1003, "�ʤ", 20, 20},
//                  {1004,"������",17,30},
//                 {1005,"�����",19,19} };
//    ofstream ofs;
//    ofs.open("epoy.text");
//    if (!ofs.is_open())
//    {
//        cerr << "open epoy.text error !" << endl;
//        exit;
//    }
//    for (int i = 0; i < 5; i++)
//    {
//        ofs <<  e[i].get_num() << endl;
//        ofs <<  e[i].get_name() << endl;
//        ofs <<  e[i].get_age() << endl;
//        ofs << e[i].get_wages() << endl;
//        ofs << endl;
//    }
//    ofs.close();
//}
//istream& operator>>(istream& cin,  epoloyee& p)
//{
//    cout << "����Ա����Ϣ��  " << endl;
//    int num;
//    string name;
//    int age;
//    float wages;
//    cout << "���ţ�  " << endl;
//    cin >> num;
//    cout << "������" << endl;
//    cin >> name;
//    cout << "���䣺 " << endl;
//    cin >> age;
//    cout << "���ʣ�  " << endl;
//    cin >> wages;
//    p.m_age = age;
//    p.m_name = name;
//    p.m_num = num;
//    p.m_wages = wages;
//    return cin;
//}
//void fun2()//��������Ա����Ϣ�������ļ�ĩβ
//{
//    epoloyee e1,e2;
//    cin >> e1>>e2;
//    ofstream ofs("epoy.text",ios::out|ios::app);
//    if (!ofs.is_open())
//    {
//        cerr << "open epoy.text errror!" << endl;
//        exit;
//    }
//    ofs  << e1.get_num() << endl;
//    ofs  << e1.get_age() << endl;
//    ofs  << e1.get_wages() << endl;
//    ofs << endl;
//    ofs  << e2.get_num() << endl;
//    ofs << e2.get_name() << endl;
//    ofs  << e2.get_age() << endl;
//    ofs  << e2.get_wages() << endl;
//    ofs << endl;
//    ofs.close();
//}
//void fun3()//����ļ�ȫ��ְ����Ϣ
//{
//    ifstream ifs("epoy.text");
//    if (!ifs.is_open())
//    {
//        cerr << "open epoy.text error!" << endl;
//        exit;
//    }
//    char s[100];
//    while (ifs.getline(s, 100, EOF))
//    {
//        cout << s;
//    }
//    ifs.close();
//}
//
////�������ʵ��������
//void fun4()//����Ա��
//{
//    cout << "��������Ҫ���ҵ�Ա���ţ�" << endl;
//    int num;
//    cin >> num;
//    ifstream ifs("epoy.text",ios::beg);
//    if (!ifs)
//    {
//        cerr << "open epoy.text error!" << endl;
//        exit;
//    }
//    epoloyee e[7];
//    int num1;
//    string name;
//    int age;
//    float wages;
//    char s[100];
//    for (int i = 0; i < 7; i++)
//    {
//        while (ifs.getline(s, 20, '\n'))
//            ifs >>num1;
//        e[i].set_num(num1);
//        ifs.ignore();
//        while (ifs.getline(s, 20, '\n'))
//            ifs >> name;
//        e[i].set_name(name);
//        ifs.ignore();
//        while (ifs.getline(s, 20, '\n'))
//            ifs >> age;
//        e[i].set_age(age);
//        ifs.ignore();
//        while (ifs.getline(s, 20, '\n'))
//            ifs >> wages;
//        e[i].set_wages(wages);
//        ifs.ignore();
//        ifs.ignore();
//  }
//    int count = 0;
//    for (int i = 0; i < 7; i++)
//    {
//        if (num == e[i].get_num())
//        {
//            cout << "���ţ�  " << e[i].get_num() << endl;
//            cout << "������  " << e[i].get_name() << endl;
//            cout << "���䣺  " << e[i].get_age()<< endl;
//            cout << "���ʣ�  " << e[i].get_wages() << endl;
//            break;
//        }
//        count++;
//   }
//    if (count == 7)
//    {
//        cout << "�޴���" << endl;
//    }
//}
//int main()
//{
//    fun1();//�������Ա����Ϣ
//    fun2();//������������Ա����Ϣ��������ԭ���ļ�Ա������
//    fun3();//���Ա������
//    fun4();//����Ա��
//    system("pause");
//    return 0;
//}


//���ϵı��Ҳ��֪�����������
#include <iostream>
#include <fstream>
using namespace std;
struct staff
{
    int num;
    char name[20];
    int age;
    double  pay;
};
int main()
{
    staff staf[7] = { 2101,"Li",34,1203,2104,"Wang",23,674.5,2108,"Fun",54,778,
                     3006,"Xue",45,476.5,5101,"Ling",39,656.6 }, staf1;
    fstream iofile("staff.dat", ios::in | ios::out | ios::binary);
    if (!iofile)
    {
        cerr << "open error!" << endl;
        abort();
    }
    int i, m, num;
    cout << "Five staff :" << endl;
    for (i = 0; i < 5; i++)
    {
        cout << staf[i].num << " " << staf[i].name << " " << staf[i].age << " " << staf[i].pay << endl;
        iofile.write((char*)&staf[i], sizeof(staf[i]));
    }
    cout << "please input data you want insert:" << endl;
    for (i = 0; i < 2; i++)
    {
        cin >> staf1.num >> staf1.name >> staf1.age >> staf1.pay;
        iofile.seekp(0, ios::end);
        iofile.write((char*)&staf1, sizeof(staf1));
    }
    iofile.seekg(0, ios::beg);
    for (i = 0; i < 7; i++)
    {
        iofile.read((char*)&staf[i], sizeof(staf[i]));
        cout << staf[i].num << " " << staf[i].name << " " << staf[i].age << " " << staf[i].pay << endl;
    }
    bool find;
    cout << "enter number you want search,enter 0 to stop.";
    cin >> num;
    while (num)
    {
        find = false;
        iofile.seekg(0, ios::beg);
        for (i = 0; i < 7; i++)
        {
            iofile.read((char*)&staf[i], sizeof(staf[i]));
            if (num == staf[i].num)
            {
                m = iofile.tellg();
                cout << num << " is No." << m / sizeof(staf1) << endl;
                cout << staf[i].num << " " << staf[i].name << " " << staf[i].age << " " << staf[i].pay << endl;
                find = true;
                break;
            }
        }
        if (!find)
            cout << "can't find " << num << endl;
        cout << "enter number you want search,enter 0 to stop.";
        cin >> num;
    }
    iofile.close();
    return 0;
}