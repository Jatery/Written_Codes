#include <stdio.h>

int main() {
	int arr[9][9];
	int m;
	scanf("%d", &m);
	int addr[m][10][2];
	int total[m];
	for(int i = 0; i < m; ++i) {
		int n;
		scanf("%d", &n);
		scanf("%d", &total[i]);
		for(int j = 0; j < n; ++j) {
			scanf("%d%d", &addr[i][j][0], &addr[i][j][1]);
			arr[addr[i][j][0]][addr[i][j][1]] = i;
		}
	}
	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < 9; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i = 0; i < m; ++i) {
		printf("%d ", total[i]);
	}
	printf("\n");
}
