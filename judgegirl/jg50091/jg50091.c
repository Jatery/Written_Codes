#include <stdio.h>
//#include "constructTable.h"
 
int **firstLevelTable[100];
int *secondLevelTable[100][100];

int ***constructTable(int A[], int B[]) {
	int indexA = 0, indexB = 0;
	while(A[indexA] != 0) {
		firstLevelTable[indexA] = secondLevelTable[indexA];
		for(int i = 0; i < A[indexA]; ++i) {
			secondLevelTable[indexA][i] = &(B[indexB]);
			while(B[indexB] != 0)
				indexB++;
			indexB++;
		}
		indexA++;
	}
	return firstLevelTable;
}

int main(){
    int N, M;
    int A[100] = {}, B[500] = {};
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &B[i]);
 
    int ***ptr;
    ptr = constructTable(A, B);
    for(int i = 0; *(ptr+i) != NULL; i++)
        for(int j = 0; j < A[i]; j++)
            for(int k = 0; *(*(*(ptr+i)+j)+k) != 0; k++)
                printf("%d ", *(*(*(ptr+i)+j)+k));
    return 0;
}
