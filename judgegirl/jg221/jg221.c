#include <stdio.h>
#include <string.h>

#define MAX 260

void write(char string[MAX], int len, int wordcount, int m) {
	int ptr = 0;
	char output[MAX];
	for(int i = 0; i < wordcount; ++i) {
		sscanf(string + ptr, "%s", output);
		printf("%s", output);
		ptr += strlen(output) + 1;
		if(wordcount == 1) {
            for(int j = 0; j < m - len; ++j) {
                printf(" ");
            }
        }
		else if(i < wordcount - 1) {
			for(int j = 0; j < (m - len) / (wordcount - 1); ++j)
				printf(" ");
			if(i < (m - len) % (wordcount - 1))
				printf(" ");
		}
	}
	if(wordcount > 0)
		printf("\n");
}

int main() {
	int m, len = 0, wordcount = 0;
	scanf("%d", &m);
	char string[MAX], input[MAX];
	while(scanf("%s", input) != EOF) {	
		if(strlen(input) == m) {
			write(string, len, wordcount, m);
			printf("%s\n", input);
			wordcount = 0;
			len = 0;
			continue;
		}
		if(len + wordcount + strlen(input) > m) {
			write(string, len, wordcount, m);
			strncpy(string, input, m);
			wordcount = 1;
			len = strlen(input);
			continue;
		}
		strncpy(string + len + wordcount, input, m);
		len += strlen(input);
		wordcount++;
	}	
	write(string, len, wordcount, m);
}
