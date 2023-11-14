#include <stdio.h>
#include <assert.h>

#define MAXN 20
#define MAXW 10000
#define MAX 1000

int max(int a, int b) {
	return (a > b ? a : b);
}

typedef struct{
	int v;
	int w;
} Object;

int fillPack(Object object[MAXN], int index, int W, int n) {
	if(index == n || W <= 0)
		return 0;
	if(W < object[index].w)
		return fillPack(object, index + 1, W, n);
	return max(fillPack(object, index + 1, W, n), fillPack(object, index + 1, W - object[index].w, n) + object[index].v);
}

int main() {
	int n, W;
	Object object[MAXN];
	scanf("%d%d", &n, &W);
	//assert(n <= MAXN && W <= MAXW);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &object[i].w, &object[i].v);
		//assert(object[i].w <= MAX && object[i].v <= MAX);
	}
	printf("%d\n", fillPack(object, 0, W, n));
}
