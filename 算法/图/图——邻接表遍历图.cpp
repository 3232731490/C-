#include<iostream>
using namespace std;
#define Maxmize 20

//邻接表 遍历无向图
struct EdgeNode
{
	int adjvex;
	EdgeNode* next;

};

struct GraphNode
{
	EdgeNode* firstEdge;
	char data;
};

struct GraphList
{
	GraphNode Graph[Maxmize];
	int numVertexes, numEdges;
};

int visited[Maxmize] = {0};
void VisitGraph(GraphList* graph, int index)
{
	visited[index] = 1;
	cout << graph->Graph[index].data << " ";

	EdgeNode* p = graph->Graph[index].firstEdge;
	while (p)
	{
		if (visited[p->adjvex] == 0)
		{
			VisitGraph(graph, p->adjvex);
		}
		p = p->next;
	}

}

int main()
{
	GraphList* mygraph = new GraphList;
	int i, j;
	cout << "输入图的顶点数和边数：" << endl;
	cin >> i >> j;
	mygraph->numEdges = j, mygraph->numVertexes = i;
	
	//输入顶点值，初始化表头指针为NULL
	cout << "输入顶点数据" << endl;
	for (int k = 0; k < i; k++)
	{
		cin >> mygraph->Graph[k].data;
		mygraph->Graph[k].firstEdge = NULL;
	}

	//输入边的信息
	for (int k = 0; k < j; k++)
	{
		cout << "输入边 （Vi,,Vj）:" << endl;
		int vi, vj;
		cin >> vi >> vj;
		EdgeNode* e1 = new EdgeNode;
		e1->adjvex = vj;
		e1->next = mygraph->Graph[vi].firstEdge;
		mygraph->Graph[vi].firstEdge = e1;

		EdgeNode* e2 = new EdgeNode;
		e2->adjvex = vi;
		e2->next = mygraph->Graph[vj].firstEdge;
		mygraph->Graph[vj].firstEdge = e2;
	}

	int index;
	cout << "输入起始遍历点" << endl;
	cin >> index;
	VisitGraph(mygraph, index);
	for (int k = 0; k < i; k++)  //若为连通图，则此循环不执行
	{
		if (visited[k] == 0)
		{
			VisitGraph(mygraph, k);
		}
	}
	delete mygraph;
	system("pause");
	return 0;
}