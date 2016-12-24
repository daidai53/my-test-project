#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
typedef struct sqQueue
{
	int * base;
	int front,rear;
};
bool Initqueue(sqQueue &q) {
	q.base = (int *)malloc(maxsize*sizeof(int));
	if (!q.base)return false;
	q.front = q.rear = 0;
	return true;
}
int length(sqQueue q) {
	return (q.rear-q.front+maxsize)%maxsize;
}
bool enqueue(sqQueue &q,int e) {
	if ((q.rear + 1) % maxsize == q.front)return false;
	q.base[q.rear] = e;
	q.rear = (q.rear + 1) % maxsize;
	return true;
}
bool dequeue(sqQueue &q,int &e) {
	if (q.front == q.rear)
		return false;
	e = q.base[q.front];
	q.front = (q.front + 1) % maxsize;
	return true;
}
int main() {
	int i, n, t;
	sqQueue q;
	if (Initqueue(q))
		printf("succeed\n");
	else
		printf("failed\n");
	printf("length%d\n",length(q));
	printf("enter n:");
	scanf("%d",&n);
	for (i = 0;i < n;i++) {
		scanf("%d",&t);
		if (!enqueue(q, t))
			printf("full");
	}printf("length%d\n", length(q));
	printf("delete the head\n");
	if (dequeue(q, t)) {
		printf("%dhas been deleted\n", t);
		printf("length%d\n", length(q));
	}
	else {
		printf("empty\n");
		printf("length%d\n", length(q));
	}
	return 0;
}