//2017��2��28��08:00:21  ���ݽṹ�ϻ�
//�Թ�����
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
	printf("�������Թ��߶ȣ��������߽磩��");
	scanf("%d",&Map.sizex);
	printf("�������Թ���ȣ�");
	scanf("%d", &Map.sizey);
}
int main() {
	return 0;
}