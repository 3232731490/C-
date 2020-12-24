#include<iostream>
using namespace std;
#define Maxmize 20
#define Max 65535

//邻接矩阵 遍历图

struct EdgeNode
{
	int Edge[Maxmize][Maxmize];
	int weight;  //权值，没有可以省略
};

struct Graph
{
	char data[Maxmize];
	int numvertexes, numedges;
};

int visited[Maxmize] = { 0 };
void visitGraph(Graph *graph ,EdgeNode *Edge ,int index)
{
	visited[index] = 1;
	cout << graph->data[index];
	for (int i = 0; i < graph->numvertexes; i++)
	{
		if (Edge->Edge[index][i] == 1 && visited[index] ==0)
		{
			visitGraph(graph, Edge, i);
		}
	
	}

}
int main()
{
	Graph *mygraph =new Graph;
	EdgeNode edge;
	cout << "输入顶点数和边数" << endl;
	int i, j;
	cin >> i >> j;
	mygraph->numedges = j, mygraph->numvertexes = i;
	for (int k = 0; k < i; k++)
	{
		cin >> mygraph->data[k];  //输入顶点数据
	}

	//邻接矩阵初始化
	for (int k = 0; k < i; k++)
	{
		for (int n = 0; n < i; n++)
		{
			edge.Edge[i][j] = 0;
		}
	}

	for (int k = 0; k < j; k++)
	{
		cout << "输入边的信息（Vi,Vj）" << endl;
		int vi, vj;
		cin >> vi >> vj;
		edge.Edge[i][j] = 1;
		edge.Edge[j][i] = edge.Edge[i][j];
	}

	cout << "输入起始查询节点" << endl;
	int index;
	cin >> index;
	visitGraph(mygraph, &edge, index);

	for(int k=0;k<i;k++)  //如果是连通图 则不执行此循环
		if(visited[k]==0)
	visitGraph(mygraph, &edge, k);

	system("pause");
	return 0;
}