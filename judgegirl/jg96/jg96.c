#include <stdio.h>
#define pi 3.1415926

int main() {
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	double ans = c * c * pi * 3 / 4;
	if(c > a)
		ans += (c-a) * (c-a) * pi / 4;
	if(c > b)
		ans += (c-b) * (c-b) * pi / 4;
	printf("%f\n", ans);
}
