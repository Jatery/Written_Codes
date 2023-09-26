#include <stdio.h>

int main() {
	int t, n, a = 0, b = 0, c = 0;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		n %= 3;
		switch(n) {
			case 0:
				a++;
				break;
			case 1:
				b++;
				break;
			case 2:
				c++;
				break;
		}
	}
	printf("%d %d %d\n", a, b, c);
	return 0;
}
