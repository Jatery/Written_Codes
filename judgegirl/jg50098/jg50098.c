#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#define MAXN 101

void find(uint64_t list, uint64_t clubs[], int n, int k, int clublist[], int clubnum, int index) {
	if (k == 0) {
#ifdef DEBUG
		for (int i = 0; i <= 64; ++i) {
			if (list & ((uint64_t)1 << i)) {
				printf("%d ", i);
			}
		}
		printf("\n");
#endif
		for (int i = 0; i < clubnum; ++i) {
			printf("%d\n", clublist[i]);
		}
		exit(0);
	}
	if (index + k > n) {
		return;
	}
	if ((list & clubs[index]) == 0) {
		clublist[clubnum] = index;
		find(list | clubs[index], clubs, n, k - 1, clublist, clubnum + 1, index + 1);
	} 
	find(list, clubs, n, k, clublist, clubnum, index + 1);
	if (index == 0) {
		printf("\n");
		for (int i = 0; i < n; ++i) {
			printf("%d: ", i);
			for (int j = 0; j <= 64; ++j) {
				if (clubs[i] & (1 << j)) {
					printf("%d ", j);
				}
			}
			printf("\n");
		}
		printf("NIE\n");
		exit(0);
	}
}

int main() {
	int n, k, m, id;
	scanf("%d%d", &n, &k);
	uint64_t clubs[n];
	for (int i = 0; i < n; ++i) {
		clubs[i] = 0;
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			scanf("%d", &id);
			clubs[i] |= ((uint64_t)1 << id);
		}
	}
	uint64_t list = 0;
	int clublist[k];
	find(list, clubs, n, k, clublist, 0, 0);
}
