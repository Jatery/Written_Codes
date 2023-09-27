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
				scanf("%d", &tower[n - i][j][k]);
			}
		}
	}
}

void getheight(int height[maxn][maxn], int n) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			height[i][j] = n - max(i, j);
		}
	}
}

void initializehash(int tower[maxn][maxn][maxn],int height[maxn][maxn], int n, int s, int c, struct hash hashtable[maxs][maxc], struct hash tmp[2]) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			int index = tower[height[i][j] - 1][i][j];
			int key = f(index), k = 0;
			while(k < c && hashtable[key][k].index != index)
				k++;
			if(k < c) {
				/* this index has appeared twice. */
				tmp[0] = hashtable[key][k];
				tmp[1].index = index, tmp[1].x = i, tmp[1].y = j;
				hashtable[key][k].index = 0;
#ifdef DEBUG
				printf("%d %d\n", tmp[0].index, tmp[1].index);
#endif
				continue;
			}
			k = 0;
			while(k < c && hashtable[key][k].index > 0)
				k++;
			/* insert the index into the hash table */
			hashtable[key][k].index = index;
			hashtable[key][k].x = i;
			hashtable[key][k].y = j;
		}
	}
}

void poptower(int height[maxn][maxn], int tower[maxn][maxn][maxn], struct hash tmp[2]) {
	printf("%d ", tmp[0].index);
	height[tmp[0].x][tmp[0].y]--;
	height[tmp[1].x][tmp[1].y]--;
	if(height[tmp[0].x][tmp[0].y] > 0)
		tmp[0].index = tower[height[tmp[0].x][tmp[0].y] - 1][tmp[0].x][tmp[0].y];
	else
		tmp[0].index = 0;
	if(height[tmp[1].x][tmp[1].y] > 0)
		tmp[1].index = tower[height[tmp[1].x][tmp[1].y] - 1][tmp[1].x][tmp[1].y];
	else
		tmp[1].index = 0;
}

int findpair(struct hash hashtable[maxs][maxc], int index, int s, int c) {
	if(index == 0)
		return -1;
	int k = 0, key = f(index);
	while(k < c && hashtable[key][k].index != index)
		k++;
	if(k == c)
		return -1;
	else
		return k;
}

void inserthashtable(struct hash hashtable[maxs][maxc], struct hash inpt, int s, int c) {
	assert(findpair(hashtable, inpt.index, s, c) == -1);
	if(inpt.index == 0)
		return;
	int k = 0, key = f(inpt.index);
	while(hashtable[key][k].index > 0)
		k++;
	assert(k < c && hashtable[key][k].index == 0);
	hashtable[key][k] = inpt;
	return;
}

int main() {
	int n, s, c;
	scanf("%d%d%d", &n, &s, &c);
	
	assert(n <= maxn);
	assert(s <= n * n);
	assert(c <= maxc);

	int tower[maxn][maxn][maxn];
	gettower(tower, n);

	int height[maxn][maxn];
	getheight(height, n);
	

	struct hash hashtable[maxs][maxc], tmp[2];
	/* initialize hashtable */
	initializehash(tower, height, n, s, c, hashtable, tmp);

	bool haspair = 1, first = 1;
	while(haspair) {
		//find tmp[0] has pair?;
		//
		//true then assert tmp[1] no pair;
		//
		//insert tmp[1] to hashtable and move tmp[1] to the pair;
		//
		//else
		//
		//find tmp[1] has pair?;
		//
		//true then assert tmp[0] no pair;
		//
		//insert tmp[0] to hashtable and move tmp[0] to the pair;

		/* eliminate the same numbers a.k.a. tmp1 and tmp2 */ 
		haspair = 0;

		poptower(height, tower, tmp);
		
		if(tmp[0].index > 0 && tmp[0].index == tmp[1].index) {
			haspair = 1;
			continue;
		}
		
		if(findpair(hashtable, tmp[0].index, s, c) >= 0) {
			haspair = 1;
			assert(findpair(hashtable, tmp[1].index, s, c) == -1);
			inserthashtable(hashtable, tmp[1], s, c);
			tmp[1] = hashtable[f(tmp[0].index)][findpair(hashtable, tmp[0].index, s, c)];
			hashtable[f(tmp[0].index)][findpair(hashtable, tmp[0].index, s, c)].index = 0;
			continue;
		}

		if(findpair(hashtable, tmp[1].index, s, c) >= 0) {
			haspair = 1;
			assert(findpair(hashtable, tmp[0].index, s, c) == -1);
			inserthashtable(hashtable, tmp[0], s, c);
			tmp[0] = hashtable[f(tmp[1].index)][findpair(hashtable, tmp[1].index, s, c)];
			hashtable[f(tmp[1].index)][findpair(hashtable, tmp[1].index, s, c)].index = 0;
			continue;
		}
		
		assert(haspair == 0);
				
	}
	printf("\n");
}
