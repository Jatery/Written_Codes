#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

void change(Node *head, int k, int m) {
	Node *arr[k];
	Node *node = head;
	for (int i = 0; i < k; ++i) {
		arr[i] = node;
		for (int j = 0; j < m; ++j) {
			if (j == m-1) {
				Node *tmp = node;
				node = node->next;
				tmp->next = NULL;
			} else {
				node = node->next;
			}
		}
		
	}
	for (int i = 0; i < k; ++i) {
		printf("%d ", arr[i]->data);
	}
	printf("\n");
	node = head;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			Node *tmp = arr[j]->next;
			arr[j]->next = arr[(j+1) % k];
			arr[j] = tmp;
		}
	}
}

int main () {
	int N;
	scanf("%d", &N);
	Node node[N];
	for (int i = 0; i < N; ++i) {
		scanf("%d", &node[i].data);
		if (i == N-1) {
			node[i].next = NULL;
		} else {
			node[i].next = &node[i+1];
		}
	}
	int k, m;
	scanf("%d %d", &k, &m);
	change(&node[0], k, m);
	Node *tmp = &node[0];
	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
