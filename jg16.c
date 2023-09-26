#include <stdio.h>
#include <stdbool.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	bool flag = 0;
	for(int i = 0; i < n; ++i) {
		if(arr[i] & 1) {
			if(flag)
				printf(" ");
			printf("%d", arr[i]);
			flag = 1;
		}
	}
	printf("\n");
	flag = 0;
	for(int i = 0; i < n; ++i) {
		if(~arr[i] & 1) {
			if(flag)
				printf(" ");
			printf("%d", arr[i]);
			flag = 1;
		}
	}
	printf("\n");
}
