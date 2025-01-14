#include<iostream>
using namespace std;
struct BTreeNode
{
	int data;
	BTreeNode* Lchild, * Rchild;
};


void CreatBinSortTree(BTreeNode** T , int n )
{
	if (!(*T))
	{
		*T = new BTreeNode;
		(*T)->data = n;
		(*T)->Lchild = NULL;
		(*T)->Rchild = NULL;
	}
	else
	{
		BTreeNode* p = *T;
		BTreeNode* pre = *T;
		int flag=0;
		while (p)
		{
			if (n < p->data)
			{
				pre = p;
				p = p->Lchild;
				flag = 0;
			}
			else if (n > p->data)
			{
				pre = p;
				p = p->Rchild;
				flag = 1;
			}

		}
		p = new BTreeNode;
		p->data = n;
		p->Lchild = p->Rchild = NULL;
		if (flag)
		{
			pre->Rchild = p;
		}
		else
		{
			pre->Lchild = p;
		}
	}

}

void BTree_research(BTreeNode* T)
{
	if (!T)
	{
		return;
	}
	else 
	{
		BTree_research(T->Lchild);
		cout << T->data << " ";
		BTree_research(T->Rchild);
	}
}


int search(BTreeNode* T ,int k,BTreeNode *f,BTreeNode** p)
{
	if (!T)
	{
		*p = f;
		return 0;
	}
	else if(k==T->data)
	{
		*p = T;
		return 1;
	}
	else if (k < T->data)
	{
		return search(T->Lchild, k, T, p);
	}
	else
	{
		return search(T->Rchild, k, T, p);
	}
}

void insertBTree(BTreeNode* T, int key)
{
	BTreeNode* p0 = NULL, *p1;
	
	if (!search(T, key, p0, &p1))
	{
		p0 = T;
		p1 = p0;
		int flag = 0;
		while (p0)
		{
			if (key < p0->data)
			{
				p1 = p0;
					p0 = p0->Lchild;
					flag = 0;
			}
			else
			{
				p1 = p0;
				p0 = p0->Rchild;
				flag = 1;
			}
		}

		cout << "插入成功！" << endl;
		if (flag)
		{
			p0 = new BTreeNode;
			p0->data = key;
			p0->Lchild = p0->Rchild = NULL;
			p1->Rchild = p0;
		}
		else
		{
			p0 = new BTreeNode;
			p0->data = key;
			p0->Lchild = p0->Rchild = NULL;
			p1->Lchild = p0;
		}
	}

	else
	{
		cout << "二叉排序树中已有 数据：" << key << endl;
	}
}


void Delete(BTreeNode** p)
{
	BTreeNode* q, * s;
	if ((*p)->Lchild == NULL)
	{
		q = *p;
		*p = (*p)->Rchild;
		delete q;
	}
	else if ((*p)->Rchild == NULL)
	{
		q = *p;
		*p = (*p)->Lchild;
		delete q;
	}
	else
	{
		q = *p;
		s = (*p)->Lchild;
		while (s->Rchild)
		{
			q = s;
			s = s->Rchild;
		}

		(*p)->data = s->data;
		if (q != (*p))
		{
			q->Rchild = s->Lchild;
		}
		else
		{
			q->Lchild = s->Lchild;
		}
		delete s;
	}
}
void delete_BTree(BTreeNode** T, int key)
{
	if (!(*T))
	{
		return;
}
	else
	{
		if (key == (*T)->data)
		{
			return Delete(T);
		}
		else if (key < (*T)->data)
		{
			return delete_BTree(&(*T)->Lchild, key);

		}
		else
		{
			return  delete_BTree(&(*T)->Rchild, key);
		}
	}
}
int main()
{
	cout << "您要创建几个节点：" << endl;
	int n;
	cin >> n;
	BTreeNode* T =NULL;
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		CreatBinSortTree(&T, data);
	}

	cout << "您要查找哪个数据：" << endl;
	int m;
	cin >> m;
	BTreeNode* f = NULL;
	BTreeNode* p0;
	int flag=search(T, m, f, &p0);
	if (!flag)
	{
		cout << "未查找到！" << endl;
	}
	else
	{
		cout << "查找到：" << p0->data << endl;
	}

	cout << "您想插入哪个数据：" << endl;
	int i;
	cin >> i;
	insertBTree(T, i);


	cout << "您想删除哪个数：" << endl;
	int d1;
	cin >> d1;

	delete_BTree(&T, d1);

	cout << "中序遍历输出为：" << endl;
	BTree_research(T);

	system("pause");
	return 0;
}