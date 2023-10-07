#include <stdio.h>
#include <assert.h>

#define min(a, b) a < b ? a : b

int main() {
	int T, C, D, distance;
	scanf("%d%d%d%d", &T, &C, &D, &distance);
	assert(T > C && C > D);
	int locT = T, locC = C, locD = D, pulls = 0;

	while(locD < distance) {
		if(locD < locC) {
#ifdef DEBUG
			printf("pull %d, pulled D from %d to %d\n", pulls + 1, locD, locC);
#endif
			locD = locC;
			pulls++;
		}
		else if(locC < locT) {
#ifdef DEBUG
			printf("pull %d, pulled C from %d to %d\n", pulls + 1, locC, min(locT, locD - D + C));
#endif
			locC = min(locT, locD - D + C);
			pulls++;
		}
		else {
#ifdef DEBUG
			printf("pull %d, pulled T from %d to %d\n", pulls + 1, locT, locC - C + T);
#endif
			locT = locC - C + T;
			pulls++;
		}
	}

	printf("%d\n", pulls);
}
