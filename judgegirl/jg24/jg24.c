#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

bool isvowel(char c) {
	char vowel[] = "aeiouAEIOU";
	for(int i = 0; i < 10; ++i)
		if(c == vowel[i])
			return 1;
	return 0;
}

int main() {
	char str[MAX + 3], vowel[] = "aeiouAEIOU";
	fgets(str, MAX + 3, stdin);
	int digits = 0, vowels = 0, consonants = 0;
	for(int i = 0; i < strlen(str); ++i) {
		if(isdigit(str[i]) > 0)
			digits++;
		else if(isalpha(str[i]) > 0)
			isvowel(str[i]) ? vowels++ : consonants++;
	}
	printf("%d %d %d %d\n", digits, vowels + consonants, vowels, consonants);
}
