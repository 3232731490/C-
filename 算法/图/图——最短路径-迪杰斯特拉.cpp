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

int Shortpathtable[Maxmize];  //储存各个顶点的最短路径的权值和
int Patharc[Maxmize];  //储存最短路径下标的数组

void Dijkstra(Graph* G ,int v0)
{
	int min,k;
	int final[Maxmize];  //final[n]=1表示求得顶点v0-vn的最短路径
	for (int i = 0; i < G->numvertexes; i++)
	{
		final[i] = 0;
		Shortpathtable[i] = G->Edge[v0][i];
		Patharc[i] = 0;
	}
	Shortpathtable[v0] = 0;
	final[v0] = 1;

	for (int i = 1; i < G->numvertexes; i++)
	{
		min = initial;
		for (int j = 0; j < G->numvertexes; j++)
		{
			if (!final[j] && Shortpathtable[j] < min)
			{
				k = j;
				min = Shortpathtable[j];
			}
		}
		final[k] = 1;
		for (int w = 0; w < G->numvertexes; w++)
		{
			if (!final[w] && (min + G->Edge[k][w] < Shortpathtable[w]))
			{
				Shortpathtable[w] = min + G->Edge[k][w];

				Patharc[w] = k;
			}
		}
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
		Shortpathtable[i] = 0;
		Patharc[i] = 0;
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

	int m;
	cout << "请输入从哪个顶点出发" << endl;
	cin >> m;
	Dijkstra(mygraph, m);
	cout << "从 V" << m << "到各个顶点的最短路径的权值为：" << endl;
	for (int i = 0; i < mygraph->numvertexes; i++)
	{
		cout <<Shortpathtable[i] << " ";
	}
	system("pause");
	return 0;
}