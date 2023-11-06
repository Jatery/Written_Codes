#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check(char input[500], int index) {
	char notice[4][10] = {"if", "case", "while", "for"};
	for(int i = 0; i < 4; ++i) {
		bool flag = 1;
		for(int j = 0; j + index < strlen(input) && j < strlen(notice[i]) && flag; ++j)
			if(input[j + index] != notice[i][j])
				flag = 0;
		if(flag) {
			if(strlen(notice[i]) + index == strlen(input) || input[strlen(notice[i]) + index] == '(')
				return 1;
		}
	}
	return 0;
}

int main() {
	char input[500];
	int cyclomatic = 0;
	while(scanf("%s", input) != EOF) {
		for(int i = 0; i < strlen(input); ++i) {
			if(input[i] == '?')
				cyclomatic++;
			else if(i == 0 || (i > 0 && input[i - 1] == ')'))
				if(check(input, i)) {
					cyclomatic++;
#ifdef DEBUG
					printf("%s\n", input);
#endif
				}
		}
	}
	printf("%d\n", cyclomatic);
}
