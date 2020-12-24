#include <iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
class Triangle
{
public:


private:

};



//不知道哪里出问题了，输入1的小数时，打印的是0的小数
//int main()
//{
//	float a;
//	while (( cin.get())!= '\n')
//	{
//		cin >> a;
//		cout << setiosflags(ios::fixed) << setprecision(3);
//		cout << setw(10) << a << endl;
//		
//	}
//	system("pause");
//	return 0;
//}


//标准答案
int main()
{
    float a[5];
    cout << "input data:";
    for (int i = 0; i < 5; i++)
        cin >> a[i];
    cout << setiosflags(ios::fixed) << setprecision(3);
    for (int i = 0; i < 5; i++)
        cout << setw(10) << a[i] << endl;
    return 0;
}


//另解
//int main()
//{
//    float a[5];
//    int i;
//    cout << "input data:";
//    for (i = 0; i < 5; i++)
//        cin >> a[i];
//    cout.setf(ios::fixed);
//    cout.precision(2);
//    for (i = 0; i < 5; i++)
//    {
//        cout.width(10);
//        cout << a[i] << endl;
//    }
//    return 0;
//}