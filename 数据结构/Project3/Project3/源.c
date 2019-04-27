#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define maxlen 100
#define nlayer 4
typedef struct bitnode {
	char data;
	struct bitnode *lchild, *rchild;
}*bitree,bitnode;
bitree T;
bitnode createbitree(bitree *bt)//先序序列构造二叉树
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		*bt == NULL;
	else
	{
		*bt = (bitree)malloc(sizeof(bitnode));
		(*bt)->data = ch;
		createbitree(&((*bt)->lchild));//递归
		createbitree(&((*bt)->rchild));
	}
}
void visit(char ch)
{
	printf("%c",ch) //访问根节点
}
void preorder(bitree root)//先序遍历,root是指向二叉树根节点的指针
{
	if (root != NULL)
	{
		visit(root->data);//访问根节点
		preorder(root->lchild);
		preorder(root->rchild);
	}
	//此为递归先序遍历,非递归后期学.此外中序及后序分别是在中间和最后访问根节点,不做展示
}
