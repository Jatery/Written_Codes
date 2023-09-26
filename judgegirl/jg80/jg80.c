#include <stdio.h>

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x1, y1, x2, y2, x3, y3, a, b, c;
		scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
		a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	   	b = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
		c = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
		/* printf("%d %d %d", a, b, c); */
		if(a == b || b == c || c == a)
			printf("isosceles\n");
		else {
			if(a > b)
				a += b, b = a - b, a -= b;
			if(b > c)
				b += c, c = b - c, b -= c;
			if(a > b)
				a += b, b = a - b, a -= b;
			if(a + b > c)
				printf("acute\n");
			else if(a + b < c)
				printf("obtuse\n");
			else
				printf("right\n");
		}
	}
	return 0;
}
