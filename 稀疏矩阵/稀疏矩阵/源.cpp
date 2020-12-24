#include<iostream>
using namespace std;
#include<time.h>
#define random(x) (rand()%x)
#define RM 100
#define CM 100
#define MaxSize 10


struct TupNode {
	
	int r;  //��
	int c;  //��
	int data; //����
};

struct TSMatris {

	int r;  //��
	int c;  //��
	int nums; //������
	TupNode data[MaxSize];  //����

};

void createMat(TSMatris& T, int A[100][100])
{
	T.r = RM;
	T.c = CM;
	T.nums = 0;
	for (int i = 0; i < RM; i++)
	{
		for (int j = 0; j < CM; j++)
		{
			if (A[i][j] != 0)
			{
				T.data[T.nums].data = A[i][j];
				T.data[T.nums].r = i;
				T.data[T.nums].c = j;
				T.nums++;
			}
		}
	}
}
int main()
{
	int A[RM][CM];
	for (int i = 0; i < RM; i++)
	{
		for (int j = 0; j < CM; j++)
		{
			A[i][j] = 0;
		}
	}
		cout << "������Ҫ�洢�������ݣ�(<=10)" << endl;
		int n;
		cin >> n;
		int randomr = 0;
		int randomc = 0;
		int data;
		srand((int)time(0));
		TSMatris T;
		for (int i = 0; i < n; i++)
		{
			randomr = random(100);
			randomc = random(100);
			cout << "�������" << (i + 1) << "�����ݣ�" << endl;
			cin >> data;
			A[randomr][randomc] = data;
		}

		createMat(T, A);
		
	system("pause");
	return 0;
}