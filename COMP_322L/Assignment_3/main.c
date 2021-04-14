#include <stdio.h>
#include <stdlib.h>
struct node {
  int R;
  int* P;
} *ptr = NULL;
typedef struct node node;
void collection() {
  if (ptr != NULL)
    free((void*)ptr);
}
void prt(int** arr, int row, int col) {
  int i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }
}
void init() {
  int i, j, n, m;
  printf("\nnumber of process:\t");
  scanf("%d", &n);
  printf("\nnumber of resources:\t");
  scanf("%d", &m);

}
int main(void) {
  init();
  collection();
  return 0;
}
