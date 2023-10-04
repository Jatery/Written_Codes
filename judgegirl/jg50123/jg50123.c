#include <stdio.h>
#include <assert.h>

#define maxn 1000
#define row(k) k / n
#define col(k) k % n
#define loc(x, y) x * n + y

int main() {
	int n, k, x, y, arr[maxn * maxn];
	scanf("%d%d%d%d", &n, &k, &x, &y);
	assert(n >= 1 && n <= maxn);
	assert(k >= 1 && k <= n);
	int tmp = k;
	do {
		arr[loc(x, y)] = tmp;
		if(tmp % n == 0)
			x++;
		else
			x--, y++;
		x = (x + n) % n;
		y %= n;
		tmp++;
		if(tmp > n * n)
			tmp -= n * n;
	} while(tmp != k);

#ifdef DEBUG
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			printf("%3d", arr[loc(i, j)]);
		}
		printf("\n");
	}
#else
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(j > 0)
				printf(" ");
			printf("%d", arr[loc(i, j)]);
		}
		printf("\n");
	}
#endif
}
