#include <stdio.h>
#include <stdbool.h>

int main () {
	int t;
	scanf("%d", &t);
	while(t--) {
		int x0, y0, x1, y1, x2, y2, x3, y3, length = 0, angle = 0;
		bool ang12, ang23, ang31;
		scanf("%d%d%d%d%d%d%d%d", &x0, &y0, &x1, &y1, &x2, &y2, &x3, &y3);
		x1 -= x0, y1 -= y0;
		x2 -= x0, y2 -= y0;
		x3 -= x0, y3 -= y0;
		ang12 = x1 * y2 - y1 * x2 > 0 ? 1 : 0;
		ang23 = x2 * y3 - y2 * x3 > 0 ? 1 : 0;
		ang31 = x3 * y1 - y3 * x1 > 0 ? 1 : 0;
		printf("%d %d %d\n", ang12, ang23, ang31);
		if(ang12 && !ang23 && !ang31) {

		}
		/* if(n1x * n2x + n1y * n2y > 0 && n2x * n3x + n2y * n3y > 0)
			n4x = -n3x, n4y = -n4y, n3x -=n2x, n3y -= n2y, n2x -= n1x, n2y -= n1y;
		else if(n1x * n2x + n1y * n2y > 0 && n1x * n3x)
		printf("%d %d %d %d %d %d %d %d\n", n1x, n1y, n2x, n2y, n3x, n3y, n4x, n4y);
		if(n1x * n1x + n1y * n1y == n2x * n2x + n2y * n2y == n3x * n3x + n3y * n3y == n4x * n4x + n4y * n4y)
			length = 2;
		if((n1x * n2x + n1y * n2y == 0) && !(n2x * n3x + n2y * n3y == 0) && !(n3x * n4x + n3y * n4y == 0) && !(n4x * n1x + n4y * n1y == 0))
			angle = 1;
		switch(length + angle) {
			case 3:
				printf("square\n");
			case 2:
				printf("diamond\n");
			case 1:
				printf("rectangle\n");
			case 0:
				printf("other\n");
		}	*/
	}
	return 0;
}
