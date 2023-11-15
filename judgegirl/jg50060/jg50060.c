#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 14

bool hasBeen(int diary[MAXN], int index, int N) {
	for(int i = 0; i < N; ++i) {
		if(diary[i] == index)
			return 1;
	}
	return 0;
}

void findShortestPath(int distance[MAXN][MAXN], int diary[MAXN], int index, int N, int currentSolution, int *bestSolution) {
	if(currentSolution >= *bestSolution)
		return;
	assert(currentSolution < *bestSolution);
	if(index == N) {
		if(currentSolution + distance[diary[index - 1]][0] < *bestSolution)
		*bestSolution = currentSolution + distance[diary[index - 1]][0];
		return;
	}
	for(int  i = 1; i < N; ++i) {
		if(!hasBeen(diary, i, index)) {
			diary[index] = i;
			findShortestPath(distance, diary, index + 1, N, currentSolution + distance[diary[index - 1]][i], bestSolution);
			diary[index] = 0;
		}
	}
	
}

int main() {
	int N;
	scanf("%d", &N);
	assert(N <= MAXN);
	int distance[MAXN][MAXN];
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			scanf("%d", &distance[i][j]);
			assert(distance[i][j] <= 100);
		}
	}
	int bestSolution = INT_MAX;
	int diary[MAXN] = {0};
	findShortestPath(distance, diary, 1, N, 0, &bestSolution);
	printf("%d\n", bestSolution);
}
