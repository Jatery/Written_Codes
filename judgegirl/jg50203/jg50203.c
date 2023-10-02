#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define maxn 100000

int max(int a, int b, int c) {
	if(a >= b && a >= c)
		return a;
	if(b >= a && b >= c)
		return b;
	return c;
}

int main() {
	int n, arr[maxn], loc, type, height;
	scanf("%d", &n);
	assert(n >= 3 && n <= maxn);
	while(scanf("%d%d", &loc, &type) != EOF) {
		assert(loc >= 0 && loc <= n - 3);
		switch(type) {
			case 0:
				height = max(arr[loc] - 1, arr[loc + 1], arr[loc + 2]);
				arr[loc] = height + 2;
				arr[loc + 1] = height + 2;
				arr[loc + 2] = height + 1;
				break;
			default:
				printf("invalid type\n");
				return 0;
		}
	}
	for(int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
