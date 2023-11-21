#include <stdio.h>
#include <stdint.h>
#include <assert.h>

void findsum(uint64_t a[], int index, int n, int k, uint64_t subset[], uint64_t *sum, uint64_t currentsum) {
	if (index == n) {
		if (currentsum < *sum) {
			*sum = currentsum;
		}
		return;
	}
	for (int i = 0; i < k; ++i) {
		uint64_t new = currentsum + 2 * subset[i] * a[index] + a[index] * a[index];
		if (new < *sum) {
			subset[i] += a[index];
			findsum(a, index + 1, n, k, subset, sum, new);
			subset[i] -= a[index];
		}
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	uint64_t a[n];
	for (int i = 0; i < n; i++) {
		scanf("%llu", &a[i]);
	}
	uint64_t sum = (uint64_t)0 - 1;
	uint64_t subset[10] = {0};
	subset[0] = a[0];
	findsum(a, 1, n, k, subset, &sum, subset[0] * subset[0]);
	printf("%llu\n", sum);
}
