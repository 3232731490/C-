#include<iostream>
#include<stack>
#include<algorithm>  //标准算法头文件
using namespace std;

//stack 栈容器 先进后出 不允许遍历 只有栈顶才能被访问到
void test()
{
	stack<int> s;
	
	//入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "开始栈的大小： " << s.size() << endl;

	//只要栈不为空，查看栈顶，并且执行出栈
	while (!s.empty())
	{
		//查看栈顶元素
		cout << "栈顶元素  :  " << s.top() << endl;

		//出栈
		s.pop();
	}

	cout << "结束栈的大小： " << s.size() << endl;
}

int main()
{
	test();
	return 0;
}