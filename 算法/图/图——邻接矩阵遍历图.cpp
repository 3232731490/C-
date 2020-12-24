#include<iostream>
using namespace std;
#define Maxmize 20
#define Max 65535

//�ڽӾ��� ����ͼ

struct EdgeNode
{
	int Edge[Maxmize][Maxmize];
	int weight;  //Ȩֵ��û�п���ʡ��
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
	cout << "���붥�����ͱ���" << endl;
	int i, j;
	cin >> i >> j;
	mygraph->numedges = j, mygraph->numvertexes = i;
	for (int k = 0; k < i; k++)
	{
		cin >> mygraph->data[k];  //���붥������
	}

	//�ڽӾ����ʼ��
	for (int k = 0; k < i; k++)
	{
		for (int n = 0; n < i; n++)
		{
			edge.Edge[i][j] = 0;
		}
	}

	for (int k = 0; k < j; k++)
	{
		cout << "����ߵ���Ϣ��Vi,Vj��" << endl;
		int vi, vj;
		cin >> vi >> vj;
		edge.Edge[i][j] = 1;
		edge.Edge[j][i] = edge.Edge[i][j];
	}

	cout << "������ʼ��ѯ�ڵ�" << endl;
	int index;
	cin >> index;
	visitGraph(mygraph, &edge, index);

	for(int k=0;k<i;k++)  //�������ͨͼ ��ִ�д�ѭ��
		if(visited[k]==0)
	visitGraph(mygraph, &edge, k);

	system("pause");
	return 0;
}