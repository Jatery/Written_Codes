#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000000

typedef struct {
	int index;
	int start;
	int end;
} Node;

int cmp(const void *a, const void *b) {
	Node *x = (Node *)a;
	Node *y = (Node *)b;
	return x->start - y->start;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int w = 6;
	while (w--) {
		char path[100] = "a572/a572_0 .in";
		char pathOut[100] = "a572/a572_0 .out";
		path[strstr(path, " ") - path] = w + '0';
		pathOut[strstr(pathOut, " ") - pathOut] = w + '0';
		FILE *fp = fopen(path, "r");
		FILE *fpOut = fopen(pathOut, "w+");
		int n;
		fscanf(fp, "%d", &n);
		Node *node = (Node *)malloc(sizeof(Node) * n);
		for (int i = 0; i < n; i++) {
			fscanf(fp, "%d%d", &node[i].start, &node[i].end);
			if (node[i].start > node[i].end) {
				printf("testcase line %d has error!\n", i + 1);
			}
			node[i].index = i + 1;
		}
		qsort(node, n, sizeof(Node), cmp);
		int haveAwake = 0;
		int index = 0;
		int firstTime = 1;
		for (int i = 0; i < n; i++) {
			if((firstTime == 1 || index <= node[i].start - 6) && node[i].start != node[i].end) {
				fprintf(fpOut, "Poor BFB No.%d died at time %d...\n", node[i].index, node[i].start);
				haveAwake = 1;
				firstTime = 0;
			}
			if (node[i].start != node[i].end) {
				index = max(index, node[i].end);
			}
		}
		if (haveAwake == 0) {
			fprintf(fpOut, "Every BFB is alive, it's another peaceful day.\n");
		}
		fclose(fp);
		fclose(fpOut);
	}
}
