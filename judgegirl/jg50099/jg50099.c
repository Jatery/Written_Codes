#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#define MAXN 16384

int max(int a, int b) {
	return a > b ? a : b;
}

int findBalancePoint(int64_t arr[MAXN], int l, int r) {
	for (int i = l; i < r; ++i) {
		int64_t total = 0;
		for (int j = 1; j <= max(i - l, r - i + 1); ++j) {
			if (i - j >= l)
				total -= arr[i - j] * j;
			if (i + j < r)
				total += arr[i + j] * j;
		}
		if (total == 0)
			return i;	
	}
	return -1;
}

int main() {
	int n;
	scanf("%d", &n);
	assert(0 < n && n < MAXN);
	int64_t arr[MAXN];
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &arr[i]);
	}
	printf("%d\n", findBalancePoint(arr, 0, n));
}
