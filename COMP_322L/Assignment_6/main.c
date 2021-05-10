/**
 * Page Replacement Algorithms:
 *  - Compare the performance of page replacement
 *    algorithms for fixed numbers of frames.
 *  - OPTIMAL
 *  - FIFO
 *  - LRU
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct node {
	int *pages;
  int frames;
  int timer;
} *ptr = NULL;
typedef struct node node;

void init(char **argv) {}
void print(char **argv) {}


void OPTIMAL() {}
void FIFO() {}
void LRU() {}

void collection() {
	if (ptr != NULL)
		free((void*)ptr);
  return;
}

int main(int argc, char **argv) {


  collection();
  return 0;
}
