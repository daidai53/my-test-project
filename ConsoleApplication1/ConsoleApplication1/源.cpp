//2017年2月28日08:00:21  数据结构上机
//迷宫问题
#include<iostream>
#include<cstdio>
#include<string.h>
#include<stdlib.h>
#include<stack>
using namespace std;

typedef struct {
	int x, y;
}zuobiao;

typedef struct {
	int sizex, sizey;
	zuobiao a[100][100];
}migong;

void init_map(migong Map) {
	printf("请输入迷宫高度（不包括边界）：");
	scanf("%d",&Map.sizex);
	printf("请输入迷宫宽度：");
	scanf("%d", &Map.sizey);
}
int main() {
	return 0;
}