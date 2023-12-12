#include <stdio.h>
#include "construct.h"

#define MAXN 10

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
	Node *node;
	if(N == 1) {
		node->value = T[0];
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	int P = BalancePoint(T, N);
	if(P >= 0) {
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
	else {
		node->value = T[N - 1];
		int L[N - 1];
		for(int i = 0; i < N - 1; ++i)
			L[i] = T[i];
		node->left = ConstructTree(L, N - 1);
		node->right = NULL;
		return node;
	}
}
