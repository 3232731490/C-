#include<iostream>
using namespace std;
#define Maxmize 20

struct EdgeNode  //�߱�ڵ�
{
	int adjvex;
	int weight;  //����Ȩֵ������ͼ����Ҫ
	EdgeNode* next;
};

struct VertexNode  //�����ڵ�
{
	char data;
	EdgeNode* firstedge;   //��ͷͷָ��
};

struct  GraphList  //�����
{
	VertexNode graph[Maxmize];
	int numVertexes, numEdges;  //ͼ�ж���ͱ���
};

int main()
{
	//����һ������ͼ
	GraphList Graph;
	
	int i, j;
	cout << "�����붥�����ͱ�����" << endl;
	cin >> i >> j;

	Graph.numVertexes = i, Graph.numEdges = j;

	//���붥����Ϣ�����������
	for (int k = 0; k < i; k++)
	{
		char data;
		cin >> data;
		Graph.graph[i].data = data;   //���붥����Ϣ
		Graph.graph[i].firstedge = NULL;  //������Ϊ�ձ�
	}
	for (int k = 0; k < j; k++)
	{
		cout << "����ߵ����꣨vi,vj��" << endl;
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