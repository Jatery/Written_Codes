#include <stdio.h>

int main() {
	int s, c, k;
	scanf("%d%d", &s, &c);
	int arr[s][c];
	for(int i = 0; i < s; ++i)
		for(int j = 0; j < c; ++j)
			arr[i][j] = 0;
	while(scanf("%d", &k) != EOF) {
		int i = 0, f = (77 * k % s + 2222 % s) % s;
		while(i < c && arr[f][i] != k)
			i++;
		if(arr[f][i] == k) {
			printf("%d %d\n", k, f);
			arr[f][i] = 0;
			continue;
		}
		i = 0;
		while(arr[f][i] > 0)
			i++;
		arr[f][i] = k;
	}
}
