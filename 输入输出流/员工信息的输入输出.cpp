//自己写的，fun1,fun2,fun3可以使用，fun4有问题

//#include <iostream>
//#include <fstream>
//#include<string>
//using namespace std;                
//
//class epoloyee
//{
//    friend istream& operator>>(istream& cin, epoloyee& p);//">>"重载
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
//    int m_num;//工号
//    string m_name;//姓名
//    int m_age;//年龄
//    float m_wages;//工资
//};
//void fun1()  //将五个员工数据放入文件中保存
//{
//    epoloyee e[5] = { { 1001,"倪路",18,0 },
//                  {1002, "李慧", 18, 10},
//                  {1003, "杨宝胜", 20, 20},
//                  {1004,"饶婷彭",17,30},
//                 {1005,"杨天锋",19,19} };
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
//    cout << "输入员工信息：  " << endl;
//    int num;
//    string name;
//    int age;
//    float wages;
//    cout << "工号：  " << endl;
//    cin >> num;
//    cout << "姓名：" << endl;
//    cin >> name;
//    cout << "年龄： " << endl;
//    cin >> age;
//    cout << "工资：  " << endl;
//    cin >> wages;
//    p.m_age = age;
//    p.m_name = name;
//    p.m_num = num;
//    p.m_wages = wages;
//    return cin;
//}
//void fun2()//输入两个员工信息，插入文件末尾
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
//void fun3()//输出文件全部职工信息
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
////这个功能实现有问题
//void fun4()//查找员工
//{
//    cout << "请输入您要查找的员工号：" << endl;
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
//            cout << "工号：  " << e[i].get_num() << endl;
//            cout << "姓名：  " << e[i].get_name() << endl;
//            cout << "年龄：  " << e[i].get_age()<< endl;
//            cout << "工资：  " << e[i].get_wages() << endl;
//            break;
//        }
//        count++;
//   }
//    if (count == 7)
//    {
//        cout << "无此人" << endl;
//    }
//}
//int main()
//{
//    fun1();//保存五个员工信息
//    fun2();//键盘输入两个员工信息并保存在原来文件员工后面
//    fun3();//输出员工数据
//    fun4();//查找员工
//    system("pause");
//    return 0;
//}


//网上的标答，也不知道哪里出错了
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