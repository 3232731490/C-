#include<iostream>
using namespace std;
#define Maxmize 15
#define initnum 65535
struct MGraph
{
	char data[Maxmize];
	int Node[Maxmize][Maxmize];
	int numVertexes, numEdges;
};

void creatGraph(MGraph* G)
{
	cout << "输入图的顶点数和边数" << endl;
	cin >> G->numVertexes >> G->numEdges;
	for (int i = 0; i < G->numVertexes; i++)
	{
		cin >> G->data[i];
	}
	for (int i = 0; i < G->numVertexes; i++)
	{
		for (int j = 0; j < G->numVertexes; j++)
		{
			G->Node[i][j] = initnum;
		}
		G->Node[i][i] = 0;
	}
	for (int k = 0; k < G->numEdges; k++)
	{
		cout << "请输入边（vi,vj）上的下标i 和下标j 和权w" << endl;
		int i, j, w;
		cin >> i >> j >> w;
		G->Node[i][j] = w;
		
		G->Node[j][i] = G->Node[i][j]; //无向图，矩阵对称
	}
}
int main()
{
	MGraph* G = new MGraph;
	creatGraph(G);

	system("pause");
	return 0;
}