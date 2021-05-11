#include <stdio.h>
#include <stdlib.h>
struct node {
  int *pages, *memory;
}*ptr=NULL;
typedef struct node node;

void fifo() {

}
void lru() {}
void optimal() {}

void collection() {
  if (ptr!=NULL)
    free((void*)ptr);
}

int main(int argc, char **argv) {
  int i, n, m, x = 0, f = 0, s = 0, r = 0, count = 0, flag = 0, tmp;
  FILE *sys = fopen(argv[1], "r");
  fscanf(sys, "%d", &n); // page reference size
  fscanf(sys, "%d", &m); // page frame size
  ptr = (struct node *)malloc(n * sizeof(struct node));
  ptr->pages = (int *)malloc(n * sizeof(*ptr->pages));
  ptr->memory = (int *)malloc(m * sizeof(*ptr->memory));
  // page reference string
  for (i=0; i<n; i++)
    fscanf(sys, "%d", &ptr->pages[i]);
  // page frame initial
  for (i=0; i<m; i++)
    ptr->memory[i] = -1;
  // fifo
  while (x < n) {
    flag = 0;
    tmp = ptr->pages[x];
    // check wether the page is already exist
    for (i=0; i<m; i++) {
      if (tmp == ptr->memory[i]) {
        x++;
        flag = 1;
        break;
      }
    }
    // if page is not already exist
    if (flag == 0) {
      if (r < m) {
        ptr->memory[r] = ptr->pages[x];
        r++;s++;count++;
      } else {
        if (f < m) {
          ptr->memory[f] = ptr->pages[x];
          f++;s++;count++;
        } else f = 0;
      }
    }
    //print the page frame
    printf("\n");
    for (i = 0; i < m; i++)
      printf("%*d%*s", 2, ptr->memory[i], 2, "");
  }
  printf("\nPage Faults = %d\n", count);

  collection();
  return 0;
}