#include <stdio.h>
#include <stdbool.h>

struct players {
	char name[64];
	int card[65536][2];
	int check[514];
};

bool bingo(int check[514], int m) {
	for(int i = 0; i < m; ++i) 
		if(check[i] == 0 || check[256 + i] == 0)
			return 1;
	if(check[512] == 0 || check[513] == 0)
		return 1;
	return 0;
}

int main() {
	int n, m, inpt;
	scanf("%d%d", &n, &m);
	struct players lst[n];
	for(int i = 0; i < n; ++i) {
		scanf("%s", lst[i].name);
		for(int j = 0; j < m; ++j)
			for(int k = 0; k < m; ++k) {
				scanf("%d", &inpt);
				lst[i].card[inpt][0] = j;
				lst[i].card[inpt][1] = k;
			}
		for(int j = 0; j < m; ++j) {
			lst[i].check[j] = m;
		   	lst[i].check[256 + j] = m;
			lst[i].check[512] = m;
			lst[i].check[513] = m;	
		}
	}
	bool end_game = 0;
	int cnt = 0;
	while(!end_game && scanf("%d", &inpt) != EOF) {
		cnt++;
		for(int i = 0; i < n; ++i) {
			lst[i].check[lst[i].card[inpt][0]]--;
			lst[i].check[256 + lst[i].card[inpt][1]]--;
			if(lst[i].card[inpt][0] == lst[i].card[inpt][1])
				lst[i].check[512]--;
			if(lst[i].card[inpt][0] + lst[i].card[inpt][1] == m - 1)
				lst[i].check[513]--;
		}
		if(cnt >= m) {
			for(int i = 0; i < n; ++i) {
				if(bingo(lst[i].check, m)) {
					if(!end_game) {
						printf("%d", inpt);
						end_game = 1;
					}
					printf(" %s", lst[i].name);
				}
			}
		}
	}
	printf("\n");
}
