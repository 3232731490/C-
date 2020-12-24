#include<iostream>
using namespace std;

#define Maxmize 20
#define initial 65535

struct Graph
{
	char data[Maxmize];
	int Edge[Maxmize][Maxmize];
	int numvertexes, numedge;

};

int Shortpath[Maxmize][Maxmize];
int Pathmatirx[Maxmize][Maxmize];

void Floyd(Graph* G)
{
	//初始化
	for (int i = 0; i < G->numvertexes; i++)
	{
		for (int j = 0; j < G->numvertexes; j++)
		{
			Shortpath[i][j] = G->Edge[i][j];
			Pathmatirx[i][j] = j;
		}
	}

	for (int k = 0; k < G->numvertexes; k++)  //中间点
	{
		for (int v = 0; v < G->numvertexes; v++)  //起点
		{
			for (int w = 0; w < G->numvertexes; w++)  //终点
			{
				if (Shortpath[v][w] > Shortpath[v][k]+ Shortpath[k][w])
				{
					Shortpath[v][w] = Shortpath[v][k] + Shortpath[k][w];
					Pathmatirx[v][w] = k;
				}
			}
		}
	}


}


void PrintPath(Graph* G)
{
	for (int v = 0; v < G->numvertexes; v++)
	{
		for (int w = v + 1; w < G->numvertexes; w++)
		{
			cout << "V" << v << " -> V" << w << " weight: " << Shortpath[v][w] << " :";

			cout << "V" << v << " ->" << " ";  //打印起点
			int k = Pathmatirx[v][w];
			while (k != w)
			{
				cout << "V" << k << " -> ";
				k = Pathmatirx[k][w];
			}

			cout << "V" << w << endl;  //打印终点
		}
		cout << endl;
	}
}
int main()
{
	cout << "输入顶点和边数：" << endl;
	Graph* mygraph = new Graph;
	cin >> mygraph->numvertexes >> mygraph->numedge;

	cout << "输入顶点信息：" << endl;
	for (int i = 0; i < mygraph->numvertexes; i++)
	{
		cin >> mygraph->data[i];
	}
	
	for (int i = 0; i < mygraph->numvertexes; i++)
	{
		for (int j = 0; j < mygraph->numvertexes; j++)
		{
			mygraph->Edge[i][j] = initial;
		}
		mygraph->Edge[i][i] = 0;
	}
	for (int i = 0; i < mygraph->numedge; i++)
	{
		int vi, vj, w;
		cout << "输入边（Vi,Vj） 权w" << endl;
		cin >> vi >> vj >> w;
		mygraph->Edge[vi][vj] = w;
		mygraph->Edge[vj][vi] = w;

	}

	Floyd(mygraph);
	PrintPath(mygraph);

	system("pause");
	return 0;
}