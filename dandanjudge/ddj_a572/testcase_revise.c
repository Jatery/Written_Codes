#include <stdio.h>
#include <string.h>

int main() {
	FILE *fp, *fpRevise;
	int w = 6;
	while (w--) {
		char path[] = "a572_0 .in";
		char pathRevise[] = "revise/a572_0 .in";
		path[strstr(path, " ") - path] = w + '0';
		pathRevise[strstr(pathRevise, " ") - pathRevise] = w + '0';
		fp = fopen(path, "r");
		fpRevise = fopen(pathRevise, "w+");
		int n;
		fscanf(fp, "%d", &n);
		fprintf(fpRevise, "%d\n", n);
		for (int i = 0; i < n; i++) {
			int x, y;
			fscanf(fp, "%d %d", &x, &y);
			if (x < y)
				fprintf(fpRevise, "%d %d\n", x, y);
			else
				fprintf(fpRevise, "%d %d\n", y, x);
		}
		fclose(fp);
		fclose(fpRevise);
	}
}
