#include <stdio.h>
#include <stdbool.h>

void solve(int arr[9][9], int *index) {
	if(*index == 81)
		return;
	if(arr[*index / 9][*index % 9] > 0) {
		(*index)++;
		solve(arr, index);
		if(*index != 81)
			(*index)--;
		return;
	}
	for(int i = 1; i <= 9; ++i) {
		bool flag = 1;
		for(int j = 0; j < 9 && flag; ++j) {
			if(arr[*index / 9][j] == i)
				flag = 0;
			else if(arr[j][*index % 9] == i)
				flag = 0;
		}
		for(int j = 0; j < 3 && flag; ++j)
			for(int k = 0; k < 3 && flag; ++k) {
				if(arr[((*index / 9) / 3) * 3 + j][((*index % 9) / 3) * 3 + k] == i)
					flag = 0;
			}
		if(flag) {
#ifdef DEBUG
			printf("try arr[%d][%d] for %d\n", *index / 9, *index % 9, i);
#endif
			arr[*index / 9][*index % 9] = i;
			(*index)++;
			solve(arr, index);
			if(*index != 81) {
				(*index)--;
				arr[*index / 9][*index % 9] = 0;
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		int arr[9][9];
		for(int i = 0; i < 9; ++i)
			for(int j = 0; j < 9; ++j)
				scanf("%d", &arr[i][j]);
		int index = 0;
		solve(arr, &index);
		for(int i = 0; i < 9; ++i) {
			for(int j = 0; j < 9; ++j) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
}
