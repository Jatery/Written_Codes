#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define ll long long
#define maxn 100000

ll max(ll a, ll b, ll c) {
	if(a >= b && a >= c)
		return a;
	if(b >= a && b >= c)
		return b;
	return c;
}

int main() {
	int n, loc, type;
	ll arr[maxn], height;
	scanf("%d", &n);
	assert(n >= 3 && n <= maxn);
	for(int i = 0; i < n; ++i)
		arr[i] = 0;
	while(scanf("%d%d", &loc, &type) != EOF) {
		assert(loc >= 0 && loc <= n - 3);
		switch(type) {
			case 0:
				height = max(arr[loc] - 1, arr[loc + 1], arr[loc + 2]);
				arr[loc] = height + 2;
				arr[loc + 1] = height + 2;
				arr[loc + 2] = height + 1;
				break;
			case 1:
				height = max(arr[loc], arr[loc + 1], arr[loc + 2] - 1);
				arr[loc] = height + 1;
				arr[loc + 1] = height + 2;
				arr[loc + 2] = height + 2;
				break;
			case 2:
				height = max(arr[loc], arr[loc + 1], arr[loc + 2]);
				arr[loc] = height + 1;
				arr[loc + 1] = height + 2;
				arr[loc + 2] = height + 1;
				break;
			case 3:
				height = max(arr[loc] - 1, arr[loc + 1], arr[loc + 2] - 1);
				arr[loc] = height + 2;
				arr[loc + 1] = height + 2;
				arr[loc + 2] = height + 2;
				break;
			default:
				printf("invalid type\n");
				return 0;
		}
	}
	for(int i = 0; i < n; ++i)
		printf("%lld ", arr[i]);
	printf("\n");
}
