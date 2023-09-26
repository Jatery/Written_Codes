#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int i = 2 * n - 1;
	while(i--) 
		printf("%d\n", (i >= n ? n * 2 - 1 - i : i + 1));
	return 0;
}
