//自己写的有问题
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
//		cout << "请输入第" << i + 1 << "组数据：" << endl;
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
//		//测试有没有读到数据
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
//		//测试有没有读到数据
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

//标准答案
#include <iostream>
#include <fstream>
using namespace std;                //VC++ 6.0要此行
//fun1函数从键盘输入20个整数，分别存放在两个磁盘文件中

void fun1()
{
    int a[10];
    ofstream outfile1("f1.dat"), outfile2("f2.dat");  //分别定义两个文件流对象
    if (!outfile1)                        //检查打开f1.dat是否成功
    {
        cerr << "open f1.dat error!" << endl;
        exit(1);
    }
    if (!outfile2)                        //检查打开f2.dat是否成功
    {
        cerr << "open f2.dat error!" << endl;
        exit(1);
    }
    cout << "enter 10 integer numbers:" << endl;
    for (int i = 0; i < 10; i++)          //输入10个数存放到f1.dat文件中
    {
        cin >> a[i];
        outfile1 << a[i] << " ";
    }
    cout << "enter 10 integer numbers:" << endl;
    for (int i = 0; i < 10; i++)           //输入10个数存放到f2.dat文件中
    {
        cin >> a[i];
        outfile2 << a[i] << " ";
    }
    outfile1.close();               //关闭f1.dat文件
    outfile2.close();               //关闭f2.dat文件
}

//从f1,dat读入10个数，然后存放到f2.dat文件原有数据的后面
void fun2()
{
    ifstream infile("f1.dat");       //f1.dat作为输入文件
    if (!infile)
    {
        cerr << "open f1.dat error!" << endl;
        exit(1);
    }
    ofstream outfile("f2.dat", ios::app);
    //f2.dat作为输出文件，文件指针指向文件尾，向它写入的数据放在原来数据的后面
    if (!outfile)
    {
        cerr << "open f2.dat error!" << endl;
        exit(1);
    }
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        infile >> a[i];           //磁盘文件f2.dat读入一个整数
        outfile << a[i] << " ";     //将该数存放到f2.dat中
    }
    infile.close();
    outfile.close();
}

//从f2.dat中读入20个整数，将它们按从小到大的顺序存放到f2.dat
void fun3()
{
    ifstream infile("f2.dat"); //定义输入文件流infile，以输入方式打开f2.dat
    if (!infile)
    {
        cerr << "open f2.dat error!" << endl;
        exit(1);
    }
    int a[20];
    int i, j, t;
    for (i = 0; i < 20; i++)
        infile >> a[i];        //从磁盘文件f2.dat读入20个数放在数组a中
    for (i = 0; i < 19; i++)     //用起泡法对20个数排序
        for (j = 0; j < 19 - i; j++)
            if (a[j] > a[j + 1])
            {
                t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            }
    infile.close();                //关闭输入文件f2.dat
    ofstream outfile("f2.dat", ios::out);
    // f2.dat作为输出文件，文件中原有内容删除
    if (!outfile)
    {
        cerr << "open f2.dat error!" << endl;
        exit(1);
    }
    cout << "data in f2.dat:" << endl;
    for (i = 0; i < 20; i++)
    {
        outfile << a[i] << " ";      //向f2.dat输出已排序的20个数
        cout << a[i] << " ";
    }        //同时输出到显示器
    cout << endl;
    outfile.close();
}

int main()
{
    fun1();                     //分别调用3个函数
    fun2();
    fun3();
    return 0;
}
