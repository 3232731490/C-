#include <iostream>
using namespace std;
class Complex
{
public:
	Complex operator+( Complex& b)
	{
		Complex temp(0, 0);
		temp.m_a =this->m_a + b.m_a;
		temp.m_b =this->m_b + b.m_b;
		return temp;
	}
	Complex operator-(Complex& b)
	{
		Complex temp(0, 0);
		temp.m_a = this->m_a - b.m_a;
		temp.m_b = this->m_b - b.m_b;
		return temp;
	}
	Complex operator*(Complex& b)
	{
		Complex temp(0, 0);
		temp.m_a = this->m_a * b.m_a - this->m_b*b.m_b;
		temp.m_b = this->m_b*b.m_a + this->m_a*b.m_b;
		return temp;
	}
	Complex operator/(Complex& b)
	{
		Complex temp(0, 0);
		temp.m_a = (this->m_a * b.m_a + this->m_b * b.m_b)/((b.m_a*b.m_a)+(b.m_b*b.m_b));
		temp.m_b = (this->m_b*b.m_a-this->m_a*b.m_b) / ((b.m_a * b.m_a) + (b.m_b * b.m_b));
		return temp;
	}
	Complex(double a, double b) : m_a(a),m_b(b){};

	int m_a, m_b;
};

int main()
{
	double a, b, c, d;
	cout << "请输入p1复数的系数：" << endl;
	cin >> a >> b;
	cout << "请输入p2复数的系数：" << endl;
	cin >> c >> d;
	Complex p1(a, b), p2(c, d);
	Complex p3 = p1+p2;
	cout << "( " << p1.m_a << " + " << p1.m_b << "i )" << " + ( " << p2.m_a << " + " << p2.m_b << "i )= " << "( " << p3.m_a << "+" << p3.m_b << "i )" << endl;
	cout << endl;
	p3 = p1 * p2;
	cout << "( " << p1.m_a << " + " << p1.m_b << "i )" << " * ( " << p2.m_a << " + " << p2.m_b << "i )= " << "( " << p3.m_a << "+" << p3.m_b << "i )" << endl;
	cout << endl;
	p3 = p1 - p2;
	cout << "( " << p1.m_a << " + " << p1.m_b << "i )" << " - ( " << p2.m_a << " + " << p2.m_b << "i )= " << "( " << p3.m_a << "+" << p3.m_b << "i )" << endl;
	cout << endl;
	p3 = p1 / p2;
	cout << "( " << p1.m_a << " + " << p1.m_b << "i )" << " / ( " << p2.m_a << " + " << p2.m_b << "i )= " << "( " << p3.m_a << "+" << p3.m_b << "i )" << endl;
	cout << endl;
	system("pause");
	return 0;
}

