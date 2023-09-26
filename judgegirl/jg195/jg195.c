#include <stdio.h>
#include <stdbool.h>

bool black_wins(int map[3][3]) {
	for(int i = 0; i < 3; ++i) {
		if(map[i][0] == 0 && map[i][1] == 0 && map[i][2] == 0)
			return 1;
		if(map[0][i] == 0 && map[1][i] == 0 && map[2][i] == 0)
			return 1;
	}
	if(map[0][0] == 0 && map[1][1] == 0 && map[2][2] == 0)
		return 1;
	if(map[0][2] == 0 && map[1][1] == 0 && map[2][0] == 0)
		return 1;
	return 0;
}

bool white_wins(int map[3][3]) {
	for(int i = 0; i <= 2; ++i) {
		if(map[i][0] == 1 && map[i][1] == 1 && map[i][2] == 1)
			return 1;
		if(map[0][i] == 1 && map[1][i] == 1 && map[2][i] == 1)
			return 1;
	}
	if(map[0][0] == 1 && map[1][1] == 1 && map[2][2] == 1)
		return 1;
	if(map[0][2] == 1 && map[1][1] == 1 && map[2][0] == 1)
		return 1;
	return 0;
}

int main() {
	int n, x, y, turns = 0;
	int map[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &x, &y);
		if(x < 0 || x > 2 || y < 0 || y > 2 || map[x][y] != -1)
			continue;
		map[x][y] = turns;
		turns ^= 1;
		//printf("%d\n", turns);
	}
	if(black_wins(map))
		printf("Black wins.\n");
	else if(white_wins(map))
		printf("White wins.\n");
	else
		printf("There is a draw.\n");
	/*
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j)
			printf("%3d", map[i][j]);
		printf("\n");
	}
	*/
}
