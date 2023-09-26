#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	double arr[n][n], ans[n];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%lf", &arr[i][j]);
	for(int i = 0; i < n; ++i)
		scanf("%lf", &ans[i]);
	for(int i = n - 1; i >= 0; --i) {
		for(int j = n - 1; j > i; --j)
			ans[i] -= arr[i][j] * ans[j];
		ans[i] /= arr[i][i];
	}
	for(int i = 0; i < n; ++i)
		printf("%f\n", ans[i]);
	return 0;
}
