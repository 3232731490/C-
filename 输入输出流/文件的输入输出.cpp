//�Լ�д��������
//#include <iostream>
//#include<string>
//#include<cmath>
//#include<iomanip>
//#include<fstream>
//using namespace std;
//int main()
//{
//	ofstream ofs;
//	ofs.open("f1.dat", ios::out);
//	int arr[2][10];
//	for (int i = 0; i < 2; i++)
//	{
//		cout << "�������" << i + 1 << "�����ݣ�" << endl;
//		for (int j = 0; j < 10; j++)
//		{
//			cin >> arr[i][j];
//		}
//}
//		for (int j = 0; j < 10; j++)
//		{
//			ofs << arr[0][j]<<" ";
//		}
//		ofs.close();
//		ofs.open("f2.dat", ios::out);
//		if (!ofs.is_open())
//		{
//			cout << "f1.dat open error" << endl;
//		}
//		for (int i = 0; i < 10; i++)
//		{
//			ofs << arr[1][i] << " ";
//	}
//		ofs.close();
//		ifstream ifs;
//		ifs.open("f1.dat", ios::in);
//		if (!ifs.is_open())
//		{
//			cout << "f1.dat open error" << endl;
//		}
//		int*p0=new int[10];
//		for (int i = 0; i < 10; i++)
//		{
//				ifs >> *p0;
//				p0++;
//			
//		}
//		//������û�ж�������
//		for (int i = 0; i < 10; i++,p0++)
//		{
//			cout << *p0 << " ";
//		}
//		ofs.open("f2.dat", ios::out|ios::app);
//		for (int i = 0; i < 10; i++,p0++)
//		{
//			ofs << *p0 << " " << endl;
//		}
//		ofs.close();
//		ifs.close();
//		ifs.open("f2.dat", ios::in);
//		if (!ifs.is_open())
//			cout << "f2.dat open error!\n";
//	
//		int* p = new int[20];
//		for (int i = 0; i < 20; i++)
//		{
//				ifs >>*p;
//				p++;
//			
//		}
//		//������û�ж�������
//		for (int i = 0; i < 20; i++)
//		{
//			cout << *p << " ";
//			p++;
//		}
//		ifs.close();
//		for (int i = 0; i < 19; i++)
//		{
//			for (int j = i + 1; j < 20; j++)
//			{
//				if (*p > *(p+1))
//				{
//					int temp =*p;
//					*p = *(p+1);
//					*(p+1) = temp;
//				}
//			}
//		}
//		ofs.open("f2.dat", ios::out);
//		if (!ofs.is_open())
//		{
//			cout << "f2.dat open error" << endl;
//		}
//		for (int i = 0; i < 20; i++)
//		{
//			ofs << *p << " ";
//			p++;
//		}
//		ofs.close();
//	system("pause");
//	return 0;
//}

//��׼��
#include <iostream>
#include <fstream>
using namespace std;                //VC++ 6.0Ҫ����
//fun1�����Ӽ�������20���������ֱ��������������ļ���

void fun1()
{
    int a[10];
    ofstream outfile1("f1.dat"), outfile2("f2.dat");  //�ֱ��������ļ�������
    if (!outfile1)                        //����f1.dat�Ƿ�ɹ�
    {
        cerr << "open f1.dat error!" << endl;
        exit(1);
    }
    if (!outfile2)                        //����f2.dat�Ƿ�ɹ�
    {
        cerr << "open f2.dat error!" << endl;
        exit(1);
    }
    cout << "enter 10 integer numbers:" << endl;
    for (int i = 0; i < 10; i++)          //����10������ŵ�f1.dat�ļ���
    {
        cin >> a[i];
        outfile1 << a[i] << " ";
    }
    cout << "enter 10 integer numbers:" << endl;
    for (int i = 0; i < 10; i++)           //����10������ŵ�f2.dat�ļ���
    {
        cin >> a[i];
        outfile2 << a[i] << " ";
    }
    outfile1.close();               //�ر�f1.dat�ļ�
    outfile2.close();               //�ر�f2.dat�ļ�
}

//��f1,dat����10������Ȼ���ŵ�f2.dat�ļ�ԭ�����ݵĺ���
void fun2()
{
    ifstream infile("f1.dat");       //f1.dat��Ϊ�����ļ�
    if (!infile)
    {
        cerr << "open f1.dat error!" << endl;
        exit(1);
    }
    ofstream outfile("f2.dat", ios::app);
    //f2.dat��Ϊ����ļ����ļ�ָ��ָ���ļ�β������д������ݷ���ԭ�����ݵĺ���
    if (!outfile)
    {
        cerr << "open f2.dat error!" << endl;
        exit(1);
    }
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        infile >> a[i];           //�����ļ�f2.dat����һ������
        outfile << a[i] << " ";     //��������ŵ�f2.dat��
    }
    infile.close();
    outfile.close();
}

//��f2.dat�ж���20�������������ǰ���С�����˳���ŵ�f2.dat
void fun3()
{
    ifstream infile("f2.dat"); //���������ļ���infile�������뷽ʽ��f2.dat
    if (!infile)
    {
        cerr << "open f2.dat error!" << endl;
        exit(1);
    }
    int a[20];
    int i, j, t;
    for (i = 0; i < 20; i++)
        infile >> a[i];        //�Ӵ����ļ�f2.dat����20������������a��
    for (i = 0; i < 19; i++)     //�����ݷ���20��������
        for (j = 0; j < 19 - i; j++)
            if (a[j] > a[j + 1])
            {
                t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            }
    infile.close();                //�ر������ļ�f2.dat
    ofstream outfile("f2.dat", ios::out);
    // f2.dat��Ϊ����ļ����ļ���ԭ������ɾ��
    if (!outfile)
    {
        cerr << "open f2.dat error!" << endl;
        exit(1);
    }
    cout << "data in f2.dat:" << endl;
    for (i = 0; i < 20; i++)
    {
        outfile << a[i] << " ";      //��f2.dat����������20����
        cout << a[i] << " ";
    }        //ͬʱ�������ʾ��
    cout << endl;
    outfile.close();
}

int main()
{
    fun1();                     //�ֱ����3������
    fun2();
    fun3();
    return 0;
}
