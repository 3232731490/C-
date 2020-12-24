#include<iostream>
#include<ctime>
using namespace std;
#define X 8
#define Y 8

int chess[X][Y];

int nextXY(int &x, int &y, int count)
{
	switch (count)
	{
	case 0:
		if (x - 2 >= 0 && y - 1 >= 0 && !chess[x - 2][y - 1])
		{
			x -= 2;
			y -= 1;
			return 1;
		}
		break;
	case 1:
		if (x + 2 < X && y - 1 >= 0 && !chess[x + 2][y - 1])
		{
			x += 2;
			y -= 1;
			return 1;
		}
		break;
	case 2:
		if (x + 2<X && y + 1<Y && !chess[x + 2][y+1])
		{
			x += 2;
			y += 1;
			return 1;
		}
		break;
	case 3:
		if (x + 1 < X && y + 2 < Y && !chess[x + 1][y + 2])
		{
			x += 1;
			y += 2;
			return 0;
		}
		break;
	case 4:
		if (x - 2 >= 0 && y + 1 < Y && !chess[x - 2][y + 1])
		{
			x -= 2;
			y += 1;
			return 1;

		}
		break;
	case 5:
		if (x - 1 >= 0 && y + 2 < Y && !chess[x - 1][y + 2])
		{
			x -= 1;
			y += 2;
			return 1;

		}
		break;
	case 6:
		if (x - 1 >= 0 && y - 2 >= 0 && !chess[x - 1][y - 2])
		{
			x -= 1;
			y -= 2;
			return 1;
		}
		break;
	case 7:
		if (x + 1 < X && y - 2 >= 0 && !chess[x + 1][y - 2])
		{
			x += 1;
			y -= 2;
			return 1;
		}
		break;
	default :
		break;
	
	}
	return 0;
}
void myprint();
int traval(int x, int y, int tag)
{
	int x1, y1;  
	int count = 0;  //记录在一个坐标上跳转的次数
	if (tag == X * Y)
	{
		myprint();
		return 1;
	}
	chess[x][y] = tag;
	x1 = x, y1 = y;
	int flag;
	flag = nextXY(x1, y1, count);
	while (0==flag && count < 7)
	{
		count++;
		flag = nextXY(x1, y1, count);
	}

	while (flag)
	{
		if (traval(x1, y1, tag+1))
		{
			return 1;
		}

		x1 = x, y1 = y;
		flag = nextXY(x1, y1, count+1);
		while (0==flag&&count<7)
		{
			count++;
			flag = nextXY(x1, y1, count );
		}
	}

	if (0 == flag)
	{
		chess[x][y] = 0;
	}
	return 0;
}

void myprint()
{

	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			cout << chess[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			chess[i][j] = 0;
		}
	}
	clock_t start, finish;
	int x, y;
	cout << "输入起始坐标：（x,y）" << endl;
	cin >> x >> y;
	start=clock();
	traval(x, y, 1);
	finish = clock();

	cout << "本次计算耗时：" <<(double)(finish-start)/CLOCKS_PER_SEC<< endl;
		
	system("pause");
	return 0;
}