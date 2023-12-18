#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef struct {
	int total;
	int addr[10][2];
	int N;
} Group;

typedef struct {
	int value;
	int groupIndex;
} Node;

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a > b ? a : b;
}

void solve(Node arr[9][9], int *index, Group groups[]) {
	if(*index == 81) {
		return;
	}
	if(arr[*index / 9][*index % 9].value > 0) {
		(*index)++;
		solve(arr, index, groups);
		if(*index != 81)
			(*index)--;
		return;
	}
	int total = groups[arr[*index / 9][*index % 9].groupIndex].total;
	int N = groups[arr[*index / 9][*index % 9].groupIndex].N;
	if(total <= 0)
		return;	
	for(int i = min(total - N * (N - 1) / 2, 9); i >= max(total - (20 - N) * (N - 1) / 2, 1) && *index != 81; --i) {
		bool flag = 1;
		for(int j = 0; j < 9 && flag; ++j) {
			if(arr[*index / 9][j].value == i)
				flag = 0;
			else if(arr[j][*index % 9].value == i)
				flag = 0;
		}
		for(int j = 0; j < 3 && flag; ++j)
			for(int k = 0; k < 3 && flag; ++k) {
				if(arr[((*index / 9) / 3) * 3 + j][((*index % 9) / 3) * 3 + k].value == i)
					flag = 0;
			}
		if(flag) {
#ifdef DEBUG
			printf("try arr[%d][%d] for %d\n", *index / 9, *index % 9, i);
#endif
			groups[arr[*index / 9][*index % 9].groupIndex].total -= i;
			groups[arr[*index / 9][*index % 9].groupIndex].N--;
			arr[*index / 9][*index % 9].value = i;
			(*index)++;
			solve(arr, index, groups);
			if(*index != 81) {
				(*index)--;
				arr[*index / 9][*index % 9].value = 0;
				groups[arr[*index / 9][*index % 9].groupIndex].total += i;
				groups[arr[*index / 9][*index % 9].groupIndex].N++;
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &m);
		Node arr[9][9];
		for(int i = 0; i < 9; ++i)
			for(int j = 0; j < 9; ++j)
				scanf("%d", &arr[i][j].value);
		Group groups[40];
		int k = 0;
		for(int j = 0; j < m; ++j) {
			scanf("%d%d", &groups[k].N, &groups[k].total);
			int N = groups[k].N;
			for(int i = 0; i < N; ++i) {
				scanf("%d%d", &groups[k].addr[i][0], &groups[k].addr[i][1]);
				arr[groups[k].addr[i][0]][groups[k].addr[i][1]].groupIndex = k;
				if(arr[groups[k].addr[i][0]][groups[k].addr[i][1]].value > 0)
					groups[k].N--;
				groups[k].total -= arr[groups[k].addr[i][0]][groups[k].addr[i][1]].value;
			}
			k++;
		}
#ifdef DEBUG
		for(int i = 0; i < 9; ++i) {
			for(int j = 0; j < 9; ++j) {
				printf("%3d", groups[arr[i][j].groupIndex].total);
			}
			printf("\n");
		}
#endif
		int index = 0;
		solve(arr, &index, groups);
#ifdef DEBUG
		printf("Finished solving.\n");
#endif
		if(index != 81) {
			printf("No solution.\n");
		}
		for(int i = 0; i < 9; ++i) {
			for(int j = 0; j < 9; ++j) {
				printf("%d ", arr[i][j].value);
			}
			printf("\n");
		}
#ifdef DEBUG
		for (int i = 0; i < 9; ++i) {
			for(int j = 0; j < 9; ++j) {
				printf("%3d", groups[arr[i][j].groupIndex].total);
			}
			printf("\n");
		}
		for(int i = 0; i < m; ++i) {
			if (groups[i].total != 0) {
				printf("%d %d %d\n", i, groups[i].N, groups[i].total);
			}
		}
#endif
	}	
}
