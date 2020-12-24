#include<iostream>
#include<cmath>
using namespace std;
#define S(a,b,c) (a+b+c)/2
#define area(a,b,c,S) sqrt(S*(S-a)*(S-b)*(S-c))
int main()
{
	cout << "请输入三角形的三边长：" << endl;
	int a, b, c;
	double area;
	cin >> a >> b >> c;
	if (a + b > c&& a + c > b&& c + b > a)
	{
		area=area(a, b, c, S(a, b, c));
	}
	cout << "area=" << area;
		return 0;
}