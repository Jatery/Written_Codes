#include <stdio.h>


void shuffle(int *deck[]) {
	if(deck[0] == NULL)
		return;
	int tmp = 0;
	while(deck[tmp] != NULL)
		tmp++;
	int mid = tmp & 1 ? tmp / 2 + 1: tmp / 2;
	int *f[mid], *b[tmp - mid];
	for(int i = 0; i < mid; ++i)
		f[i] = deck[i];
	for(int i = 0; i < tmp - mid; ++i)
		b[i] = deck[mid + i];
	for(int i = 0; i < tmp; ++i) {
		if(~i & 1) {
			deck[i] = f[i / 2];
		}
		else {
			deck[i] = b[i / 2];
		}
	}
}

void print(int *deck[]) {
	int flag = 0;
	for(int i = 0; deck[i] != NULL; ++i) {
		flag = 1;
		if(i > 0)
			printf(" ");
		printf("%d", *deck[i]);
	}
	if(flag)
		printf("\n");
}

/*
int main()
{
  int card[10000];
  int *deck[10000];
  int index = 0;

  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;
  shuffle(deck);
  print(deck);
  return 0;
}
*/
