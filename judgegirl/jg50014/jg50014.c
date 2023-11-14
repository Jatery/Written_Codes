#include <stdio.h>
#include "subset.h"
 
int subset(int numbers[], int n, int K, int S) {
	if(K < 0)
		return 0;
	if(S == 0)
		return K == 0;
	if(n < S)
		return 0;
	return subset(numbers, n - 1, K - numbers[n - 1], S - 1) | subset(numbers, n - 1, K, S);	
}

int main() {
    int n, K, S;
    while (scanf("%d %d %d", &n, &K, &S) == 3) {
        int A[128];
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        printf("%d\n", subset(A, n, K, S));
    }
    return 0;
}
