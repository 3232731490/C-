#include <iostream>
#include<string>
#include<cmath>
using namespace std;
class Shape
{
public:
	virtual void m_Shape() = 0;
	virtual void outputS() = 0;

};
class Circle :public Shape
{
public:
	void m_Shape()
	{
		cout << "This is a Circle:  " << "\n";
	}
	Circle(float r) :m_r(r) {};
	void outputS()
	{
		cout << "The Circle's S =  " << m_r * m_r * 3.14159 << endl;
	}
private:
	float m_r;
};
class Rectangle :public Shape
{
public:
	void m_Shape()
	{
		cout << "This is a Recrangle " << "\n";
	}
	Rectangle(float a, float b) :m_w(b), m_l(a) {};
	void outputS()
	{
		cout << "The Rectangle's S =  " << m_w * m_l << endl;
	}

private:
	float m_w;
	float m_l;
};
class Triangle :public Shape
{
public:
	void m_Shape()
	{
		cout << "This is a Recrangle " << "\n";
	}
	Triangle(float a, float b,float c) :m_b(b), m_a(a),m_c(c) {};
	float s = (m_a + m_b + m_c) / 2;
	float S = sqrt(s * (s - m_a) * (s - m_b) * (s - m_c));
	void outputS()
	{
		cout << "The Rectangle's S =  " << S << endl;
	}
private:
	float m_a;
	float m_b;
	float m_c;
};
int main()
{
	Shape* p = new Circle(34);
	p->m_Shape();
	p->outputS();
	cout << "-------------------------" << endl;
	delete p;
	p = new Rectangle(2, 4);
	p->m_Shape();
	p->outputS();
	cout << "-------------------------" << endl;
	delete p;
	p = new Triangle(1, 4, 8);
	p->m_Shape();
	p->outputS();
	system("pause");
	return 0;
}