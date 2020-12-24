#include<iostream>
using namespace std;

typedef enum {Link,Thread} PointTag;
struct BinThrTree
{
	char c;
	BinThrTree* lchild, * rchild;
	PointTag ltag, rtag;
};

BinThrTree* pre;
void creatBinTree(BinThrTree **T)
{
	char c;
	cin >> c;
	if ('#' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = new BinThrTree;
		(*T)->c = c;
		(*T)->ltag = Link;
		(*T)->rtag = Link;
		creatBinTree(&(*T)->lchild);
		creatBinTree(&(*T)->rchild);
	}
}

void creatThread(BinThrTree *T)
{
	if (T)
	{
		creatThread(T->lchild);
		if (!T->lchild)
		{
			T->lchild = pre;
			T->ltag = Thread;
		}
		if (!pre->rchild)
		{
			pre->rchild = T;
			pre->rtag = Thread;
		}
		pre = T;
		creatThread(T->rchild);
	}
}

void creatThreadOrding(BinThrTree* T)
{
	pre = T;
	BinThrTree* P = pre->lchild;
	creatThread(P);
	pre->rchild = T;
	T->rchild = pre;
}

void InOrderTraverse_Thr(BinThrTree* T)
{
	BinThrTree *P = T->lchild;
	while (P != T)
	{
		while (P->ltag == Link)
		{
			P = P->lchild;
		}
		cout << P->c << " ";
		while (P->rtag == Thread && P->rchild != T)
		{
			P = P->rchild;
			cout << P->c << " ";
		}
		P = P->rchild;
	}

}

int main()
{
	BinThrTree* T ;
	cout << "请按前序遍历输入树的各个节点" << endl;
	creatBinTree(&T);
	BinThrTree* head =new BinThrTree;
	head->ltag = Link;
	head->rtag = Thread;
	head->lchild = T;
	creatThreadOrding(head);
	cout << "按中序遍历输出树的各个节点为：" << endl;
	InOrderTraverse_Thr(head);
	system("pause");
	return 0;
}