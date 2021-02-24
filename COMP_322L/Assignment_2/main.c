#include <stdio.h>
#include <stdlib.h>
/**
 * 3 Scheduling Algorithms:
 *  - FIFO
 *  - SJF (non-preemptive)
 *  - SRT (preemptive)
 *  - Compute turnaround times
 *  - Compute average turnaround time
 */
struct node {
  int data;
  struct node *next;
}*nodeptr=NULL;
typedef struct node node;
/**
 * Garbage collection
 */
void collection() {
  if (nodeptr != NULL)
    free((void *)nodeptr);
}
void FIFO() {

  printf("----------------------------------------------\n"
         "| Process      |  A  |  B  |  C  |  D  |  E  |\n"
         "|--------------|-----|-----|-----|-----|-----|\n"
         "| Arrival Time |  0  |  2  |  4  |  6  |  8  |\n"
         "|--------------|-----|-----|-----|-----|-----|\n"
         "| Service Time |  3  |  6  |  4  |  5  |  2  |\n"
         "---------------------------------------------\n"
         "\nFIFO Turnaround Time: "
         "\nFIFO Average Turnaround Time: ");
}
void SJF() {

  printf("----------------------------------------------\n"
         "| Process      |  A  |  B  |  C  |  D  |  E  |\n"
         "|--------------|-----|-----|-----|-----|-----|\n"
         "| Arrival Time |  0  |  2  |  4  |  6  |  8  |\n"
         "|--------------|-----|-----|-----|-----|-----|\n"
         "| Service Time |  3  |  6  |  4  |  5  |  2  |\n"
         "---------------------------------------------\n"
         "\nSJF Turnaround Time: "
         "\nSJF Average Turnaround Time: ");
}
void SRT() {

  printf("----------------------------------------------\n"
         "| Process      |  A  |  B  |  C  |  D  |  E  |\n"
         "|--------------|-----|-----|-----|-----|-----|\n"
         "| Arrival Time |  0  |  2  |  4  |  6  |  8  |\n"
         "|--------------|-----|-----|-----|-----|-----|\n"
         "| Service Time |  3  |  6  |  4  |  5  |  2  |\n"
         "---------------------------------------------\n"
         "\nSRT Turnaround Time:"
         "\nSRT Average Turnaround Time: ");
}
int main(void) {
  int n;
  while(n!=4) {
    printf("\n\nScheduling Algorithms\n"
           "------------------------\n"
           "1. FIFO\n"
           "2. SJF (non-preemptive)\n"
           "3. SRT (preemptive)\n"
           "4. Quit\n\n"
           "Enter #: ");
    scanf("%d", &n);
    switch (n) {
    case 1:
      FIFO();
      break;
    case 2:
      SJF();
      break;
    case 3:
      SRT();
      break;
    default:
      break;
    }
  }
  collection();
  return 0;
}