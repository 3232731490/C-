#include <iostream>
using namespace std;
class Array
{
	friend void operator<<(ostream& cout, Array& array);
	friend void operator>>(istream& cin, Array &array);
public:

	Array operator+(Array& p)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				this->a[i][j] = this->a[i][j] + p.a[i][j];
			}
		}
		return *this;
	}

private:
	int a[2][3];
};
void operator<<(ostream& cout ,Array &array)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << array.a[i][j] << "  ";
		}
		cout << '\t';
		cout << endl;
	}
	cout << endl;
}
void operator>>(istream& cin, Array &array)
{
	for (int j = 0; j < 2; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			cin >> array.a[j][k];
		}
	}
}
int main()
{
	cout << "输入a1 数组：" << endl;
	Array a1;
	cin >> a1;
	cout << "输入a2 数组：" << endl;
	Array a2;
	cin >> a2;
	cout << "a1矩阵：" << endl;
	cout << a1;
	cout << "a2矩阵：" << endl;
	cout << a2;
	a1 = a1 + a2;
	cout << "两个矩阵相加为：" << endl;
	cout << a1;
	system("pause");
	return 0;
}

