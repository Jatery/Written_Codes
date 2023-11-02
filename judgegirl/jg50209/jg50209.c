#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char keyboard[5][12] = {"            ",
							" qwertyuiop ", 
							" asdfghjkl; ", 
							" zxcvbnm,./ ", 
							"            "};
	char input;
	int x = 0, y = 0, dir;
	int moves[6][2] = {{0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}};
	scanf("%c", &input);
	for(int i = 1; i < 4 && x == 0 && y == 0; ++i) {
		for(int j = 1; j < 11 && x == 0 && y == 0; ++j) {
			if(keyboard[i][j] == input) {
				x = i;
				y = j;
			}
		}
	}
	printf("%c\n", keyboard[x][y]);
	while(scanf("%d", &dir) != EOF) {
		if(isalpha(keyboard[x + moves[dir][0]][y + moves[dir][1]]) > 0) {
			x += moves[dir][0];
			y += moves[dir][1];
			printf("%c\n", keyboard[x][y]);
		}
	}
}
