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

		cout << "����ɹ���" << endl;
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
		cout << "���������������� ���ݣ�" << key << endl;
	}
}

void delete_BTree(BTreeNode* T, int key)
{
	BTreeNode* p0 = NULL, * p1;

	if (!search(T, key, p0, &p1))
	{
		cout << "δ�ҵ������ݣ�" << endl;
	}
	else
	{
		if (p1->Lchild == NULL)
		{
			p0 = p1;
			p1 = p1->Rchild;
			delete p0;
		}
		else if(p1->Rchild==NULL)
		{
			p0 = p1;
			p1 = p1->Lchild;
			delete p0;
		}
		else
		{
			p0 = p1->Lchild;
			BTreeNode* p;
			p = p1;
			while (p0->Rchild)
			{
				p = p0;
				p0 = p0->Rchild;
			}
			p1->data = p0->data;

			if (p != p1)
			{
				p->Rchild = p0->Lchild;
				delete p0;
			}
			else
			{
				p->Lchild = p0->Lchild;
				delete p0;
			}
		}
	}
}
int main()
{
	cout << "��Ҫ���������ڵ㣺" << endl;
	int n;
	cin >> n;
	BTreeNode* T =NULL;
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		CreatBinSortTree(&T, data);
	}

	cout << "��Ҫ�����ĸ����ݣ�" << endl;
	int m;
	cin >> m;
	BTreeNode* f = NULL;
	BTreeNode* p0;
	int flag=search(T, m, f, &p0);
	if (!flag)
	{
		cout << "δ���ҵ���" << endl;
	}
	else
	{
		cout << "���ҵ���" << p0->data << endl;
	}

	cout << "��������ĸ����ݣ�" << endl;
	int i;
	cin >> i;
	insertBTree(T, i);


	cout << "����ɾ���ĸ�����" << endl;
	int d1;
	cin >> d1;

	delete_BTree(T, d1);

	cout << "����������Ϊ��" << endl;
	BTree_research(T);

	system("pause");
	return 0;
}