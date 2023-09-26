#include <stdio.h>

int main() {
	int a = 0, b = 0, m, n;
	scanf("%d%d", &m, &n);
	for(int i = 0; i < 4; ++i) {
		int test1 = 1, test2 = 1;
		for(int j = 0; j < i; ++j)
			test1 *= 10;
		test2 = test1 * 10;
		for(int j = 0; j < 4; ++j) {
			int test3 = 1, test4 = 1;
			for(int k = 0; k < j; ++k)
				test3 *= 10;
			test4 = test3 * 10;
			//printf("%d %d %d %d\n", test1, test2, test3, test4);
			//printf("%d %d\n", (m / test1) - (m / test2) * 10, (n / test3) - (n / test4) * 10);
			if((m / test1) - (m / test2) * 10 == (n / test3) - (n / test4) * 10) {
				if(i == j)
					a++;
				else
					b++;
			}
		}
	}
	printf("%dA%dB\n", a, b);
	return 0;
}
