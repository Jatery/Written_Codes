#include <stdio.h>

int main() {
	FILE *fp;
	fp = fopen("level1.txt", "r");
	char map[100][100];
	int n = 0, m = 0, k = 0;
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
	}
	map[n][k] = '\0';
	n++;
	if (k > m) {
		m = k;
	}
	printf("\n%d %d\n", n, m);
	char solution[100] = "";
	for (int i = 0; i < n; ++i) {
		printf("%s\n", map[i]);
	}
}
