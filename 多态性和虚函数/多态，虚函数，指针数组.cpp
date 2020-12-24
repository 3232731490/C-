#include <iostream>
#include<string>
#include<cmath>
using namespace std;
class Shape  //形状基类
{
public:
	virtual void m_Shape() = 0;
	virtual void outputS() = 0;
	virtual double get_S() = 0;
};
class Circle :public Shape  //圆类
{
public:
	void m_Shape()
	{
		cout << "This is a Circle:  " << "\n";
	}
	Circle(double r) :m_r(r) {};
	void outputS()
	{
		cout << "The Circle's S =  " << m_r * m_r * 3.14159 << endl;
	}
	double get_S()
	{
		return m_r * m_r * 3.14159;
	}
private:
	double m_r;
};
class Rectangle :public Shape   //矩形
{
public:
	void m_Shape()
	{
		cout << "This is a Recrangle " << "\n";
	}
	Rectangle(double a, double b) :m_w(b), m_l(a) {};
	void outputS()
	{
		cout << "The Rectangle's S =  " << m_w * m_l << endl;
	}
	double get_S()
	{
		return m_w * m_l;
	}
private:
	double m_w;
	double m_l;
};
class Triangle :public Shape   //三角形
{
public:
	void m_Shape()
	{
		cout << "This is a Triangle " << "\n";
	}
	Triangle(double a, double b,double c)
	{
		m_a = a;
		m_b = b;
		m_c = c;
		m_s = (m_a + m_b + m_c) / 2;
		m_S = sqrt(m_s * (m_s - m_a) * (m_s - m_b) * (m_s - m_c));
	};
	void outputS()
	{
		cout << "The Trinangle's S =  " << m_S << endl;
	}
	double get_S()
	{
		return m_S;
	}
private:
	double m_a;
	double m_b;
	double m_c;
	double m_S;
	double m_s;
};
class Square :public Shape   //正方形
{
public:
	void m_Shape()
	{
		cout << "This is a Square" << endl;
	}
	Square(double a) :m_a(a) {};
	void outputS() 
	{
		cout << "The Square's S=  " << m_a * m_a << endl;
	}
	double get_S()
	{
		return m_a * m_a;
	}
private:
	double m_a;
};
class Trapezoid :public Shape   //梯形
{
public:
	void m_Shape()
	{
		cout << "This is a Trapezoid" << endl;
	}
	Trapezoid(double a, double b, double c) :m_a(a), m_b(b), m_c(c) {};
	void outputS()
	{
		cout << "The Trapezoid's S=  " << (m_a + m_b) * m_c / 2<<endl;
	}
	double get_S()
	{
		return  (m_a + m_b) * m_c / 2;
	}
private:
	double m_a;//上底
	double m_b;//下底
	double m_c;//高
};
int main()
{
	Shape* p[5] = { new Circle(3.4),new Square(8.7),new Rectangle(3.2, 4.6), new Trapezoid(12,3,6),new Triangle(3,4,5) };
	double Num = 0;
	for (int i = 0; i < 5; i++)
	{
		p[i]->m_Shape();
		p[i]->outputS();
		cout << "---------------分割线--------------" << endl;
		Num += p[i]->get_S();
	}
	cout << "---------------分割线--------------" << endl;
	cout << "所有图形面积之和为：   " << Num << endl;
	system("pause");
	return 0;
}