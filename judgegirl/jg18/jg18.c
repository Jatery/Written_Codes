#include <stdio.h>
#include <stdbool.h>

int main() {
	int r, c;
	scanf("%d%d", &r, &c);
	int arr[r][c];
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
			scanf("%d", &arr[i][j]);
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j) {
			if(i > 0 && arr[i][j] <= arr[i-1][j])
				continue;
			if(i < r - 1 && arr[i][j] <= arr[i+1][j])
				continue;
			if(j > 0 && arr[i][j] <= arr[i][j-1])
				continue;
			if(j < c - 1 && arr[i][j] <= arr[i][j+1])
				continue;
			printf("%d\n", arr[i][j]);
		}
}
