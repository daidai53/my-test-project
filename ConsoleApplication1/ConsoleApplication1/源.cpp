#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define maxsize 1000
//Ï¡Êè¾ØÕóµÄ×ªÖÃ
typedef struct triple
{
	int i, j;
	int e;
};
typedef struct TSMatrix {
	triple data[maxsize];
	int mu, nu, tu;
};

void print(TSMatrix ts) {
	int a;
	int b[100][100];
	for (int m = 0; m <ts.mu; m++)
		for (int n = 0; n <ts.nu; n++)
			b[m][n] = 0;
	for (a = 0; a < ts.tu; a++) {
		b[ts.data[a].i][ts.data[a].j] = ts.data[a].e;
	}
	for (int m = 0; m < ts.mu; m++) {
		for (int n = 0; n < ts.nu; n++)
			printf("%d ", b[m][n]);
		printf("\n");
	}
}
void transpose(TSMatrix ts, TSMatrix &st) {
	st.mu = ts.nu;
	st.nu = ts.mu;
	st.tu = ts.tu;
	for (int m = 0; m < ts.tu; m++) {
		st.data[m].e = ts.data[m].e;
		st.data[m].i = ts.data[m].j;
		st.data[m].j = ts.data[m].i;
	}
}
int main() {
	TSMatrix ts,st;
	ts.mu = 5;
	ts.nu = 3;
	ts.tu = 2;
	ts.data[0].e = 3;
	ts.data[0].i = 1;
	ts.data[0].j = 2;
	ts.data[1].e = 1;
	ts.data[1].i = 0;
	ts.data[1].j = 0;
	print(ts);
	transpose(ts,st);
	print(st);
	return 0;
}