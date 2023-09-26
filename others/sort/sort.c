#include <stdio.h>

void MergeSort(int l, int r, int arr[]) {
	int mid = (l + r) / 2;
	if(l < r){
		MergeSort(l, mid, arr);
		MergeSort(mid+1, r, arr);
	}
	int lenL = mid - l + 1, lenR = r - mid;
	int al[lenL], ar[lenR];
	for(int i = l, j = 0; j < lenL; ++i, ++j)
		al[j] = arr[i];
	for(int i = mid+1, j = 0; j < lenR; ++i, ++j)
		ar[j] = arr[i];
	int pl = 0, pr = 0, p = l;
	while(pl != lenL && pr != lenR){
		if(al[pl] < ar[pr]){
			arr[p] = al[pl];
			p++, pl++;
		}
		else{
			arr[p] = ar[pr];
			p++, pr++;
		}
	}
	while(pl != lenL){
		arr[p] = al[pl];
		p++, pl++;
	} 
	while(pr != lenR){
		arr[p] = ar[pr];
		p++, pr++; 
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n;i++)
		scanf("%d", &arr[i]);
	MergeSort(0, n, arr);
	for(int i = 0; i < n; ++i) {
		if(i > 0)
			printf(" ");
		printf("%d", arr[i]);
	}
	printf("\n");
}
