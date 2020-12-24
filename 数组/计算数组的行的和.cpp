#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int score[3][3] =
	{ {100,100,100},
	{90,50,100},
	{60,70,80}
	};
	int score1[3] = {};
	for(int i = 0; i < 3;i++ )
	{
		for (int j = 0; j < 3; j++)
		{
			score1[i] = score1[i] + score[i][j];
		}
	}
	cout << "张三总成绩为：" << score1[0] << endl;
	cout << "李四总成绩为：" << score1[1]<<endl;
	cout << "王五总成绩为：" << score1[2]<<endl;
	return 0;
}