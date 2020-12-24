#include<iostream>
using namespace std;

struct BiTNode
{
	int num;
	BiTNode* lchild ,* rchild;
};

void creatBiTree(BiTNode** T)
{
	int c;
	cin >> c;
	if (0 == c)
	{
		*T = NULL;
	}
	else
	{
		
		*T = new BiTNode;
		(*T)->num = c;
		creatBiTree(&(*T)->lchild);
		creatBiTree(&(*T)->rchild);
	}
}

void preOrderVisit(BiTNode* T,int level)
{
	if (T)
	{
		cout << T->num << "ÔÚµÚ" << level << " ²ã" << endl;
		preOrderVisit(T->lchild, level + 1);
		preOrderVisit(T->rchild, level + 1);
	}
}
int main()
{
	int level = 1;
	BiTNode* T =NULL;
	creatBiTree(&T);
	preOrderVisit(T, level);

	system("pause");
	return 0;
}
