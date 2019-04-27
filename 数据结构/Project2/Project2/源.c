
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define max 100

typedef struct Node {
	//二叉树结构
	char data;
	struct Node *lchild, *rchild;
}*Bitree,Bitnode;
void createbitree(Bitree &T)//先序创建二叉树
{
	char ch;
	scanf("%d", &ch);
	if (ch == '#')
		T = NULL;
	else {

	}
}