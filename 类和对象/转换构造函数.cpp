#include <iostream>
using namespace std;
class Complex
{
public:
	Complex(double r)
	{
		this->m_a = r;
		this->m_b = 0;
	}

	Complex(double a, double b) : m_a(a),m_b(b){};

	int m_a, m_b;
};
Complex operator+(Complex& a, Complex &b)
{
	Complex temp(0, 0);
	temp.m_a = a.m_a + b.m_a;
	temp.m_b = a.m_b + b.m_b;
	return temp;
}
int main()
{
	double a, b, c, d,i;
	cout << "请输入p1复数的系数：" << endl;
	cin >> a >> b;
	cout << "请输入p2复数的系数：" << endl;
	cin >> c >> d;
	cout << "输入一个整数： " << endl;
	cin >> i;
	Complex p1(a, b), p2(c, d);
	Complex p3 = p1+p2;  //两个复数之和
	cout << "( " << p1.m_a << " + " << p1.m_b << "i )" << " + ( " << p2.m_a << " + " << p2.m_b << "i )= " << "( " << p3.m_a << "+" << p3.m_b << "i )" << endl;
	cout << endl;
	p3 = p1 + Complex( i );  //复数+整数
	cout << "( " << p1.m_a << " + " << p1.m_b << "i )" << " +  " << i<< "  =  " << "( " << p3.m_a << "+" << p3.m_b << "i )" << endl;
	cout << endl;
	p3 = Complex(i) + p2;  //整数+ 复数
	cout << i<< " + " <<"  ( " << p2.m_a << " + " << p2.m_b << "i )= " << "( " << p3.m_a << "+" << p3.m_b << "i )" << endl;
	system("pause");
	return 0;
}

