#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 1000
int tim = 1;
int numberOfFrames;
int pages[N];

// printing current status of frame memory table
void printMemoryTable(int memoryTable[], int numberOfFrames) {
  for (int i = 0; i < numberOfFrames; i++) {
    if (memoryTable[i] == -1)
      printf("-- ");
    else
      printf("%2d ", memoryTable[i]);
  }
  printf(" |");
}

// checking particular page existance in frame
int exists(int memoryTable[], int numberOfFrames, int page){
  for (int i = 0; i < numberOfFrames; i++)
    if (page == memoryTable[i])
      return 1;
  return 0;
}

// FIFO CODE
void FIFO(int n){
  printf("\n---------FIFO ALGORITHM--------\n");
  int pos = 0, cnt1 = 0, memoryTable[N];
  printf("%d\n", n);
  for (int i = 0; i < N; i++)
    memoryTable[i] = -1;
  for (int i = 0; i < n; i++) {
    printf("Table after request %2d | ", pages[i]);
    if (!exists(memoryTable, numberOfFrames, pages[i])) {
      memoryTable[pos] = pages[i];
      pos = (pos + 1) % numberOfFrames;
      printMemoryTable(memoryTable, numberOfFrames);
      printf(" Page Fault\n");
      cnt1++;
      continue;
    }
    printMemoryTable(memoryTable, numberOfFrames);
    printf("\n");
  }
  printf("\nNumber of page faults in FIFO : %d\n\n", cnt1);
}

// checking particular page existance in frame for LRU
int lru_exists(int memoryTable[], int numberOfFrames, int page, int used[]){
  for (int i = 0; i < numberOfFrames; i++)
    if (page == memoryTable[i]){
      used[i] = tim++;
      return 1;
    }
  return 0;
}

// getting position where page should be placed in LRU
int lru_getpos(int numberOfFrames, int used[]){
  int mini = 1e9, pos = -1;
  for (int i = 0; i < numberOfFrames; i++)
    if (mini > used[i]){
      mini = used[i];
      pos = i;
    }
  return pos;
}

// LRU CODE
void LRU(int n){
  printf("\n----------LRU ALGORITHM---------\n");
  int pos = 0, cnt2 = 0;
  int memoryTable[N], used[N];
  for (int i = 0; i < N; i++){
    memoryTable[i] = -1;
    used[i] = 0;
  }
  printf("\nFrame table after each request\n");
  printf("---------------------------------\n");
  for (int i = 0; i < n; i++){
    printf("Table after request %2d | ", pages[i]);
    if (!lru_exists(memoryTable, numberOfFrames, pages[i], used)){
      pos = lru_getpos(numberOfFrames, used);
      memoryTable[pos] = pages[i];
      used[pos] = tim++;
      printMemoryTable(memoryTable, numberOfFrames);
      printf(" Page Fault\n");
      cnt2++;
      continue;
    }
    printMemoryTable(memoryTable, numberOfFrames);
    printf("\n");
  }
  printf("\nNumber of page faults in LRU : %d\n\n", cnt2);
}

// getting position where page should be placed in OPTIMAL
int optimal_getpos(int memoryTable[], int numberOfFrames, int pages[], int curr, int n){
  for (int i = 0; i < numberOfFrames; i++)
    if (memoryTable[i] == -1)
      return i;
  int pos[N] = {0};
  for (int i = 0; i < numberOfFrames; i++){
    pos[i] = 1e9;
    for (int j = curr + 1; j < n; j++)
      if (pages[j] == memoryTable[i]){
        pos[i] = j;
        break;
      }
  }
  int maxi = -1, retPos = -1;
  for (int i = 0; i < numberOfFrames; i++)
    if (maxi < pos[i]){
      maxi = pos[i];
      retPos = i;
    }
  return retPos;
}

// OPTIMAL CODE
void OPTIMAL(int n){
  printf("\n----------OPTIMAL ALGORITHM----------\n");
  int pos = 0, cnt3 = 0, memoryTable[N];
  for (int i = 0; i < N; i++)
    memoryTable[i] = -1;
  printf("\nFrame table for optimal page replacement after each request\n");
  printf("---------------------------------\n");
  for (int i = 0; i < n; i++){
    printf("Table after request %2d | ", pages[i]);
    if (!exists(memoryTable, numberOfFrames, pages[i])){
      pos = optimal_getpos(memoryTable, numberOfFrames, pages, i, n);
      memoryTable[pos] = pages[i];
      printMemoryTable(memoryTable, numberOfFrames);
      printf(" Page Fault\n");
      cnt3++;
      continue;
    }
    printMemoryTable(memoryTable, numberOfFrames);
    printf("\n");
  }
  printf("\nNumber of page faults in OPT : %d\n\n", cnt3);
}

// main program
int main(){
  int x = 2;
  int k = 0, T = 20;
  int n = T;
  // random number generator
  // you can T value as input variable
  while (T--){
    //between 1 t0 10
    int random_integer = rand() % (10) + 1;
    pages[k++] = random_integer;
  }
  printf("--------- Page Reference ----------\n");
  for (int i = 0; i < 20; i++){
    printf("%d ", pages[i]);
  }
  while (x){
    if (x == 2)
      numberOfFrames = 3;
    else
      numberOfFrames = 4;
    printf("----------For %d frames ----------\n", numberOfFrames);
    printf("\n");
    FIFO(n);
    LRU(n);
    OPTIMAL(n);
    x--;
  }
  return 0;
}
