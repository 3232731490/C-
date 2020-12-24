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
		cout << "�����(Vi,Vj) Ȩw :" << endl;
		int vi, vj,w;
		cin >> vi >> vj>>w;
		Edge* e = new Edge;
		e->adjvet = vj;
		e->weight = w;
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
int* etv, * ltv;  //���緢��ʱ���������ʱ������
stack<int> S2;  //������������

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
	int ete, lte;    //����緢��ʱ�����ٷ���ʱ�����
	TopologicalSort(G); //���������� ����etv�����S2��ֵ
	ltv = new int[G->numvertexes];
	for (int i = 0; i < G->numvertexes; i++)
	{
		ltv[i] = etv[G->numvertexes - 1];  //��ʼ��
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
				ltv[j] = ltv[k] - e->weight;  //������ʱ������
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