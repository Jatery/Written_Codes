#include <stdio.h>
#include <stdint.h>

uint64_t lowbit(uint64_t x) {
	return x & (-x);
}

void findFriend(int m, int index, int friendlist[][2], uint64_t *friendPicked, uint64_t currentPicked, int *friendCount, int currentCount) {
	if (*friendCount < currentCount) {
		return;
	}
	if (index == m) {
#ifdef DEBUG
		printf("%d\n", currentCount);
		for (int i = 0; i < 64; i++) {
			if (currentPicked & ((uint64_t)1 << i)) {
				printf("%d ", i);
			}
		}
		printf("\n");
#endif
		if (*friendCount > currentCount || *friendPicked == 0 || (lowbit(currentPicked & ~(currentPicked & *friendPicked)) < lowbit(*friendPicked & ~(currentPicked & *friendPicked)))) {
			*friendPicked = currentPicked;
			*friendCount = currentCount;	
		}
		return;
	}
	if (currentPicked & ((uint64_t)1 << friendlist[index][0]) || currentPicked & ((uint64_t)1 << friendlist[index][1])) {
		findFriend(m, index + 1, friendlist, friendPicked, currentPicked, friendCount, currentCount);
	}
	else {
		findFriend(m, index + 1, friendlist, friendPicked, currentPicked | ((uint64_t)1 << friendlist[index][0]), friendCount, currentCount + 1);
		findFriend(m, index + 1, friendlist, friendPicked, currentPicked | ((uint64_t)1 << friendlist[index][1]), friendCount, currentCount + 1);

	}
}

int main () {
	int n, m;
	scanf("%d %d", &n, &m);
	int friendlist[m][2];
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &friendlist[i][0], &friendlist[i][1]);
		if (friendlist[i][0] > friendlist[i][1]) {
			int temp = friendlist[i][0];
			friendlist[i][0] = friendlist[i][1];
			friendlist[i][1] = temp;
		}
	}
	uint64_t friendPicked = (uint64_t)0;
	int friendCount = 100;
	findFriend(m, 0, friendlist, &friendPicked, (uint64_t)0, &friendCount, 0);
#ifdef DEBUG
	for (int i = 0; i < m; ++i) {
		printf("%d %d\n", friendlist[i][0], friendlist[i][1]);
	}
	printf("%d\n", friendCount);
#endif
	for (int i = 0; i < n; i++) {
		if (friendPicked & ((uint64_t)1 << i)) {
			printf("%d\n", i);
		}
	}
}
