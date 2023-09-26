#include <stdio.h>
#include "intersection.h"

void intersection(int map[100][100], int result[4]) {
	result[0] = result[1] = result[2] = result[3] = 0;
	for(int i = 0; i < 100; ++i)
		for(int j = 0; j < 100; ++j) 
			if(map[i][j]) {
				int cnt = 0;
				if(i > 0 && map[i-1][j])
					cnt+=1;
				if(i < 99 && map[i+1][j])
					cnt+=2;
				if(j > 0 && map[i][j-1])
					cnt+=4;
				if(j < 99 && map[i][j+1])
					cnt+=8;
				switch(cnt) {
					case 15:
						++result[0];
						break;
					case 14: case 13: case 11: case 7:
						++result[1];
						break;
					case 5: case 9: case 6: case 10:
						++result[2];
						break;
					case 1: case 2: case 4: case 8:
						++result[3];
						break;
				}
			}
}
/*
int main() {
	int map[100][100], result[4];
	for(int i = 0; i < 100; ++i)
		for(int j = 0; j < 100; ++j)
			scanf("%d", map[i][j]);
	intersection(map, result);
	printf(result[0])
}
*/
