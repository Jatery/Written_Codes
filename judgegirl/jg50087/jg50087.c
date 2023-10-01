#include <stdio.h>
#include <assert.h>

#define maxn 2048

int max(int a, int b) {
	return a > b ? a : b;
}

int FindBalancePoint(int arr[maxn], int n) {
	for(int i = 1; i < n - 1; ++i) {
		int total = 0;
		for(int j = 1; j <= max(i, n - i - 1); ++j) {
			if(j <= i)
				total -= arr[i - j] * j;
			if(j + i < n)
				total += arr[i + j] * j;
		}
		if(total == 0)
			return i;
	}
	return -1;
}

int main() {
	int n, arr[maxn];
	scanf("%d", &n);
	assert(n <= maxn);

	for(int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	if(FindBalancePoint(arr, n) > 0) {
		for(int i = 0; i < n; ++i) {
			if(i > 0)
				printf(" ");
			if(i == FindBalancePoint(arr, n))
				printf("v");
			else
				printf("%d", arr[i]);
		}
		printf("\n");
	}
	else
		printf("not found\n");
}
