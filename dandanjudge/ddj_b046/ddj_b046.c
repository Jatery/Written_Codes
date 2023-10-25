#include <stdio.h>

int main() {
	int x, n, k, left = 0, right = 0;
	scanf("%d%d", &x, &n);
	int min = x, max = x;
	while(n--) {
		scanf("%d", &k);
		if(k < x) {
			left++;
			if(k < min)
				min = k;
		} else {
			right++;
			if(k > max)
				max = k;
		}
	}
	if(left > right)
		printf("%d %d\n", left, min);
	else
		printf("%d %d\n", right, max);
}
