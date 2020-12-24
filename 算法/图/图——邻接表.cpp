#include<iostream>
using namespace std;
#define Maxmize 20

struct EdgeNode  //边表节点
{
	int adjvex;
	int weight;  //储存权值，非网图则不需要
	EdgeNode* next;
};

struct VertexNode  //顶点表节点
{
	char data;
	EdgeNode* firstedge;   //表头头指针
};

struct  GraphList  //顶点表
{
	VertexNode graph[Maxmize];
	int numVertexes, numEdges;  //图中顶点和边数
};

int main()
{
	//建立一个无向图
	GraphList Graph;
	
	int i, j;
	cout << "请输入顶点数和边数：" << endl;
	cin >> i >> j;

	Graph.numVertexes = i, Graph.numEdges = j;

	//读入顶点信息，建立顶点表
	for (int k = 0; k < i; k++)
	{
		char data;
		cin >> data;
		Graph.graph[i].data = data;   //读入顶点信息
		Graph.graph[i].firstedge = NULL;  //将表置为空表
	}
	for (int k = 0; k < j; k++)
	{
		cout << "输入边的坐标（vi,vj）" << endl;
		int vi, vj;
		cin >> vi >> vj;
		EdgeNode* edge1 = new EdgeNode;
		
		edge1->adjvex = vj;
		edge1->next = Graph.graph[vi].firstedge;
		Graph.graph[vi].firstedge = edge1;
	
		EdgeNode* edge2 = new EdgeNode;
		edge2->adjvex = vi;
		edge2->next= Graph.graph[vj].firstedge;
		Graph.graph[vj].firstedge = edge2;

	}
	system("pause");
	return 0;
}