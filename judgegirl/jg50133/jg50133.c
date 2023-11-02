#include <stdio.h>
#include <string.h>

#define MAX 100000

void sort(int l, int r, char str[]) {
	int mid = (l + r) / 2;
#ifdef DEBUG
	printf("original str: %s\nl: %d, r: %d, mid: %d\n", str + l * 3, l, r, mid);
#endif
	if(r - l > 1) {
		sort(l, mid, str);
		sort(mid, r, str);
	}
	int lenL = mid - l, lenR = r - mid;
	char al[MAX] = "", ar[MAX] = "", cmp1[3] = "", cmp2[3] = "";
	strncpy(al, str + l * 3, lenL * 3);
	strncpy(ar, str + mid * 3, lenR * 3);
	int pl = 0, pr = 0, p = l;
	strncpy(cmp1, al, 3);
	strncpy(cmp2, ar, 3);
	while(pl < lenL && pr < lenR) {
		if(strcmp(cmp1, cmp2) < 0) {
			strncpy(str + p * 3, cmp1, 3);
			p++;
			pl++;
			strncpy(cmp1, al + pl * 3, 3);
		}
		else {
			strncpy(str + p * 3, cmp2, 3);
			p++;
			pr++;
			strncpy(cmp2, ar + pr * 3, 3);
		}
	}
	while(pl < lenL) {
		strncpy(str + p * 3, al + pl * 3, 3);
		pl++;
		p++;
	}
	while(pr < lenR) {
		strncpy(str + p * 3, ar + pr * 3, 3);
		pr++;
		p++;
	}
#ifdef DEBUG
	printf("al: %s ar: %s\nstr: %s\n", al, ar, str);
#endif
}

int main() {
	char mainstring[MAX], previousstring[MAX], inputstring[MAX];
	scanf("%s", previousstring);
	sort(0, strlen(previousstring) / 3, previousstring);
#ifdef DEBUG
	printf("previous: %s\n", previousstring);
#endif
	while(scanf("%s", inputstring) != EOF) {
		sort(0, strlen(inputstring) / 3, inputstring);
#ifdef DEBUG
		printf("input: %s\n", inputstring);
#endif
		int m = strlen(previousstring) / 3, n = strlen(inputstring) / 3;
		int i = 0, j = 0, k = 0;
		char cmp1[3], cmp2[3];
		strncpy(cmp1, previousstring, 3);
		strncpy(cmp2, inputstring, 3);
		while(i < m && j < n) {
			if(strcmp(cmp1, cmp2) < 0) {
				strncpy(mainstring + k * 3, cmp1, 3);
				i++;
				strncpy(cmp1, previousstring + i * 3, 3);
			}
			else {
				strncpy(mainstring + k * 3, cmp2, 3);
				j++;
				strncpy(cmp2, inputstring + j * 3, 3);
			}
			k++;
		}
		if(i < m) {
			strcpy(mainstring + k * 3, previousstring + i * 3);
		}
		else {
			strcpy(mainstring + k * 3, inputstring + j * 3);
		}
		printf("%s\n", mainstring);
		strcpy(previousstring, mainstring);
	}
}
