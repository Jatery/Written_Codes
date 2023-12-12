#include <stdio.h>
#include <stdlib.h>
#include "construct.h"

#ifndef MAXLENGTH
#define MAXLENGTH 3
#endif

int Point(int sequence[], int N) {
	if (N < MAXLENGTH)
		return -1;
	int subset[MAXLENGTH];
	for (int i = 0; i < MAXLENGTH; i++) {
		subset[i] = sequence[i];
	}
	// bubble sort
	for (int i = 0; i < MAXLENGTH; ++i) {
		for (int j = 0; j < MAXLENGTH - i - 1; ++j) {
			if (subset[j] > subset[j + 1]) {
				int temp = subset[j];
				subset[j] = subset[j + 1];
				subset[j + 1] = temp;
			}
		}
	} 	
	for (int i = MAXLENGTH; i < N; ++i) {
		int value = sequence[i];
		int j = 0;
		while (j < MAXLENGTH && value > subset[j]) {
			if (j > 0)
				subset[j - 1] = subset[j];
			++j;
		}
		if (j > 0)
			subset[j - 1] = value;
	}
	for (int i = 0; i < N; ++i) {
		if (sequence[i] == subset[0])
			return i;
	}
	return -1;
}

Node* ConstructTree(int sequence[], int N) {
	int P = Point(sequence, N);
	if (P == -1) {
		Node *tmp = NULL;
		for (int i = 0; i < N; ++i) {
			Node *node = (Node*)malloc(sizeof(Node));
			node->value = sequence[i];
			node->left = tmp;
			node->right = NULL;
			tmp = node;
		}
		return tmp;
	}
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = sequence[P];
	node->left = ConstructTree(sequence, P);
	node->right = ConstructTree(sequence + P + 1, N - P - 1);
	return node;
}
