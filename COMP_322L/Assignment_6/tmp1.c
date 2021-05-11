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
#include <time.h>
#include <unistd.h>
#define N 1000
struct node {
  int *pages;
  int frames;
  int counter;
}*ptr=NULL;
typedef struct node node;

void printMemoryTable(int table[], int frames) {
  for (int i = 0; i < frames; i++)
    (table[i] == -1) ? printf("-- ") : printf("%2d ", table[i]);
  printf(" |");
}

bool exists(int table[], int frames, int pages) {
  for (int i = 0; i < frames; i++)
    if (pages == table[i])
      return true;
  return false;
}

void FIFO(int n) {
  printf("\n---------FIFO ALGORITHM--------\n");
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

bool lru_exists(int table[], int frames, int pages, int used[]) {
  for (int i = 0; i < frames; i++)
    if (pages == table[i]) {
      used[i] = ptr->counter++;
      return true;
    }
  return false;
}

int lru_getpos(int frames, int used[]){
  int mini = 1e9, pos = -1;
  for (int i = 0; i < frames; i++)
    if (mini > used[i]){
      mini = used[i];
      pos = i;
    }
  return pos;
}

void LRU(int n) {
  printf("\n----------LRU ALGORITHM---------\n");
  int pos = 0, cnt2 = 0;
  int memoryTable[N], used[N];
  for (int i = 0; i < N; i++){
    memoryTable[i] = -1;
    used[i] = 0;
  }
  printf("\nFrame table after each request\n---------------------------------\n");
  for (int i = 0; i < n; i++) {
    printf("Table after request %2d | ", ptr->pages[i]);
    if (!lru_exists(memoryTable, ptr->frames, ptr->pages[i], used)) {
      pos = lru_getpos(ptr->frames, used);
      memoryTable[pos] = ptr->pages[i];
      used[pos] = ptr->counter++;
      printMemoryTable(memoryTable, ptr->frames);
      printf(" Page Fault\n");
      cnt2++;
      continue;
    }
    printMemoryTable(memoryTable, ptr->frames);
    printf("\n");
  }
  printf("\nNumber of page faults in LRU: %d\n\n", cnt2);
}

int optimal_getpos(int table[], int frames, int pages[], int curr, int n){
  for (int i = 0; i < frames; i++)
    if (table[i] == -1)
      return i;
  int pos[N] = {0};
  for (int i = 0; i < frames; i++){
    pos[i] = 1e9;
    for (int j = curr + 1; j < n; j++)
      if (pages[j] == table[i]){
        pos[i] = j;
        break;
      }
  }
  int maxi = -1, retPos = -1;
  for (int i = 0; i < frames; i++)
    if (maxi < pos[i]){
      maxi = pos[i];
      retPos = i;
    }
  return retPos;
}

void OPTIMAL(int n) {
  printf("\n----------OPTIMAL ALGORITHM----------\n");
  int pos = 0, cnt3 = 0, memoryTable[N];
  for (int i = 0; i < N; i++)
    memoryTable[i] = -1;
  printf("\nFrame table for optimal page replacement after each request\n");
  printf("---------------------------------\n");
  for (int i = 0; i < n; i++){
    printf("Table after request %2d | ", ptr->pages[i]);
    if (!exists(memoryTable, ptr->frames, ptr->pages[i])){
      pos = optimal_getpos(memoryTable, ptr->frames, ptr->pages, i, n);
      memoryTable[pos] = ptr->pages[i];
      printMemoryTable(memoryTable, ptr->frames);
      printf(" Page Fault\n");
      cnt3++;
      continue;
    }
    printMemoryTable(memoryTable, ptr->frames);
    printf("\n");
  }
  printf("\nNumber of page faults in OPT: %d\n\n", cnt3);
}

int main(int argc, char **argv) {
  srand(time(NULL));
  int i, x = 2, t = 20, r = 10, n = t, k = 0;
  ptr = (struct node *)malloc(N * sizeof(struct node));
  ptr->pages = (int *)malloc(N * sizeof(*ptr->pages));
  while (t--) {
    int random = (rand() % r) + 1;
    ptr->pages[k++] = random;
  }
  printf("--------- Page Reference ----------\n");
  for (i = 0; i < 20; i++)
    printf("%d ", ptr->pages[i]);
  printf("\n");
  while (x) {
    ptr->frames = (x == 2) ? 3 : 4;
    printf("----------For %d frames ----------\n", ptr->frames);
    printf("\n");
    FIFO(n);
    LRU(n);
    OPTIMAL(n);
    x--;
  }
  return 0;
}
