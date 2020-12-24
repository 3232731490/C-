#include<iostream>
using namespace std;
#define Maxmize 20

//�ڽӱ� ��������ͼ
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
	cout << "����ͼ�Ķ������ͱ�����" << endl;
	cin >> i >> j;
	mygraph->numEdges = j, mygraph->numVertexes = i;
	
	//���붥��ֵ����ʼ����ͷָ��ΪNULL
	cout << "���붥������" << endl;
	for (int k = 0; k < i; k++)
	{
		cin >> mygraph->Graph[k].data;
		mygraph->Graph[k].firstEdge = NULL;
	}

	//����ߵ���Ϣ
	for (int k = 0; k < j; k++)
	{
		cout << "����� ��Vi,,Vj��:" << endl;
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
	cout << "������ʼ������" << endl;
	cin >> index;
	VisitGraph(mygraph, index);
	for (int k = 0; k < i; k++)  //��Ϊ��ͨͼ�����ѭ����ִ��
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