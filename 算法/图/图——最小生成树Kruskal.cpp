#include<iostream>
using namespace std;
#define maxmize 20

struct Edgearc
{
	int begin;
	int finish;
	int w;

};

struct Graph
{
	char data[maxmize];
	Edgearc Edge[maxmize];
	int numvetexes, numEdges;
};

int find(int *p ,int f)
{
	while(p[f] > 0)
	{
		f = p[f];
	}
	return f;
}

void Kruskal(Graph* graph)
{
	int parent[maxmize];
	int m, n;
	for (int i = 0; i < graph->numvetexes; i++)
	{
		parent[i] = 0;
	}
	for (int i = 0; i < graph->numvetexes; i++)
	{
		m = find(parent, graph->Edge[i].begin);
		n = find(parent, graph->Edge[i].finish);
		if (m != n)
		{
			parent[m] = n;
			cout << "( " << graph->Edge[i].begin << "--" << graph->Edge[i].finish << " )  " << graph->Edge[i].w << endl;
		}
	}

}

int main()
{

	Graph* mygraph = new Graph;
	cout << "输入顶点和边数：" << endl;
	cin >> mygraph->numvetexes >> mygraph->numEdges;

	cout << "输入顶点信息：" << endl;
	for (int i = 0; i < mygraph->numvetexes; i++)
	{
		cin >> mygraph->data[i];
	}

	cout << "输入边信息： （Vi,Vj）和 w" << endl;
	for (int i = 0; i < mygraph->numEdges; i++)
	{
		cin >> mygraph->Edge[i].begin >> mygraph->Edge[i].finish >> mygraph->Edge[i].w;
	}

	for (int i = 0; i < mygraph->numEdges; i++)
	{
		for (int j = i + 1; j < mygraph->numEdges; j++)
		{
			if (mygraph->Edge[i].w > mygraph->Edge[j].w)
			{
				Edgearc temp=mygraph->Edge[i];
				mygraph->Edge[i] = mygraph->Edge[j];
				mygraph->Edge[j] = temp;
			}
		}
	}

	Kruskal(mygraph);

	system("pause");
	return 0;
}