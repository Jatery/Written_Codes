#include <stdio.h>

#define MAXN 100000

void merge_sort (int a[], int l, int r) {
	for(int i = l; i < r; i++)
		printf("%d ", a[i]);
	printf("\n");
	int m = (l + r) >> 1;
	if (m != l) {
		merge_sort(a, l, m);
		merge_sort(a, m, r);
	}
	int i = l, j = m, k = 0, b[r - l];
	while (i < m && j < r)
			b[k++] = (a[i] < a[j] ? a[i++] : a[j++]);
	while (i < m)
		b[k++] = a[i++];
	while (j < r)
		b[k++] = a[j++];
	for (i = l; i < r; i++)
		a[i] = b[i - l];
	if (m != l) {
		for (i = l; i < r; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
}

int main () {
	int n = 0, a[MAXN];
	while (scanf("%d", &a[n++]) != EOF);
	if (--n == 1)
		printf("%d\n", a[0]);
	else
		merge_sort(a, 0, n);
}
