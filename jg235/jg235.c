#include <stdio.h>

struct fraction {
	int nom;
	int den;
};

void simplify(struct fraction *inpt) {
	if((*inpt).nom == 0) {
		(*inpt).den = 1;
		return;
	}	
	int a = (*inpt).den, b = (*inpt).nom;
	while(a % b != 0)
		a %= b, a += b, b = a - b, a -= b;
	(*inpt).den /= b, (*inpt).nom /= b;
	return;
}

struct fraction add(struct fraction a, struct fraction b) {
	struct fraction sum;
	sum.den = a.den * b.den;
	sum.nom = a.nom * b.den + b.nom * a.den;
	simplify(&sum);
	return sum;
}

struct fraction multiply(struct fraction a, struct fraction b) {
	struct fraction ans;
	ans.den = a.den * b.den;
	ans.nom = a.nom * b.nom;
	simplify(&ans);
	return ans;
}

int main() {
	int n, a, b;
	scanf("%d", &n);
	struct fraction arr[n + 1];
	//initialize
	arr[0].nom = 1;
	arr[0].den = 1;
	for(int i = 1; i <= n; ++i) {
		arr[i].nom = 0;
		arr[i].den = 1;
	}

	for(int i = 0; i < n; ++i) {
		for(int j = i; j >= 0; --j) {
			scanf("%d%d", &a, &b);
			struct fraction push, transform;
			push.den = a + b, push.nom = a;
			transform.den = a + b, transform.nom = b;
			simplify(&push);
			simplify(&transform);
			arr[j + 1] = add(arr[j + 1], multiply(arr[j], push));
			arr[j] = multiply(arr[j], transform);
		}
	}
	for(int i = n; i >= 0; --i)
		printf("%d/%d\n", arr[i].nom, arr[i].den);
}
