#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
//二叉树链式存储
typedef struct BiTNode{
	char data;
	struct BiTNode * lchild = NULL;
	struct BiTNode * rchild=NULL;
}BiTNode, *BiTree;
typedef struct {
	BiTree *base;
	BiTree *top;
	int stacksize;
}Stack;
int createbitree(BiTree &T) {
	char ch;
	cin >> ch;
	if (ch == '`')T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		createbitree(T->lchild);
		createbitree(T->rchild);
	}
	return 1;
}
int Visit(char data) {
	printf("%c ",data);
	return 1;
}
int PreOrderTranverse(BiTree T, int(* Visit)(char data)) {
	if (T) {
		if (Visit(T->data)) {
			if (PreOrderTranverse(T->lchild, Visit))
				if (PreOrderTranverse(T->rchild, Visit))
					return 1;
			return 0;
		}
	}
	else
	{
		return 1;
	}
}
void InitStack(Stack &S) {
	S.base = (BiTree *)malloc(100 * sizeof(BiTree));
	if (!S.base)exit(0);
	S.top = S.base;
	S.stacksize = 100;
}
bool StackEmpty(Stack S) {
	BiTree *p;
	int i;
	i = S.stacksize;
	p = S.base;
	while (i--) {
		if (*p != NULL)
			return false;
	}
	return true;
}
int GetTop(Stack S, BiTree &e) {
	BiTree *p;
	p = S.top--;
	e = *p;
	return 1;
}
void Push(Stack &S, BiTree e) {
	*S.top++ = e;
}
void Pop(Stack &S, BiTree &e) {
	S.top--;
	e = *S.top;
}
int inordertranverse(BiTree T,int (* Visit)(char data)) {
	Stack S;
	BiTree p;
	InitStack(S);
	Push(S,T);
	p = T;
	while (!StackEmpty(S)) {
		while (GetTop(S, p) && p)
			Push(S,p->lchild);
		Pop(S,p);
		if (!StackEmpty(S)) {
			Pop(S,p);
			if (!Visit(p->data))return 0;
			Push(S,p->rchild);
		}
	}
	return 1;
}
int main() {
	BiTree bt;
	printf("输入二叉树的每个结点，“`”代表空\n");
	if (createbitree(bt))
		printf("创建成功\n");
	else
		printf("创建失败\n");
	if (!PreOrderTranverse(bt,Visit))
		printf("failed\n");
	if (!inordertranverse(bt, Visit))
		printf("failed\n");
	return 0;
}