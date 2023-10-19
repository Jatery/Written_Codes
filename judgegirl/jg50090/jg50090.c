#include <stdio.h>
//#include "count.h"
 
#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512

#include <stdio.h>

void count(int **p[]) {
	int cnt[512] = {0};
	int index = 0;
	int *num[512];
	int i = 0, flag;
	while(p[i] != NULL) {
		flag = 0;
		for(int j = 0; j < index && flag == 0; ++j) {
			if(*p[i] == num[j]) {
				cnt[j]++;
				flag = 1;
			}
		}
		if(!flag) {
			num[index] = *p[i];
			cnt[index] = 1;
			index++;
		}
		i++;
	}
	/* bubble sort */
	for(i = index - 1; i > 0; --i) {
		for(int j = 0; j < i; ++j) {
			if(cnt[j] > cnt[j+1] || (cnt[j] == cnt[j+1] && *num[j] > *num[j+1])) {
				cnt[j] += cnt[j+1];
				cnt[j+1] = cnt[j] - cnt[j+1];
				cnt[j] -= cnt[j+1];
				int *tmp = num[j];
				num[j] = num[j+1];
				num[j+1] = tmp;
			}
		}
	}
	for(i = 0; i < index; ++i) {
		printf("%d %d\n", *num[i], cnt[i]);
	}
}
 
int main(){
  int **ptrArray[MAX_SIZE_PTRARRAY] = {};
  int  *intPtr[MAX_NUM_PTR];
  int   intVar[MAX_NUM_INTVAR];
 
  intVar[0] = 7;
  intVar[1] = 6;
  intVar[2] = 2;
  intVar[3] = 9;
  ptrArray[0] = &intPtr[0];
  ptrArray[1] = &intPtr[1];
  ptrArray[2] = &intPtr[2];
  ptrArray[3] = &intPtr[3];
  ptrArray[4] = NULL;
  intPtr[0] = &intVar[0];
  intPtr[1] = &intVar[1];
  intPtr[2] = &intVar[2];
  intPtr[3] = &intVar[3];
 
  count(ptrArray);
 
  return 0;
}
