#include <stdio.h>
#include <assert.h>

int x(int index, int m) {
	return index / m;
}

int y(int index, int m) {
	return ((index / m) % 2 == 0 ? index % m : m - index % m - 1);
}
 
void snake(const int *ptr_array[100][100], int m) {
	for(int i = m * m - 1; i > 0; --i) {
		for(int j = 0; j < i; ++j) {	
			if(*(ptr_array[x(j, m)][y(j, m)]) > *(ptr_array[x(j+1, m)][y(j+1, m)])) {
				const int *tmp = ptr_array[x(j, m)][y(j, m)];
				ptr_array[x(j, m)][y(j, m)] = ptr_array[x(j+1, m)][y(j+1, m)];
				ptr_array[x(j+1, m)][y(j+1, m)] = tmp;
			}
		}
	}
}
 
int main()
{
  int array[100][100], check[100][100];
  const int *ptr_array[100][100];
  int m;
 
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) {
      ptr_array[i][j] = &(array[i][j]);
      scanf("%d", &(array[i][j]));
      check[i][j] = array[i][j];
    }
 
  snake(ptr_array, m);
 
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      assert(check[i][j] == array[i][j]);
      assert((ptr_array[i][j] >= &array[0][0]) && (ptr_array[i][j] <= &array[99][99]));
      printf("%d ", *(ptr_array[i][j]));
    }
    printf("\n");
  }
 
  return 0;
}
