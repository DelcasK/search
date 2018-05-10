#include<iostream>
#include<stdlib.h>
//顺序查找法
int Search(int a[], int n, int k)                                    //n为数组长度，k为待匹配的元素
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

//折半查找法（二分法）前提条件是线性表是有序的
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
//折半查找可用二叉树表示

//分块查找（分块有序，块内可以无序）
typedef struct
{
	int key;                                                          //存放键值
	int low, high;                                                 //存放链值，指向首尾位置
}indexElem;

//二叉排序树(二分法的二叉树即是二叉排序树)
typedef struct BTNode
{
	int key;
	BTNode*lchild,*rchild;
}BTNode;

//查找关键字算法
BTNode* BSTsearch1(BTNode*bt, int key)              //自制
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

BTNode* BSTsearch(BTNode*bt, int key)                                 //从根结点开始比较，小于key就递归右子树，大于递归左子树
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

//插入关键字算法
int BSTInsert(BTNode*&bt, int key)                                         //bt在经历此方法之后，会改变，因此需用引用变量
{
	if (bt==NULL)
	{
		bt = (BTNode*)malloc(sizeof(BTNode));                        //当bt为空时，即为插入位置
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
			return 0;                                                                      //结点已经存在，插入失败
		}
	}
}

//二叉排序树的构造方法(利用BSTIsert方法实现二叉排序树的构造)
void CreateBST(BTNode*&bt, int key[],int n)
{
	bt = NULL;
	for (int i = 0; i < n; i++)
	{
		BSTInsert(bt, key[i]);
	}
}

//删除关键字算法
//3种情况：无子树，存在单侧子树，存在双侧子树

//平衡二叉树（平衡二叉树是二叉排序树，左右子树高度之差绝对值不超过1）


