#include<iostream>
using namespace std;
#define LH 1
#define EH 0
#define RH -1

typedef struct AVLNode
{
	int data;
	AVLNode* Lchild, * Rchild;
	int Bf;
}AVLNode, *AVLTree ;

void L_Rotate(AVLTree *T)
{
	AVLTree L;
	L = (*T)->Rchild;
	(*T)->Rchild = L->Lchild;
	L->Lchild = (*T);
	*T = L;
}
void R_Rotate(AVLTree* T)
{
	AVLTree L;
	L = (*T)->Lchild;
	(*T)->Lchild = L->Rchild;
	L->Rchild = (*T);
	*T = L;
}

void L_Balance(AVLTree* T)
{
	AVLTree L,Lr;
	L = (*T)->Lchild;
	switch (L->Bf)
	{
	case LH:
	{
		R_Rotate(T);
		L->Bf = (*T)->Bf = EH;
		break;
	}
	case RH:
	{
		Lr = L->Rchild;
		switch (Lr->Bf)  //对T及其左孩子的平衡因子进行调整
		{
		case LH:
			(*T)->Bf = RH;
			L->Bf = EH;
			break;
		case EH:
			(*T)->Bf = L->Bf = EH;
			break;
		case RH:
			(*T)->Bf = EH;
			L->Bf = LH;
			break;

		}
		Lr->Bf = EH;
		L_Rotate(&(*T)->Lchild);
		R_Rotate(T);
	}
	}
}

void R_Balance(AVLTree* T)
{
	AVLTree R, Rl;
	R = (*T)->Rchild;
	switch (R->Bf)
	{
	case RH:
	{
		L_Rotate(T);
		R->Bf = EH;
		(*T)->Bf = EH;
	}
	case LH:
	{
		Rl = R->Lchild;
		switch (Rl->Bf)
		{
		case RH:
		{
			(*T)->Bf = LH;
			R->Bf = EH;
			break;
		}
		case EH:
		{
			(*T)->Bf = R->Bf = EH;
			break;

		}
		case LH:
		{
			R->Bf = RH;
			(*T)->Bf = EH;
			break;
		}
		Rl->Bf = EH;
		R_Rotate(&(*T)->Rchild);
		L_Rotate(T);
		}
	}
	}
}

int insertAVL(AVLTree* T, int e, int* taller)
{
	if (!*T)
	{
		//插入节点，树长高，将taller设为1
		*T = new AVLNode;
		(*T)->data = e;
		(*T)->Bf = EH;
		(*T)->Lchild = (*T)->Rchild = NULL;
		*taller = 1;
	}
	else
	{
		if (e == (*T)->data)
		{
			//树中存在与e相同节点，不插入
			*taller = 0;
			return 0;
		}
		if (e < (*T)->data)
		{
			if (!insertAVL(&(*T)->Lchild, e, taller))
			{
				return 0;
			}
			if (*taller)  //这里表示 节点已插入左子树中 树已长高
			{
				switch ((*T)->Bf)
				{
				case LH:  //原本左子树比右子树高，需要左平衡处理
				{
					L_Balance(T);
					*taller = 0;
					break;
				}
				case RH:   //原本右子树比左子树高 现平衡 
				{
					(*T)->Bf = EH;
					*taller = 0;
					break;
				}
				case EH:  //原本左右等高 现在左子树比右子树高 树增高
				{
					(*T)->Bf = LH;
					*taller = 1;
					break;
				}
				}
			}
		}

		else
		{
			if (!insertAVL(&(*T)->Rchild, e, taller))
			{
				return 0;
			}
			if (*taller)
			{
				switch ((*T)->Bf)
				{
				case RH:  //原本右子树高 现在继续插入右子树 右子树需做平衡处理
				{
					R_Balance(T);
					*taller = 0;
					break;
				}
				case LH:
				{
					(*T)->Bf = EH;
					*taller = 0;
					break;
				}
				case EH:
				{
					(*T)->Bf = RH;
					*taller = 1;
					break;
				}

				}
			}
		}
	}
	return 1;
}


void visitTree(AVLTree T)
{
	if (!T)
	{
		return;
	}
	visitTree(T->Lchild);
	cout << T->data << " ";
	visitTree(T->Rchild);
}

int main()
{
	AVLTree T=NULL;
	cout << "您要输入几个数据：" << endl;
	int n;
	cin >> n;
	cout<<"请输入数据："<<endl;
	int taller = 0;
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		insertAVL(&T, e, &taller);
	}

	cout << "中序遍历输出为：" << endl;
	visitTree(T);

	system("pause");
	return 0;
}