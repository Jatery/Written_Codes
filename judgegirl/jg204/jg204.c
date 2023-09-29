#include <stdio.h>
#include <assert.h>

#define max 102
#define up 1
#define right -1
#define down 2
#define left -2

int code(int pw, int pd, int w, int d) {
	if(pd > d)
		return pw - 1;
	if(pw > w)
		return w + d - pd;
	if(pd == 0)
		return w * 2 + d - pw;
	return w * 2 + d + pd - 1;
}

void run(int *kw, int *kd, int dir) {
	switch(dir) {
		case up:
			(*kd)--;
			break;
		case right:
			(*kw)++;
			break;
		case down:
			(*kd)++;
			break;
		case left:
			(*kw)--;
			break;
	}
}

void change(int arr[max][max], int pw, int pd, int w, int d, int dir) {
	int kw = pw, kd = pd;
	run(&kw, &kd, dir);
	while(kw > 0 && kw <= w && kd > 0 && kd <= d) {
		if(arr[kd][kw] == 1)
			dir = -dir;
		run(&kw, &kd, dir);
	}
	arr[pd][pw] += arr[kd][kw], arr[kd][kw] = arr[pd][pw] - arr[kd][kw], arr[pd][pw] -= arr[kd][kw];
}

void getmirror(int arr[max][max], int w, int d) {
	for(int i = 1; i <= d; ++i)
		for(int j = 1; j <= w; ++j)
			scanf("%d", &arr[i][j]);

	for(int i = 1; i <= w; ++i)
		arr[d + 1][i] = code(i, d + 1, w, d);
	for(int i = d; i > 0; --i)
		arr[i][w + 1] = code(w + 1, i, w, d);
	for(int i = w; i > 0; --i)
		arr[0][i] = code(i, 0, w, d);
	for(int i = 1; i <= d; ++i)
		arr[i][0] = code(0, i, w, d);
}

int main() {
	int w, d;
	scanf("%d%d", &w, &d);

	assert(w + 2 <= max);
	assert(d + 2 <= max);
	int arr[max][max];
	getmirror(arr, w, d);

#ifdef DEBUG
	for(int i = 0; i <= d + 1; ++i) {
		for(int j = 0; j <= w + 1; ++j)
			printf("%3d", arr[i][j]);
		printf("\n");
	}
#endif
	
	for(int i = 1; i <= w; ++i) {
		if(arr[d + 1][i] == code(i, d + 1, w, d))
			change(arr, i, d + 1, w, d, up);
		printf("%d\n", arr[d + 1][i]);
	}
	for(int i = d; i > 0; --i) {
		if(arr[i][w + 1] == code(w + 1, i, w, d))
			change(arr, w + 1, i, w, d, left);
		printf("%d\n", arr[i][w + 1]);
	}
	for(int i = w; i > 0; --i) {
		if(arr[0][i] == code(i, 0, w, d))
			change(arr, i, 0, w, d, down);
		printf("%d\n", arr[0][i]);
	}
	for(int i = 1; i <= d; ++i) {
		if(arr[i][0] == code(0, i, w, d))
			change(arr, 0, i, w, d, right);
		printf("%d\n", arr[i][0]);
	}

#ifdef DEBUG
	for(int i = 0; i <= d + 1; ++i) {
		for(int j = 0; j <= w + 1; ++j)
			printf("%3d", arr[i][j]);
		printf("\n");
	}
#endif
}
