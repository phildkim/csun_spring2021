/**
 * Page Replacement Algorithms:
 *  - Compare the performance of page replacement
 *    algorithms for fixed numbers of frames.
 *  - OPTIMAL
 *  - FIFO
 *  - LRU
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 1000
struct node {
  int *pages;
  int frames;
}*ptr=NULL;
typedef struct node node;



bool exists(int memoryTable[], int numberOfFrames, int page) {
  for (int i = 0; i < numberOfFrames; i++)
    if (page == memoryTable[i])
      return true;
  return false;
}

void printMemoryTable(int memoryTable[], int numberOfFrames) {
  for (int i = 0; i < numberOfFrames; i++)
    (memoryTable[i] == -1) ? printf("-- ") : printf("%2d ", memoryTable[i]);
  printf(" |");
}


void FIFO(int n) {
  printf("\nFIFO ALGORITHM:\n");
  int pos = 0, cnt1 = 0, memoryTable[N];
  printf("%d\n", n);
  for (int i = 0; i < N; i++)
    memoryTable[i] = -1;
  for (int i = 0; i < n; i++) {
    printf("Table after request %2d | ", ptr->pages[i]);
    if (!exists(memoryTable, ptr->frames, ptr->pages[i])) {
      memoryTable[pos] = ptr->pages[i];
      pos = (pos + 1) % ptr->frames;
      printMemoryTable(memoryTable, ptr->frames);
      printf(" Page Fault\n");
      cnt1++;
      continue;
    } else
      printf("\n");
  }
  printf("\nNumber of page faults in FIFO: %d\n\n", cnt1);
}

void LRU(int n) {
  printf("\nLRU ALGORITHM:\n");

}

void OPTIMAL(int n) {
  printf("\nOPTIMAL ALGORITHM:\n");

}

int main(int argc, char **argv) {
  int i, x = 2, t = 20, r = 10,
      n = t, k = 0;

  ptr = (struct node *)malloc(N * sizeof(struct node));
  ptr->pages = (int *)malloc(N * sizeof(*ptr->pages));
  while (t--) {
    int random = (rand() % r) + 1;
    ptr->pages[k++] = random;
  }
  printf("\nPage Reference:\n");
  for (i = 0; i < 20; i++)
    printf("%d ", ptr->pages[i]);
  printf("\n");
  while (x) {
    ptr->frames = (x == 2) ? 3 : 4;
    printf("Frames %d\n", ptr->frames);
    printf("\n");
    FIFO(n);
    // LRU(n);
    // OPTIMAL(n);
    x--;
  }
  return 0;
}
