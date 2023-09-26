#include <stdio.h>

int main() {
	int year, month, index, days;
	scanf("%d%d%d", &year, &month, &index);
	if(month < 1 || month > 12 || index < 0 || index > 6) {
		printf("invalid\n");
		return 0;
	}
	switch(month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			days = 31;
			break;
		case 4: case 6: case 9: case 11:
			days = 30;
			break;
		case 2:
			if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
				days = 29;
			else
				days = 28;
			break;
	}
	printf(" Su Mo Tu We Th Fr Sa\n");
	printf("=====================\n");
	for(int i = 0; i < index; ++i)
		printf("   ");
	for(int i = 1; i <= days; ++i) {
		printf("%3d", i);
		if((index + i) % 7 == 0)
			printf("\n");
	}
	if((index + days) % 7)
		printf("\n");
	printf("=====================\n");
	return 0;
}
