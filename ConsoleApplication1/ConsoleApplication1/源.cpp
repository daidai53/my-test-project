#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode * next;
}LNode,* Linklist;
void GetElem(Linklist L,int i,int &e);
void ListInsert(Linklist &L,int i,int e);
void ListDelete(Linklist &L,int i,int & e);
void CreateList(Linklist &L,int n);
void print(Linklist L);
int main() {
	int n,e;
	Linklist l;
	printf("请输入链表长度：");
	scanf("%d",&n);
	CreateList(l,n);
	print(l);
	GetElem(l,5,e);
	printf("第五个元素为%d\n",e);
	ListInsert(l,5,20);
	print(l);
	GetElem(l, 5, e);
	printf("第五个元素为%d\n", e);
	ListDelete(l,5,e);
	printf("deleted %d\n",e);
	print(l);
	GetElem(l, 5, e);
	printf("第五个元素为%d\n", e);
	return 0;
}
void GetElem(Linklist L,int i,int &e) {
	int j = 1;
	Linklist p = L->next;
	while (j != i) {
		p = p->next;
		j++;
	}
	e = p->data;
}
void ListInsert(Linklist &L, int i, int e) {
	Linklist p = L;
	Linklist s;
	int j = 0;
	while (j < i-1) {
		p = p->next;
		j++;
	}
	if (j <= i) {
		s = (Linklist)malloc(sizeof(LNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
	}
	else {
		exit(0);
	}
}
void ListDelete(Linklist &L, int i, int & e) {
	Linklist p = L;
	int j = 0;
	while (j < i - 1) {
		j++;
		p = p->next;
	}
	Linklist s = p->next;
	p->next = s->next;
	free(s);
}

void CreateList(Linklist & L, int n){
	L = (Linklist)malloc(sizeof(LNode));
	L->next = NULL;
	Linklist p;
	printf("请逆序输入单链表的各个元素:\n");
	for (int i = 0;i < n;i++) {
		p = (Linklist)malloc(sizeof(LNode));
		p->next = L->next;
		L->next = p;
		scanf("%d",&p->data);
	}
}

void print(Linklist L){
	Linklist p;
	p = L->next;
	while (p != NULL) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
