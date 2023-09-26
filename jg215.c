#include <stdio.h>

int main () {
	int x, y, z, s, f, t;
	scanf("%d%d%d", &s, &f, &t);
	x = s * 4 - f / 2 - t * 2;
	y = s * -4 + f / 2 + t * 3;
	z = s - t;
	if(x < 0 || y < 0 || z < 0 || f % 2)
		printf("0\n");
	else
		printf("%d\n%d\n%d\n", x, y, z);
	return 0;
}
