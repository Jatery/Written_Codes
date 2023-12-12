#include <stdio.h>
#include <stdlib.h>
#include "construct.h"
 
#define MAXN 10
 
int T[MAXN];

#include <stdio.h>
#include <stdlib.h>
#include "construct.h"

int max(int a, int b) {
	return a > b ? a : b;
}

int BalancePoint(int T[], int N) {
	for (int i = 0; i < N; ++i) {
		int total = 0;
		for(int j = 1; j <= max(i, N - i - 1); ++j) {
			if(i - j >= 0)
				total -= T[i - j] * j;
			if(i + j <= N - 1)
				total += T[i + j] * j;
		}
		if(total == 0)
			return i;
	}
	return -1;
}

Node *ConstructTree(int T[], int N) {
	int P = BalancePoint(T, N);
	if(N < 3 || P < 0) {
		Node *tmp = NULL;
		for (int i = 0; i < N; ++i) {
			Node *node = (Node *)malloc(sizeof(Node));
			node->value = T[i];
			node->left = tmp;
			node->right = NULL;
			tmp = node;
		}
		return tmp;
	}
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = T[P];
	int L[P], R[N - P - 1];
	for(int i = 0; i < P; ++i)
		L[i] = T[i];
	for(int i = 0; i < N - P - 1; ++i)
		R[i] = T[i + P + 1];
	node->left = ConstructTree(L, P);
	node->right = ConstructTree(R, N - P - 1);
	return node;
}
 
void PrintTree( Node *root ){
    if (root == NULL)
        return;
 
    printf("%d\n", root->value);
    PrintTree(root->left);
    PrintTree(root->right);
    return;
}
 
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &T[i]);
 
    Node *tree = ConstructTree( T, N );
 
    PrintTree( tree );
    return 0;
}
