#include<iostream>
#include<queue>
using namespace std;
#define maxmize 20

struct Edge
{
	int adjext;
	Edge* next;
};

struct GraphNode
{
	char data;
	Edge* firstEdge;
	
};

struct GraphList
{
	GraphNode graph[maxmize];
	int numvertexes, numedges;
};
int visited[maxmize];
void BFS(GraphList* Graph)
{
	queue<int> Q;
	for (int i = 0; i < Graph->numvertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			cout << Graph->graph[i].data<<" ";
			Q.push(i);

			while (!Q.empty())
			{
				i = Q.front();
				Q.pop();
				Edge* p = Graph->graph[i].firstEdge;
				while (p)
				{
					if (!visited[p->adjext])
					{
						visited[p->adjext] = 1;
						cout << Graph->graph[p->adjext].data << " ";
						Q.push(p->adjext);
						
					}
					p = p->next;
				}
			}
		}
	}

}
int main()
{
	cout << "输入顶点和边" << endl;
	int i, j;
	cin >> i >> j;
	GraphList* mygraph = new GraphList;
	mygraph->numedges = j, mygraph->numvertexes = i;
	cout << "输入顶点信息" << endl;
	for (int k = 0; k < i; k++)
	{
		cin >> mygraph->graph[k].data;
		visited[k] = 0;
		mygraph->graph[k].firstEdge = NULL;
	}

	for (int k = 0; k < j; k++)
	{
		cout << "输入边（Vi,Vj）" << endl;
		int vi, vj;
		cin >> vi >> vj;
		Edge* e1 = new Edge;
		e1->adjext = vj;
		e1->next = mygraph->graph[vi].firstEdge;
		mygraph->graph[vi].firstEdge = e1;

		Edge* e2 = new Edge;
		e2->adjext = vi;
		e2->next = mygraph->graph[vj].firstEdge;
		mygraph->graph[vj].firstEdge = e2;
	}
	BFS(mygraph);
	system("pause");
	return 0;
}