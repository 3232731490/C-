#include<iostream>
#include<stack>
using namespace std;
#define maximum 20
struct Edge
{
	int adjvet;
	Edge* next;
};

struct GraphNode
{
	int in;  //���
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
	cout << "���붥��ͱ�����" << endl;
	cin >> G->numvertexes >> G->numEdge;
	cout << "���붥����Ϣ��" << endl;
	for (i = 0; i < G->numvertexes; i++)  //��ʼ��ͼ
	{
		cin >> G->graph[i].data;
		G->graph[i].in = 0;
		G->graph[i].firstEdge = NULL;
	}

	for (i = 0; i < G->numEdge; i++)
	{
		cout << "�����(Vi,Vj) :" << endl;
		int vi, vj;
		cin >> vi >> vj;
		Edge* e = new Edge;
		e->adjvet = vj;
		e->next = G->graph[vi].firstEdge;
		G->graph[vi].firstEdge = e;
	}

	for (i = 0; i < G->numvertexes; i++) //�������
	{
		Edge* p = G->graph[i].firstEdge;
		while (p)
		{
			G->graph[p->adjvet].in++;
			p = p->next;
		}
	}

}

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
	while (!S.empty())
	{
		j = S.top();
		cout << G->graph[j].data << " ";
		count++;
		S.pop();
		p = G->graph[j].firstEdge;
		while (p)
		{
		
			if (--G->graph[p->adjvet].in == 0)
			{
				S.push(p->adjvet);
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
int main()
{
	Graph* mygraph = new Graph;
	creatGraph(mygraph);
	int i=TopologicalSort(mygraph);
	if (i )
	{
		cout << "��ͼΪAOVͼ����������ɹ�" << endl;
	}
	else
	{
		cout << "��ͼΪ��AOVͼ����������ʧ��" << endl;
	}
}