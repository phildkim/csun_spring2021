#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node {
  int arrival;
  int service;
  int waiting;
} *node_ptr = NULL;
typedef struct node node;
int num_process = 0;
int fifo_total = 0;
int sjf_total = 0;
int srt_total = 0;
void collection() {
  if (node_ptr != NULL)
    free((void*)node_ptr);
}

void fifo() {
  int i;
  printf("\nNumber of process: ");
  scanf("%d", &num_process);
  node_ptr = (node *)(malloc(num_process * sizeof(node)));
  printf("\nEnter arrival and service time\n");
  for (i=0; i<num_process; i++) {
    printf("Process %c arrival and service time: ", 'A' + i);
    scanf("%d %d", &node_ptr[i].arrival, &node_ptr[i].service);
  }
  node_ptr[0].waiting = 0;
  for (i=0; i<num_process; i++)
    node_ptr[i].waiting = node_ptr[i - 1].service + node_ptr[i - 1].waiting;
  for (i=0; i<num_process; i++)
    fifo_total += (node_ptr[i].service + node_ptr[i].waiting) - node_ptr[i].arrival;
  printf("\nᵢ-------------------------------------------ᵢ"
         "\n|     FIFO (First-In-First-Out) Schedule    |"
         "\n|-------------ᵢ--------------ᵢ--------------|"
         "\n|   Process   |    Arrival   |    Service   |");
  for (i=0; i<num_process; i++)
    printf("\n|-------------|--------------|--------------|"
           "\n|      %c      |     %*dms     |     %*dms     |",
           'A' + i, 2, node_ptr[i].arrival, 2, node_ptr[i].service);
  printf("\n|-------------ᵢ--------------ᵢ--------------|"
         "\n|                    FIFO                   |"
         "\n|      Total turnaround time:     %*dms      |"
         "\n|    Average turnaround time:  %*.2fms      |"
         "\nᵢ-------------------------------------------ᵢ",
         2, fifo_total, 2, (float)fifo_total / num_process);
}
void sjf() {

}
void srt() {
  int i,t,r=0,min;
  printf("\nNumber of process: ");
  scanf("%d", &num_process);
  node_ptr = (node *)(malloc(((num_process*2)+1) * sizeof(node)));
  printf("\nEnter arrival and service time\n");
  for (i=0; i<num_process; i++) {
    printf("Process %c arrival and service time: ", 'A' + i);
    scanf("%d %d", &node_ptr[i].arrival, &node_ptr[i].service);
  }
  node_ptr[num_process * 2].service = INT_MAX;
  for (t=0; r!=num_process; t++) {
    min = num_process*2;
    for (i=0; i<num_process; i++) {
      if (node_ptr[i].arrival <= t && node_ptr[i].service < node_ptr[min].service && node_ptr[i].service > 0)
        min = i;
    }
    node_ptr[min].service--;
    if (node_ptr[min].service == 0) {
      r++;
      sjf_total += (t + 1) - node_ptr[min].arrival;
    }
  }
  printf("\nᵢ-------------------------------------------ᵢ"
         "\n|  SRT (Shortest Remaining Time) Schedule   |"
         "\n|-------------ᵢ--------------ᵢ--------------|"
         "\n|   Process   |    Arrival   |    Service   |");
  for (i = 0; i < num_process; i++)
    printf("\n|-------------|--------------|--------------|"
           "\n|      %c      |     %*dms     |     %*dms     |",
           'A' + i, 2, node_ptr[i].arrival, 2, node_ptr[i].service);
  printf("\n|-------------ᵢ--------------ᵢ--------------|"
         "\n|                     SRT                   |"
         "\n|      Total turnaround time:     %*dms      |"
         "\n|    Average turnaround time:   %*.2fms     |"
         "\nᵢ-------------------------------------------ᵢ",
         2, sjf_total, 2, (float)sjf_total / num_process);
}
int main(void) {
  int n;
  while (n != 5) {
    printf("\n\n1. FIFO\n2. SJF \n3. SRT \n4. All \n5. Quit\nEnter #: ");
    scanf("%d", &n);
    switch (n) {
      case 1:
        fifo();
        break;
      case 2:
        sjf();
        break;
      case 3:
        srt();
        break;
      case 4:
        break;
      default:
        break;
    }
  }
  collection();
  return 0;
}