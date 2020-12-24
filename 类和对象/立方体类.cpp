#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
class Cube
{
public:
	void set_Cube()  //输入长宽高
	{
		cout << "请输入长方体的长：" << endl;
		cin >> L;
		cout << "请输入长方体的宽：" << endl;
		cin >> W;
		cout << "请输入长方体的高：" << endl;
		cin >> H;
}
	int V()  //计算长方体的体积
	{
		return L * W * H;
	}
	void showV()
	{
		cout << V();
	}
private:
	int L;
	int W;
	int H;
};

int main()
{
	Cube a,b,c;
	a.set_Cube();
	a.V();
	b.set_Cube();
	b.V();
	c.set_Cube();
	c.V();
	cout << "三个长方体的体积为：" << endl;
	a.showV(); cout << "  ";
	b.showV(); cout << "  ";
	c.showV(); cout << "  ";

	system("pause");
	return 0;
}
