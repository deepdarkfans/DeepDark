
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define max 100

typedef struct Node {
	//�������ṹ
	char data;
	struct Node *lchild, *rchild;
}*Bitree,Bitnode;
void createbitree(Bitree &T)//���򴴽�������
{
	char ch;
	scanf("%d", &ch);
	if (ch == '#')
		T = NULL;
	else {

	}
}