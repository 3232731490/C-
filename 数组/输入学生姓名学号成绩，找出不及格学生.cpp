#include<iostream>
#include<string>

using namespace std;
int n, b[50], c[50];
string a[50];
int main()
{
	void input( int n);
	void find( int n);
	cout << "请输入学生个数：" << endl;
	cin >> n;
	input( n);
	find( n);
	system("pause");
	return 0;
}
void input( int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的姓名，学号，成绩" << endl;
		cin >> a[i] >> b[i] >> c[i];
	}
}
void find(int n)
{
	cout << "不及格的学生有" << endl;
	for (int i = 0; i < n; i++)
	{
		if (c[i] < 60)
		{
			cout <<"姓名："<< a[i] <<"学号："<< b[i] <<"成绩："<< c[i] << endl;
		}
	}

}
