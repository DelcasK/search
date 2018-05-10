#include<iostream>
#include<stdlib.h>
//˳����ҷ�
int Search(int a[], int n, int k)                                    //nΪ���鳤�ȣ�kΪ��ƥ���Ԫ��
{
	for (int i = 0; i < n; i++)
	{
		if (i==k)
		{
			return 1;
		}
	}
	return 0;
}

//�۰���ҷ������ַ���ǰ�����������Ա��������
int Bsearch(int a[], int low,int high, int k)
{
	int mid;
	while (low<=high)
	{
		mid = (low + high) / 2;
		if (a[mid]==k)
		{
			return 1;
		}
		else if(a[mid]>k)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return 0;
}
//�۰���ҿ��ö�������ʾ

//�ֿ���ң��ֿ����򣬿��ڿ�������
typedef struct
{
	int key;                                                          //��ż�ֵ
	int low, high;                                                 //�����ֵ��ָ����βλ��
}indexElem;

//����������(���ַ��Ķ��������Ƕ���������)
typedef struct BTNode
{
	int key;
	BTNode*lchild,*rchild;
}BTNode;

//���ҹؼ����㷨
BTNode* BSTsearch1(BTNode*bt, int key)              //����
{
	BTNode*p = bt;
	while (p)
	{
		if (p->key>key)
		{
			p = p->lchild;
		}
		else if (p->key<key)
		{
			p = p->rchild;
		}
		else
		{
			return p;
		}
	}
	return NULL;
}

BTNode* BSTsearch(BTNode*bt, int key)                                 //�Ӹ���㿪ʼ�Ƚϣ�С��key�͵ݹ������������ڵݹ�������
{
	if (bt)
	{
		if (bt->key==key)
		{
			return bt;
		}
		else if(bt->key<key)
		{
			return BSTsearch(bt->rchild, key);
		}
		else
		{
			return BSTsearch(bt->lchild, key);
		}
	}
	else
	{
		return NULL;
	}
}

//����ؼ����㷨
int BSTInsert(BTNode*&bt, int key)                                         //bt�ھ����˷���֮�󣬻�ı䣬����������ñ���
{
	if (bt==NULL)
	{
		bt = (BTNode*)malloc(sizeof(BTNode));                        //��btΪ��ʱ����Ϊ����λ��
		bt->lchild = bt->rchild = NULL;
		bt->key = key;
		return 1;
	}
	else
	{
		if (bt->key<key)
		{
			BSTInsert(bt->rchild, key);
		}
		else if(bt->key>key)
		{
			BSTInsert(bt->lchild, key);
		}
		else
		{
			return 0;                                                                      //����Ѿ����ڣ�����ʧ��
		}
	}
}

//�����������Ĺ��췽��(����BSTIsert����ʵ�ֶ����������Ĺ���)
void CreateBST(BTNode*&bt, int key[],int n)
{
	bt = NULL;
	for (int i = 0; i < n; i++)
	{
		BSTInsert(bt, key[i]);
	}
}

//ɾ���ؼ����㷨
//3������������������ڵ�������������˫������

//ƽ���������ƽ��������Ƕ��������������������߶�֮�����ֵ������1��


