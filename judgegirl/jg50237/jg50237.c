#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define MAXSTRINGLENGTH 5
#define MAXN 100

int max(int a, int b) {
	return (a > b ? a : b);
}

int hashIndex(char str[MAXSTRINGLENGTH], int n) {
	int s = 0;
	for(int i = 0; i < strlen(str); ++i) {
		s = (s + str[i] - 'a' + 1) * 29;
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

void getTower(Tower *tower, Hash hash[MAXN * MAXN][10], int n) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			for(int k = 0; k <= i; ++k) {
				scanf("%s", tower->string[i][j][k]);
			}
			tower->height[i][j] = n - max(i, j);
		}
	}
#ifdef DEBUG
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j <= i; ++j) {
			for(int k = 0; k <= i; ++k)
				printf("%s ", tower->string[i][j][k]);
			printf("\n");
		}
#endif
}

void pushTable(Tower tower, Hash *hash, Hash *tmp, int n) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			
		}
	}
}

int main() {
	int n;
	Tower tower;
	Hash hash[MAXN * MAXN][10], tmp[2];
	scanf("%d", &n);

	assert(n <= MAXN);

	getTower(&tower, hash, n);
	pushTable(tower, *hash, tmp, n);

}
