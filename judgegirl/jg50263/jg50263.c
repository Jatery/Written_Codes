#include <stdio.h>
#define MAXH 100
#define MAXW 100
#define MAXK 10

void img2col(int h, int w, int k, int imgMatrix[MAXH][MAXW], int colMatrix[MAXK * MAXK][MAXW * MAXH]) {
	for(int i = 0; i < h - k + 1; ++i) {
		for(int j = 0; j < w - k + 1; ++j) {
			for(int l = 0; l < k * k; ++l) {
				colMatrix[l][i * (w - k + 1) + j] = imgMatrix[i + l / k][j + l % k];
			}
		}
	}
}
 
int main() {
    int imgHeight, imgWidth;
    int colHeight, colWidth;
    int windowSize;
    int imgMat[MAXH][MAXW];
    int colMat[MAXK * MAXK][MAXW * MAXH];
 
    scanf("%d%d", &imgHeight, &imgWidth);
    scanf("%d", &windowSize);
 
    colHeight = windowSize * windowSize;
    colWidth = (imgWidth - windowSize + 1) * (imgHeight - windowSize + 1);
 
    for (int i = 0; i < imgHeight; i++) 
        for (int j = 0; j < imgWidth; j++) 
            scanf("%d", &imgMat[i][j]);
 
    img2col(imgHeight, imgWidth, windowSize, imgMat, colMat);
 
    for (int i = 0; i < colHeight; i++) {
        for (int j = 0; j < colWidth; j++) 
            printf("%d ", colMat[i][j]);
        printf("\n");
    }
}
