#include <stdio.h>

int main() {
	int n, m, tmp = 100000, cnt = 0;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < 6; ++i, tmp /= 10) 
		if(m / tmp - m / tmp / 100 * 100 == n)
			cnt++;
	printf("%d\n", cnt);
	return 0;
}
