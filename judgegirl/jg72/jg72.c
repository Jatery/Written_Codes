#include <stdio.h>

void fill_array(int *ptr[], int n) {
	for(int i = 0; ptr[0] + i <= ptr[n-1]; ++i)
		*(ptr[0] + i) = 0;

	for(int i = 0; i < n; ++i) {
		*ptr[i] = -1;
	}
	for(int i = 1; i < n - 1; ++i) {
		int j = 1;
		while(*(ptr[i] + j) >= 0) {
			*(ptr[i] + j) += i;
			j++;
		}	
	}

	for(int i = 1; i < n; ++i) {
		int j = 1;
		while(*(ptr[i] - j) >= 0) {
			*(ptr[i] - j) += i;
			j++;
		}
	}

	for(int i = 0; i < n; ++i) {
		*ptr[i] = i;
	}
}

int main() {
    int arr[100] = {};
    int *ptr[100];
    int n = 6, m = 0;
    int A[100] = {0, 5, 6, 9, 3, 12};
    for (int i = 0; i < n; i++) {
        ptr[i] = &arr[A[i]];
        if (A[i] > m)    m = A[i];
    }
    fill_array(ptr, n);
    for (int i = 0; i <= m; i++)
        printf("%d%c", arr[i], " \n"[i==m]);
    return 0;
}


