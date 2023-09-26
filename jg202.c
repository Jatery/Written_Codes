#include <stdio.h>

int main() {
	int a, b, c, d, e, f, g;
	scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
	int num1 = (a >= 0 ? a * c + b : a * c - b), den1 = c, num2 = (e >= 0 ? e * g + f : e * g - f), den2 = g, num, den, flag = 0;
	switch(d) {
		case 0:
			num = num1 * den2 + num2 * den1;
			den = den1 * den2;
			break;
		case 1:
			num = num1 * den2 - num2 * den1;
			den = den1 * den2;
			break;
		case 2:
			num = num1 * num2;
			den = den1 * den2;
			break;
		case 3:
			num = num1 * den2;
			den = den1 * num2;
			if(den < 0)
				den = -den, num = -num;
			break;
	}
	//printf("%d %d\n", num, den);
	if(num < 0)
		num = -num, flag = 1;	
	int p = num, q = den;
	if(p < q)
		p += q, q = p - q, p -= q;
	while(p % q > 0) {
		p %= q;
		p += q, q = p - q, p -= q;
	}
	num /= q, den /= q;
	if(flag)
		printf("-");
	printf("%d\n%d\n%d\n", num / den, num % den, den);
	return 0;
}
