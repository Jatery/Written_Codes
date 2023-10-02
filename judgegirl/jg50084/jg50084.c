#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MAX 500
#define maxp 100
#define maxq 500

int max(int a, int b) {
	return  a > b ? a : b;
}

typedef struct Task {
	int machine;
	int time;
}task;

bool jobfinish(int jobamount[MAX], int jobsequence[MAX], int M) {
	for(int i = 0; i < M; ++i)
		if(jobsequence[i] < jobamount[i])
			return 0;
	return 1;
}

int jobchosen(int machine[MAX], int jobamount[MAX], int jobsequence[MAX], int jobtime[MAX], task jobs[MAX][maxq], int N, int M) {
	int i = 0, ans;
	while(jobsequence[i] == jobamount[i])
		++i;
	ans = i;
	++i;
	while(i < M) {
		if(jobsequence[i] < jobamount[i])
			if(max(machine[jobs[i][jobsequence[i]].machine], jobtime[i]) + jobs[i][jobsequence[i]].time < max(machine[jobs[ans][jobsequence[ans]].machine], jobtime[ans]) + jobs[ans][jobsequence[ans]].time)
				ans = i;
		++i;
	}
	return ans;
}

int main() {
	int N, M, machine[MAX], jobamount[MAX], jobsequence[MAX], jobtime[MAX];
	scanf("%d%d", &N, &M);
	assert(N > 0 && N < MAX);
	assert(M > 0 && M < MAX);
	task jobs[MAX][maxq];
	for(int i = 0; i < N; ++i)
		machine[i] = 0;
	for(int i = 0; i < M; ++i) {
		jobsequence[i] = 0;
		scanf("%d%d", &jobtime[i], &jobamount[i]);
		assert(jobtime[i] >= 0 && jobtime[i] < maxp);
		assert(jobamount[i] > 0 && jobamount[i] < maxq);
		for(int j = 0; j < jobamount[i]; ++j) {
			scanf("%d%d", &jobs[i][j].machine, &jobs[i][j].time);
			assert(jobs[i][j].time < 100);
		}
	}
	
	while(!jobfinish(jobamount, jobsequence, M)) {
		int t = jobchosen(machine, jobamount, jobsequence, jobtime, jobs, N, M);
#ifdef DEBUG
		printf("Num.%d of Job %d on machine %d\n", jobsequence[t], t, jobs[t][jobsequence[t]].machine);
#endif

		jobtime[t] = machine[jobs[t][jobsequence[t]].machine] = max(machine[jobs[t][jobsequence[t]].machine], jobtime[t]) + jobs[t][jobsequence[t]].time;
		jobsequence[t]++;
	}

	for(int i = 0; i < M; ++i) {
		printf("%d\n", jobtime[i]);
	}

}
