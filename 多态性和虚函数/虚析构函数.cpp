#include <iostream>
#include<string>
using namespace std;
class Point
{
public:
	Point(float a, float b)
	{
		m_x = a;
		m_y = b;
	}
	virtual ~Point()
	{
		cout << "execuing Point destuctor" << endl;
	}

private:
	float m_x, m_y;
};
class Circle:public Point
{
public:
	Circle(float a, float b, float r):Point(a,b)
	{
		m_r = r;
	}
	~Circle()
	{
		cout << "execuing Circle destuctor" << endl;
	}
private:
	float m_r;
};
int main()
{
	Point* p = new Circle(3.2,4.5,5);
	delete p;
	system("pause");
	return 0;
}