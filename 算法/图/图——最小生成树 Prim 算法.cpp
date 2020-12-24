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


void MiniSpanTree_Prim(MGraph* graph)
{
	int adjvet[Maxmize];
	int lowcost[Maxmize];
	adjvet[0] = 0;
	lowcost[0] = 0;
	int k ;
	
	for (int i = 1; i < graph->numVertexes; i++)
	{

		adjvet[i] = 0;
		lowcost[i] = graph->Node[0][i];
	}
	for (int i = 1; i < graph->numVertexes; i++)
	{
		int min = initnum;
		int j = 1;
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
		cout << "( " << adjvet[k] <<"--"<< k << " ) ";
		lowcost[k] = 0;
		for (j = 1; j < graph->numVertexes; j++)
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
	cout << "����ͼ�Ķ������ͱ���" << endl;
	cin >> G->numVertexes >> G->numEdges;
	cout << "���붥����Ϣ" << endl;
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
		cout << "������ߣ�vi,vj���ϵ��ϱ�i ���±�j(��Χ�� " << "0-" << G->numVertexes - 1 << ")" << "��Ȩw " << endl;
	
		cin >> vi >> vj >> w;
		G->Node[vi][vj] = w;

		G->Node[vj][vi] = G->Node[vi][vj];
	}
}
int main()
{
	MGraph* G = new MGraph;
	creatGraph(G);
	MiniSpanTree_Prim(G);
	system("pause");
	return 0;
}