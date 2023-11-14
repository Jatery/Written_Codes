#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void fill(bool arr[64][64], int l, int x, int y) {
	int typearr[4][2] = {{1, 1}, {0, 1}, {0, 0}, {1, 0}};	
	int type = 0;
	for(int i = 0; i < 4; ++i) {
		if(arr[x + typearr[i][0] * (l - 1)][y + typearr[i][1] * (l - 1)])
			type += i + 1;
	}
	assert(type > 0);
	if(type > 4) {
#ifdef DEBUG
		printf("%d\n", type);
#endif
		return;
	}
	if(l == 2) {
		printf("%d %d %d\n", type, x + 1, y + 1);
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < 2; ++j)
				if(i != typearr[type - 1][0] || j != typearr[type - 1][1])
					arr[x + i][y + j] = 1;
#ifdef DEBUG
		/* print */
		for(int i = l - 1; i >= 0; --i) {
			for(int j = 0; j < l; ++j) {
				printf("%d ", (arr[j][i]? 1 : 0));
			}
			printf("\n");
		}
#endif
		return;
	}
	assert(l > 2);
	printf("%d %d %d\n", type, x + l / 2, y + l / 2);
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			if(i != typearr[type - 1][0] || j != typearr[type - 1][1])
				arr[x + l / 2 - 1 + i][y + l / 2 - 1 + j] = 1;
#ifdef DEBUG
	/* print */	
	for(int i = l - 1; i >= 0; --i) {
		for(int j = 0; j < l; ++j) {
			printf("%d ", (arr[j][i]? 1 : 0));
		}
		printf("\n");
	}
#endif
	fill(arr, l / 2, x, y);
	fill(arr, l / 2, x + l / 2, y);
	fill(arr, l / 2, x, y + l / 2);
	fill(arr, l / 2, x + l / 2, y + l / 2);
}

int main() {
	int m, l;
	scanf("%d%d", &l, &m);
	bool arr[64][64] = {{0}};
	assert(1 <= m && m < l && l <= 64);
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < m; ++j) {
			arr[l - m + i][l - m + j] = 1;
		}
	}
#ifdef DEBUG
	/* print */
	for(int i = l - 1; i >= 0; --i) {
		for(int j = 0; j < l; ++j) {
			printf("%d ", (arr[j][i]? 1 : 0));
		}
		printf("\n");
	}
#endif
	fill(arr, l, 0, 0);
#ifdef DEBUG
	/* print */
	for(int i = l - 1; i >= 0; --i) {
		for(int j = 0; j < l; ++j) {
			printf("%d ", (arr[j][i]? 1 : 0));
		}
		printf("\n");
	}
#endif
}
