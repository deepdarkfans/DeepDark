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
void createbitree(bitree *bt)//�������й��������
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		*bt == NULL;
	else
	{
		*bt = (bitree)malloc(sizeof(bitnode));
		(*bt)->data = ch;
		createbitree(&((*bt)->lchild));//�ݹ�
		createbitree(&((*bt)->rchild));
	}
}