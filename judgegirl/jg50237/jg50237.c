#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSTRINGLENGTH 6
#define MAXN 100

int max(int a, int b) {
	return (a > b ? a : b);
}

int hashIndex(char str[], int n) {
	int s = 0;
	for(int i = 0; i < strlen(str); ++i) {
		s = s * 29 + (str[i] - 'a' + 1);
	}
	return s % (n * n);
}

typedef struct{
	char string[MAXN][MAXN][MAXN][MAXSTRINGLENGTH];
	int height[MAXN][MAXN];
} Tower;

typedef struct{
	char index[MAXSTRINGLENGTH];
	int x;
	int y;
} Hash;

void getTower(Tower *tower, int n) {
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < i; ++j) {
			for(int k = 0; k < i; ++k) {
				scanf("%s", tower->string[n - i][j][k]);
			}	
		}
	}
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			tower->height[i][j] = n - max(i, j);
}

void pushTable(Tower tower, Hash hash[][10], Hash tmp[], int n) {
	bool flag = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {	
			int key = hashIndex(tower.string[tower.height[i][j] - 1][i][j], n);
			for (int k = 0; k < 10; ++k) {
				if (strcmp(hash[key][k].index, tower.string[tower.height[i][j] - 1][i][j]) == 0) {
					tmp[0] = hash[key][k];
					strcpy(tmp[1].index, tower.string[tower.height[i][j] - 1][i][j]);
					tmp[1].x = i;
					tmp[1].y = j;
					hash[key][k].index[0] = '\0';
					flag = 1;
					break;
				}
			}
			if (!flag) {
				int k = 0;
				while (hash[key][k].index[0] != '\0')
					k++;
				assert (k < 10);
				strcpy(hash[key][k].index, tower.string[tower.height[i][j] - 1][i][j]);
				hash[key][k].x = i;
				hash[key][k].y = j;
				flag = 0;
			}
		}
	}
}

void popTower (Tower *tower, Hash tmp[2]) {
	printf("%s\n", tmp[0].index);
	tower->height[tmp[0].x][tmp[0].y]--;
	tower->height[tmp[1].x][tmp[1].y]--;
	for (int i = 0; i < 2; ++i) {
		if (tower->height[tmp[i].x][tmp[i].y] > 0)
			strcpy(tmp[i].index, tower->string[tower->height[tmp[i].x][tmp[i].y] - 1][tmp[i].x][tmp[i].y]);
		else
			tmp[i].index[0] = '\0';
	}
}

int findPair (Hash hash[][10], char index[MAXSTRINGLENGTH], int n) {
	if (strcmp(index, "") == 0)
		return -1;
	int k = 0, key = hashIndex(index, n);
	while (k < 10 && strcmp(hash[key][k].index, index) != 0)
		k++;
	if (k == 10)
		return -1;
	return k;
}

void insertHash(Hash hash[][10], Hash tmp, int n) {
	assert (findPair(hash, tmp.index, n) == -1);
	if (tmp.index[0] == '\0')
		return;
	int k = 0, key = hashIndex(tmp.index, n);
	while(hash[key][k].index[0] != '\0')
		k++;
	assert(k < 10 && hash[key][k].index[0] == '\0');
	hash[key][k] = tmp;
}

int main() {
	int n;
	Tower tower;
	
	scanf("%d", &n);

	assert(n <= MAXN);

	Hash hash[n * n][10], tmp[2];
	for (int i = 0; i < n * n; ++i) {
		for (int j = 0; j < 10; ++j)
			hash[i][j].index[0] = '\0';
	}

	getTower(&tower, n);
	pushTable(tower, hash, tmp, n);
	
	bool haspair = 1;
	while (haspair) {
		haspair = 0;
		popTower(&tower, tmp);

		if (tmp[0].index[0] != '\0' && strcmp(tmp[0].index, tmp[1].index) == 0) {
			haspair = 1;
			continue;
		}
		for (int i = 0; i < 2; ++i) {
			if (findPair(hash, tmp[i].index, n) >= 0) {
				haspair = 1;
				assert (findPair(hash, tmp[i ^ 1].index, n) == -1);
				insertHash(hash, tmp[i ^ 1], n);
				tmp[i ^ 1] = hash[hashIndex(tmp[i].index, n)][findPair(hash, tmp[i].index, n)];
				hash[hashIndex(tmp[i].index, n)][findPair(hash, tmp[i].index, n)].index[0] = '\0';
				break;
			}
		}
	}
	assert (!haspair);
}
