#include<iostream>
#include<queue>
using namespace std;
#define maxmize 20
#define initial 65535
struct graphList
{
	char data[maxmize];
	int arc[maxmize][maxmize];
	int numVertexes, verEdgenum;
};
int visted[maxmize] = {0};

void BFS(graphList* graph)
{
	queue<int> Q;
	int k = 0;
	for (int i = 0; i < graph->numVertexes; i++)
	{
		if (visted[i] == 0)
		{
			cout << graph->data[i];

			visted[i] = 1;
			Q.push(i);

			while (!Q.empty())
			{
				i=Q.front();
				Q.pop();
				for (int j = 0; j < graph->numVertexes; j++)
				{
					if (!visted[j] && graph->arc[i][j] == 1)
					{
						visted[j] = 1;
						cout << graph->data[j];
						Q.push(j);
					}
				}
			}
		}
	}
}
int main()
{
	graphList* graph = new graphList;
	int i, j;
	cout << "输入图的顶点和边数：" << endl;
	cin >> i >> j;
	graph->numVertexes = i;
	graph->verEdgenum = j;
	cout << "输入顶点数据" << endl;
	for (int k = 0; k < i; k++)
	{
		cin >> graph->data[k];

	}
	for (int k = 0; k < i; k++)
	{
		for (int n = 0; n < i; n++)
		{
			graph->arc[i][n] = initial;
		}
	}
	for (int k = 0; k < j; k++)
	{
		cout << "输入边的信息：" << endl;
		int vi, vj;
		cin >> vi >> vj;
		graph->arc[vi][vj] = 1;
		graph->arc[vj][vi] = graph->arc[vi][vj];

	}


	BFS(graph);

	system("pause");
	return 0;
}