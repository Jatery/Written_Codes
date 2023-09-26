#include <stdio.h>

int main() {
	int n, i, ans = 1;
	scanf("%d%d", &n, &i);
	while(i--)
		ans *= n;
	printf("%d\n", ans);
	return 0;
}
