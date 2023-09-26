#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define f(k) (77 * k + 2222) % s
#define maxn 105
#define maxs maxn * maxn
#define maxc 10
#define maxk 2e7

struct hash {
	int index;
	int x;
	int y;
};

int max(int a, int b) {
	return a > b ? a : b;
}

void gettower(int tower[maxn][maxn][maxn], int n) {
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < i; ++j) {
			for(int k = 0; k < i; ++k) {
				scanf("%d", &tower[i-1][j][k]);
			}
		}
	}
}

int main() {
	int n, s, c;
	scanf("%d%d%d", &n, &s, &c);
	
	assert(n <= maxn);

	int tower[maxn][maxn][maxn];
	gettower(tower, n);

	int height[maxn][maxn];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			height[i][j] = n - max(i, j);
		}
	}

	struct hash hashtable[maxs][maxc], tmp1, tmp2;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			int ind = tower[n - height[i][j]][i][j];
			int key = f(ind), k = 0;
			while(k < c && hashtable[key][k].index != ind)
				k++;
			if(k < c) {
				/* this index has appeared twice. */
				tmp1 = hashtable[key][k];
				tmp2.index = ind, tmp2.x = i, tmp2.y = j;
				hashtable[key][k].index = 0;
				continue;
			}
			k = 0;
			while(k < c && hashtable[key][k].index > 0)
				k++;
			/* insert the index into the hash table */
			hashtable[key][k].index = ind;
			hashtable[key][k].x = i;
			hashtable[key][k].y = j;
		}
	}

	bool haspair = 1, first = 1;
	struct hash tmp0;
	while(haspair) {
		/* eliminate the same numbers a.k.a. tmp1 and tmp2 */ 
#ifdef DEBUG
		printf("index: %d x1: %d y1: %d x2: %d y2: %d\n", tmp1.index, tmp1.x, tmp1.y, tmp2.x, tmp2.y);
#endif

#ifndef DEBUG
		printf("%c%d", (first? '\0' : ' '), tmp1.index);
#endif
		first = 0;
		height[tmp1.x][tmp1.y]--;
		height[tmp2.x][tmp2.y]--;
		if(height[tmp1.x][tmp1.y] > 0)
			tmp1.index = tower[n - height[tmp1.x][tmp1.y]][tmp1.x][tmp1.y];
		if(height[tmp2.x][tmp2.y] > 0)
			tmp2.index = tower[n - height[tmp2.x][tmp2.y]][tmp2.x][tmp2.y];
		if(height[tmp1.x][tmp1.y] && height[tmp2.x][tmp2.y] && tmp1.index == tmp2.index)
			continue;

		if(height[tmp1.x][tmp1.y] > 0) {
#ifdef DEBUG
			printf("into function f1, tmp1 is %d\n", tmp1.index);
#endif
			int key1 = f(tmp1.index), k1 = 0;
			while(k1 < c && hashtable[key1][k1].index != tmp1.index) 
				k1++;
			if(k1 < c) {
#ifdef DEBUG
				printf("tmp1 has the pair and tmp2 won't have\n");
#endif
				if(height[tmp2.x][tmp2.y] > 0) {
#ifdef DEBUG
					printf("push tmp2 into the hash table\n");
#endif
					/* push tmp2 into the hash table */
					int k2 = 0, key2 = f(tmp2.index);
					while(k2 < c && hashtable[key2][k2].index > 0)
						k2++;
					hashtable[key2][k2] = tmp2;
#ifdef DEBUG
					printf("pushed %d into the hash table.\n", tmp2.index);
#endif
				}
				tmp2 = hashtable[key1][k1];
#ifdef DEBUG
				printf("%d\n", tmp2.index);
#endif
			}
			else {
				k1 = 0;
				while(k1 < c && hashtable[key1][k1].index > 0)
					k1++;
				/* insert the index into the hash table */
				hashtable[key1][k1] = tmp1;
			}
		}		
		else if(height[tmp2.x][tmp2.y] > 0) {
#ifdef DEBUG
			printf("into function f2, tmp2 is %d\n", tmp2.index);
#endif
			int key2 = f(tmp2.index), k2 = 0;
			while(k2 < c && hashtable[key2][k2].index != tmp2.index) 
				k2++;
			if(k2 < c) {
#ifdef DEBUG
				printf("tmp2 has the pair and tmp1 won't have\n");
#endif
				if(height[tmp1.x][tmp1.y] > 0) {
					int k1 = 0, key1 = f(tmp1.index);
					while(k1 < c && hashtable[key1][k1].index > 0)
						k1++;
					hashtable[key1][k1] = tmp1;
#ifdef DEBUG
					printf("pushed %d into the hash table.\n", tmp1.index);
#endif
				}
				tmp1 = hashtable[key2][k2];
#ifdef DEBUG
				printf("%d\n", tmp1.index);
#endif
			}
			else {
				k2 = 0;
				while(k2 < c && hashtable[key2][k2].index > 0)
					k2++;
				/* insert the index into the hash table */
				hashtable[key2][k2] = tmp2;
			}
		}
		else
			haspair = 0;
	}
	printf("\n");
}
