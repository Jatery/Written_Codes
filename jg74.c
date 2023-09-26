#include <stdio.h>

int main () {
	int n, m;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	scanf("%d", &m);
	int ans[m];
	for(int i = 0; i < m; ++i)
		ans[i] = 0;
	for(int i = 0; i < n; ++i)
		ans[arr[i] % m]++;
	for(int i = 0; i < m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
