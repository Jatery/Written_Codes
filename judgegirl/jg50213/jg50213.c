#include <stdio.h>

#define MAXN 100000

void merge_sort (int a[], int l, int r) {
	for(int i = l; i < r; i++)
		printf("%d%c", a[i], i == r - 1 ? '\n' : ' ');
	int m = (l + r) / 2;
	if (m != l) {
		merge_sort(a, l, m);
		merge_sort(a, m, r);
	}
	int i = l, j = m, k = 0;
	int b[MAXN];
	while (i < m && j < r) {
		if (a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i < m) {
		b[k++] = a[i++];
	}
	while (j < r) {
		b[k++] = a[j++];
	}
	for (i = l; i < r; i++)
		a[i] = b[i - l];
	if (r - l > 1)
		for (i = l; i < r; i++)
			printf("%d%c", a[i], i == r - 1 ? '\n' : ' ');
}

int main () {
	int n = 0;
	int a[MAXN];
	while (scanf("%d", &a[n]) != EOF)
		n++;
	if (n == 1) {
		printf("%d\n", a[0]);
		return 0;
	}
	else {
		merge_sort(a, 0, n);
		return 0;
	}
}
