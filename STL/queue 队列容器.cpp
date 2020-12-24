#include<iostream>
#include<queue>
#include<algorithm>  //标准算法头文件
using namespace std;

//queue 队列容器 先进先出 不允许遍历 只有队头、队尾能被外界访问

void test()
{
	queue < int> q;
	
	//入队
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	cout << "队列容器开始的大小为：  " << q.size() << endl;

	while (!q.empty())
	{
		//查看队头
		cout << "此时队头： "<<q.front() << endl;
		
		//查看队尾
		cout <<"此时队尾： "<< q.back() << endl;
		//出队
		q.pop();
	}

	//队列大小
	cout << "队列容器结束的大小为：  " << q.size() << endl;
}

int main()
{
	test();
	return 0;
}