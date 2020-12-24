#include <iostream>
#include<string>
#include<cmath>
using namespace std;
class Triangle
{
public:
	Triangle(float a, float b, float c) :m_a(a), m_b(b), m_c(c) { m_s = (a + b + c) / 2; };
	float outputm_S()
	{
		return sqrt(m_s * (m_s - m_a) * (m_s - m_b) * (m_s - m_c));
	}

private:
	float m_a;
	float m_b;
	float m_c;
	float m_s;
};

int main()
{
	cout << "请输入三角形三边长：" << endl;
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b > c&& a + c > b&& b + c > a&& a > 0 && b > 0 && c > 0)
	{
		Triangle  Tri(a, b, c);
		float S = Tri.outputm_S();
		cout << "The Triangle's S=   " << S << endl;
	}
	else cerr << "三角形三边长输入有误！" << endl;
	system("pause");
	return 0;
}