#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000005

int main() {
	int n, k;
	scanf("%d", &n);
	int arr[2][MAX] = {0}, bigShelf[MAX * 2] = {0}, index[2][2];
	for(int i = 0; i < 2; ++i) {
		bool flag = 1;
		for(int j = 0; j < n; ++j) {
			scanf("%d", &k);
			arr[i][j] = abs(k);
			if(k < 0)
				index[i][0] = j;
			else if(flag) {
				index[i][1] = j;
				flag = 0;
			}
		}
		if(flag)
			index[i][1] = index[i][0] + 1;
		index[i][0] = index[i][1] - 1;
	}
	int p = 0;
	while(index[0][0] >= 0 || index[0][1] < n || index[1][0] >= 0 || index[1][1] < n) {
		int x, y, min = 700000005;
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j) {
				if(index[i][j] >= 0 && index[i][j] < n && arr[i][index[i][j]] < min) {
					min = arr[i][index[i][j]];
					x = i;
					y = j;
				}
			}
		}
		bigShelf[p] = arr[x][index[x][y]];
		p++;
		if(y == 0)
			index[x][y]--;
		else
			index[x][y]++;
	}
	for(int i = 0; i < 2 * n; ++i)
		printf("%lld%c", (long long) bigShelf[i] * bigShelf[i], " \n"[i==2*n-1]);
}
