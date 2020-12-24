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


void MiniSpanTree_Prim(MGraph* graph,int index)
{
	int adjvet[Maxmize];
	int lowcost[Maxmize];

	int k;

	for (int i = 0; i < graph->numVertexes; i++)
	{

		adjvet[i] = index;
		lowcost[i] = graph->Node[index][i];
	}
	lowcost[index] = 0;

	for (int i = 1; i < graph->numVertexes; i++)
	{
		int min = initnum;
		int j = 0;
		k = 0;
		while (j < graph->numVertexes)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		cout << "( " << adjvet[k] << "--" << k << " ) " << min<<endl;
		lowcost[k] = 0;
		for (j = 0; j < graph->numVertexes; j++)
		{
			if (lowcost[j] != 0 && graph->Node[k][j] < lowcost[j])
			{
				lowcost[j] = graph->Node[k][j];
				adjvet[j] = k;
			}
		}
	}

}

void creatGraph(MGraph* G)
{
	cout << "输入图的顶点数和边数" << endl;
	cin >> G->numVertexes >> G->numEdges;
	cout << "输入顶点信息：" << endl;
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
		int vi, vj, w;
		cout << "请输入边（vi,vj）上的上标i 和下标j(范围： " << "0-" << G->numVertexes - 1 << ")" << "和权w " << endl;

		cin >> vi >> vj >> w;
		G->Node[vi][vj] = w;

		G->Node[vj][vi] = G->Node[vi][vj];
	}
}
int main()
{
	MGraph* G = new MGraph;
	creatGraph(G);

	for (int i = 0; i < G->numVertexes; i++)
	{
		for (int j = 0; j < G->numVertexes; j++)
		{
			cout << G->Node[i][j] << " \t";
		}
		cout << endl;
	}
	int index;
	cout << "输入Prim 算法起点：" << endl;
	cin >> index;
	MiniSpanTree_Prim(G, index);
	system("pause");
	return 0;
}