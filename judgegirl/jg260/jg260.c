#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 128

void merge(char string[MAX], char input[MAX]) {
	for(int i = 0; i < strlen(string); ++i) {
		if(string[i] == input[0]) {
			bool flag = 1;
			for(int j = 1; j + i < strlen(string) && flag; ++j) {
				if(string[j + i] != input[j])
					flag = 0;
			}
			if(flag) {
				strcpy(string + i, input);
				return;
			}
		}
	}
	strcpy(string + strlen(string), input);
}

int main() {
	char string[MAX], input[MAX];
	scanf("%s", string);
	while(scanf("%s", input) != EOF)
		merge(string, input);	
	printf("%s", string);
}
