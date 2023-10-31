#include <stdio.h>

int main() {
	char arr[3];
	int i = 0, cnt = 0, flag = 0;
	while(scanf("%c", &arr[i]) != EOF) {
		if(arr[i] == '.') 
			flag = 1;
		else if(arr[i] == ' ' && arr[(i+1) % 3] == '.' && arr[(i+2) % 3] == ' ') {
			cnt++;
			flag = 0;
		}
		else if(arr[i] == '\n' && arr[(i+2) % 3] == '.') {
			cnt++;
			flag = 0;
		}
		else if(arr[i] != '\n' && arr[i] != ' ')
			flag = 0;
		i = (i+1) % 3;
	}
	if(flag == 1)
		cnt++;
	printf("%d\n", cnt);
}
