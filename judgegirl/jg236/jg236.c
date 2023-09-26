#include <stdio.h>

int lcm(int x, int y) {
	int a = x, b = y;
	if(a < b)
		a += b, b = a - b, a -= b;
	while(a % b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	//printf("%d", x / b * y);
	return x / b * y;
}

int main() {
	int t, ans = 1;
	while(scanf("%d", &t) != EOF)
		ans = lcm(ans, t);
	printf("%d\n", ans);
}
