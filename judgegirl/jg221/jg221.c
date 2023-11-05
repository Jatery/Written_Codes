#include <stdio.h>
#include <string.h>

#define MAX 260

void write(char string[MAX], int len, int wordcount, int m) {
	int ptr = 0;
	char output[MAX];
	for(int i = 0; i < wordcount; ++i) {
		sscanf(string + ptr, "%s", output);
		strcpy(output + strlen(output), "\0");	
		printf("%s", output);
		ptr += strlen(output) + 1;
		if(i < wordcount - 1 && wordcount > 1) {
			for(int j = 0; j < (m - len) / (wordcount - 1); ++j)
				printf(" ");
			if(i < (m - len) % (wordcount - 1))
				printf(" ");
		}
		else if(wordcount == 1) {
			for(int j = 0; j < m - len; ++j) {
				printf(" ");
			}
		}
	}
	printf("\n");
}

int main() {
	int m, len = 0, wordcount = 0;
	scanf("%d", &m);
	char string[MAX], input[MAX];
	while(scanf("%s", input) != EOF) {
		if(len + wordcount + strlen(input) > m || strlen(input) >= m) {
			if(wordcount > 0)
				write(string, len, wordcount, m);
			while(strlen(input) >= m) {
				char output[MAX];
				for(int i = 0; i < strlen(input) / m; ++i) {
					strncpy(output, input + m * i, m);
					strcpy(output + m, "\0");
					printf("%s\n", output);
				}
				strncpy(output, input + m * (strlen(input) / m), m);
				strncpy(input, output, m);
			}
			strncpy(string, input, m);
			if(strlen(input) > 0)
				wordcount = 1;
			else
				wordcount = 0;
			len = strlen(input);
			continue;
		}
		strncpy(string + len + wordcount, input, m);
		len += strlen(input);
		wordcount++;
	}	
	write(string, len, wordcount, m);
}
