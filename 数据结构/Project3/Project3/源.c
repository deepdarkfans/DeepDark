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
void createbitree(bitree *bt)//先序序列构造二叉树
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