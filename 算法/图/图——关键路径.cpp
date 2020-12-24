#include<iostream>
#include<stack>
using namespace std;
#define maximum 20
struct Edge
{
	int adjvet;
	int weight;
	Edge* next;
};

struct GraphNode
{
	int in;  //入度
	Edge* firstEdge;  
	char data;
};


struct Graph
{

	GraphNode graph[maximum];
	int numvertexes, numEdge;
};

void creatGraph(Graph* G)
{
	int i=0;
	cout << "输入顶点和边数：" << endl;
	cin >> G->numvertexes >> G->numEdge;
	cout << "输入顶点信息：" << endl;
	for (i = 0; i < G->numvertexes; i++)  //初始化图
	{
		cin >> G->graph[i].data;
		G->graph[i].in = 0;
		G->graph[i].firstEdge = NULL;
	}

	for (i = 0; i < G->numEdge; i++)
	{
		cout << "输入边(Vi,Vj) 权w :" << endl;
		int vi, vj,w;
		cin >> vi >> vj>>w;
		Edge* e = new Edge;
		e->adjvet = vj;
		e->weight = w;
		e->next = G->graph[vi].firstEdge;
		G->graph[vi].firstEdge = e;
	}

	for (i = 0; i < G->numvertexes; i++) //计算入度
	{
		Edge* p = G->graph[i].firstEdge;
		while (p)
		{
			G->graph[p->adjvet].in++;
			p = p->next;
		}
	}

}
int* etv, * ltv;  //最早发生时间和最晚发生时间数组
stack<int> S2;  //储存拓扑序列

int TopologicalSort(Graph* G)
{
	int i, j,count=0;
	stack<int> S;  
	for (i = 0; i < G->numvertexes; i++)
	{
		if (G->graph[i].in == 0)
		{
			S.push(i);
		}
	}
	Edge* p;
	etv = new int[G->numvertexes];
	for (int i = 0; i < G->numvertexes; i++)
	{
		etv[i] = 0;
	}

	while (!S.empty())
	{
		j = S.top();
		S2.push(j);
		count++;
		S.pop();
		p = G->graph[j].firstEdge;
		while (p)
		{
		
			if (--G->graph[p->adjvet].in == 0)
			{
				S.push(p->adjvet);
			}
			if ((etv[j] + p->weight) > etv[p->adjvet])
			{
				etv[p->adjvet] = etv[j] + p->weight;
			}
			p = p->next;
		}
	}
	if (count < G->numvertexes)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void CriticalPath(Graph* G)
{
	Edge* e;
	int ete, lte;    //活动最早发生时间和最迟发生时间变量
	TopologicalSort(G); //求拓扑序列 计算etv数组和S2的值
	ltv = new int[G->numvertexes];
	for (int i = 0; i < G->numvertexes; i++)
	{
		ltv[i] = etv[G->numvertexes - 1];  //初始化
	}
	int j = 0;
	while (!S2.empty())
	{
		j = S2.top();
		S2.pop();
		e = G->graph[j].firstEdge;
		while (e)
		{
			int k = e->adjvet;
			if (ltv[k] - e->weight < ltv[j])
			{
				ltv[j] = ltv[k] - e->weight;  //求最晚时间数组
			}
			e = e->next;
		}
	}
		for (int i = 0; i < G->numvertexes; i++)
		{
			e = G->graph[i].firstEdge;
			while (e)
			{
				int k = e->adjvet;
				ete = etv[i];
				lte = ltv[k] - e->weight;
				if (ete == lte)
				{
					cout << "<V" << G->graph[i].data << ",V" << G->graph[k].data << "> length :" << e->weight <<endl;
				}
				e = e->next;
			}
		}
	}

int main()
{
	Graph* mygraph = new Graph;
	creatGraph(mygraph);
	CriticalPath(mygraph);
	system("pause");
	return 0;
}