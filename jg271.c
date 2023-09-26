#include <stdio.h>

int main() {
	int a, b;
	scanf("%d", &a);
	int pola[a];
	for(int i = 0; i < a; ++i)
		scanf("%d", &pola[i]);
	scanf("%d", &b);
	int polb[b];
	for(int i = 0; i < b; ++i)
		scanf("%d", &polb[i]);
	int ans[a + b - 1];
	for(int i = 0; i < a + b - 1; ++i)
		ans[i] = 0;
	for(int i = 0; i < a; ++i)
		for(int j = 0; j < b; ++j)
			ans[i + j] += pola[i] * polb[j];
	for(int i = 0; i < a + b - 1; ++i)
		printf((i > 0 ? " %d" : "%d"), ans[i]);
	printf("\n");
}
