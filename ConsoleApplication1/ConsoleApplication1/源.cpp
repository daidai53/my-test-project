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
int main() {
	return 0;
}
void GetElem(Linklist L,int i,int &e) {
	int j = 1;
	//while(j!=)
}
void ListInsert(Linklist &L, int i, int e) {

}
void ListDelete(Linklist &L, int i, int & e) {

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
