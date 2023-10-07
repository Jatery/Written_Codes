#include <stdio.h>
#include <assert.h>

#define min(a, b) a < b ? a : b

int main() {
	int T, C, D, distance;
	scanf("%d%d%d%d", &T, &C, &D, &distance);
	assert(T > C && C > D);
	int locT = T, locC = C, locD = D;
	long long pulls = 0;

#ifdef DEBUG
	printf("%3d:", pulls);
	for(int i = 1; i <= distance; ++i) {
		if(i > locD - D && i <= locD)
			printf("D");
		else if(i > locC - C && i <= locC)
			printf("C");
		else if(i > locT - T && i <= locT)
			printf("T");
		else
			printf("-");
	}
	printf("\n");
#endif

	/* goal: every pull should be the maximum amount that moment can pull */

	while(locD < distance) {
		if(locD < locC) {
			locD = locC;
			pulls++;
		}
		else if(locC < locT && (locD - D + C <= locT || locT >= distance)) {
			locC = min(locT, locD - D + C);
			pulls++;
		}
		else {
			locT = min(distance, locC - C + T);
			pulls++;
		}

#ifdef DEBUG
		printf("%3d:", pulls);
		for(int i = 1; i <= distance; ++i) {
			if(i > locD - D && i <= locD)
				printf("D");
			else if(i > locC - C && i <= locC)
				printf("C");
			else if(i > locT - T && i <= locT)
				printf("T");
			else
				printf("-");
		}
		printf("\n");
#endif

	}
	printf("%lld\n", pulls);
}
