#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
//��������ʽ�洢
typedef struct BiTNode{
	char data;
	struct BiTNode * lchild, * rchild;
}BiTNode, *BiTree;

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
int main() {
	BiTree bt;
	printf("�����������ÿ����㣬��`�������\n");
	if (createbitree(bt))
		printf("�����ɹ�\n");
	else
		printf("����ʧ��\n");
	if (!PreOrderTranverse(bt,Visit))
		printf("failed\n");
	return 0;
}