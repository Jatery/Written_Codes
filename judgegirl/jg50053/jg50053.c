#include <stdio.h>
#include <string.h>

#define MAXLENGTH 50
#define MAXM 100

int find(char author[MAXLENGTH], char authorList[MAXM][MAXLENGTH], int N) {
	for(int i = 0; i < N; ++i) {
		if(strcmp(author, authorList[i]) == 0)
			return i;
	}
	return -1;
}

int main() {
	int numBooks, numAuthors = 0, sold[MAXM] = {0};
	char author[MAXM][MAXLENGTH], bookList[MAXM][MAXLENGTH];
	char authorList[MAXM][MAXLENGTH];
	scanf("%d", &numBooks);
	for(int i = 0; i < numBooks; ++i) {
		scanf("%s%s", author[i], bookList[i]);
		if(find(author[i], authorList, numAuthors) == -1) {
			strcpy(authorList[numAuthors], author[i]);
			numAuthors++;
		}
	}
	for(int i = 0; i < numBooks; ++i) {
		char book[MAXLENGTH];
		int k;
		scanf("%s%d", book, &k);
		sold[find(author[find(book, bookList, numBooks)], authorList, numAuthors)] += k;
	}
	int maxsold = 0;
	for(int i = 0; i < numAuthors; ++i) {
		if(sold[i] > sold[maxsold] || (sold[i] == sold[maxsold] && strcmp(authorList[i], authorList[maxsold]) < 0))
			maxsold = i;
	}
	printf("%s %d\n", authorList[maxsold], sold[maxsold]);
}
