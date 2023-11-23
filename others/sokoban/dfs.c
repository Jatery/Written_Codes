#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int playerPos[2];
	int boxPos[10][2];
	int goalPos[10][2];
} Status;

int isGoal(Status status, const int boxCount) {
	for (int i = 0; i < boxCount; ++i) {
		bool flag = false;
		for (int j = 0; j < boxCount; ++j) {
			if (status.boxPos[i][0] == status.goalPos[j][0] && status.boxPos[i][1] == status.goalPos[j][1]) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			return 0;
		}
	}
	return 1;
}

int isExplored(Status status, Status explored[], const int exploredIndex, const int boxCount) {
	for (int i = 0; i < exploredIndex; ++i) {
		bool flag = true;
		if (status.playerPos[0] != explored[i].playerPos[0] || status.playerPos[1] != explored[i].playerPos[1]) {
			flag = false;
			continue;
		}
		for (int j = 0; j < boxCount; ++j) {
			bool subflag = false;
			for (int k = 0; k < boxCount; ++k) {
				if (status.boxPos[j][0] == explored[i].boxPos[k][0] && status.boxPos[j][1] == explored[i].boxPos[k][1]) {
					subflag = true;
					break;
				}
			}
			if (!subflag) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return 1;
		}
	}
	return 0;
}

bool isLegal(Status status, char map[100][100], int direction[], const int boxCount) {
	int nextPlayerPos[2] = {status.playerPos[0] + direction[0], status.playerPos[1] + direction[1]};
	if (map[nextPlayerPos[0]][nextPlayerPos[1]] == '#') {
		return false;
	}
	for (int i = 0; i < boxCount; ++i) {
		if (status.boxPos[i][0] == nextPlayerPos[0] && status.boxPos[i][1] == nextPlayerPos[1]) {
			int nextBoxPos[2] = {status.boxPos[i][0] + direction[0], status.boxPos[i][1] + direction[1]};
			if (map[nextBoxPos[0]][nextBoxPos[1]] == '#') {
				return false;
			}
			for (int j = 0; j < boxCount; ++j) {
				if (status.boxPos[j][0] == nextBoxPos[0] && status.boxPos[j][1] == nextBoxPos[1]) {
					return false;
				}
			}
		}
	}
	return true;
}
/*
bool isFailed(Status status, char map[][], const int boxCount) {
	int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
		for (int i = 0; i < boxCount; ++i) {
		bool flag = false;
		bool inGoal = false;
		for (int j = 0; j < boxCount; ++j) {
			if (status.boxPos[i][0] == status.goalPos[j][0] && status.boxPos[i][1] == status.goalPos[j][1]) {
				inGoal = true;
				break;
			}
		}
		if (inGoal) {
			continue;
		}
		for (int j = 0; j < 4; ++j) {
			if (map[x + direction[j][0]][y + direction[j][1]] == '#' && map[x + direction[(j+1)%4][0]][y + direction[(j + 1) % 4][1]] == '#') {
				return true;
			}
			for (int k = 0; k < boxCount; ++k) {
				if (status.boxPos[k][0] == nextBoxPos[0] && status.boxPos[k][1] == nextBoxPos[1]) {
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		else {
			for (j = 0; j < )
		}
	}
	return true;
}
*/
void dfs(char solution[], char map[100][100], const int n, const int m, const int boxCount, int exploredIndex, Status explored[], Status currentStatus) {
	if (isGoal(currentStatus, boxCount)) {
		printf("%s\n", solution);
		exit(0);
	}
	if (exploredIndex == 1000) {
		printf("No solution\n");
		return;
	}
	if (isExplored(currentStatus, explored, exploredIndex, boxCount)) {
		return;
	}
	explored[exploredIndex] = currentStatus;
	exploredIndex++;
	int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	for (int i = 0; i < 4; ++i) {
		if (isLegal(currentStatus, map, direction[i], boxCount)) {
			Status nextStatus = currentStatus;
			nextStatus.playerPos[0] += direction[i][0];
			nextStatus.playerPos[1] += direction[i][1];	
			for (int j = 0; j < boxCount; ++j) {
				if (nextStatus.boxPos[j][0] == nextStatus.playerPos[0] && nextStatus.boxPos[j][1] == nextStatus.playerPos[1]) {
					nextStatus.boxPos[j][0] += direction[i][0];
					nextStatus.boxPos[j][1] += direction[i][1];
					break;
				}
			}
			/*
			if (isFalied(nextStatus, map, boxCount)) {
				break;
			}*/
			char nextSolution[100] = "";
			strncpy(nextSolution, solution, strlen(solution));
			if (i == 0) {
				strcat(nextSolution, "U");
			}
			else if (i == 1) {
				strcat(nextSolution, "R");
			}
			else if (i == 2) {
				strcat(nextSolution, "D");
			}
			else {
				strcat(nextSolution, "L");
			}
			dfs(nextSolution, map, n, m, boxCount, exploredIndex, explored, nextStatus);
		}
		
	}
}

int main() {
	FILE *fp;
	fp = fopen("level1.txt", "r");
	Status initialStatus;
	int n = 0, m = 0, k = 0, boxCount = 0, goalCount = 0;
	char map[100][100];
	while((map[n][k] = fgetc(fp)) != EOF) {
		printf("%c", map[n][k]);
		if(map[n][k] == '\n') {
			map[n][k] = '\0';
			if (k > m) {
				m = k;
			}
			n++;
			k = 0;
		}
		else {
			k++;
		}
		if (map[n][k] == '&') {
			initialStatus.playerPos[0] = n;
			initialStatus.playerPos[1] = k;
		}
		if (map[n][k] == 'B' || map[n][k] == 'X') {
			initialStatus.boxPos[boxCount][0] = n;
			initialStatus.boxPos[boxCount][1] = k;
			boxCount++;
		}
		if (map[n][k] == '.' || map[n][k] == 'X') {
			initialStatus.goalPos[goalCount][0] = n;
			initialStatus.goalPos[goalCount][1] = k;
			goalCount++;
		}
	}
	assert(boxCount == goalCount);
	map[n][k] = '\0';
	n++;
	if (k > m) {
		m = k;
	}
	printf("\n%d %d\n", n, m);
	fclose(fp);
	char solution[100] = "";
	Status explored[1000];
	explored[0] = initialStatus;
	for (int i = 0; i < n; ++i) {
		printf("%s\n", map[i]);
	}
	dfs(solution, map, n, m, boxCount, 0, explored, initialStatus);
}
