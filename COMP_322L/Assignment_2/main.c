#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node {
  int arrival;
  int service;
}*ptr=NULL;
typedef struct node process;
int n;
int fifo_total;
int sjf_total;
int srt_total;
void collection(){
  if (ptr != NULL)
    free((void *)ptr);
}

void fifo() {
  int i,a,s,total=0;
  printf("# of process: ");
  scanf("%d", &n);
  int waiting[n];
  waiting[0]=0;
  ptr=(process*)(malloc(n*sizeof(process)));
  for (i=0; i<n; i++) {
    printf("arrival service: ");
    scanf("%d %d", &a, &s);
    ptr[i].arrival = a;
    ptr[i].service = s;
  }
  for (i=0; i<n; i++)
    waiting[i] = ptr[i-1].service + waiting[i-1];
  for (i=0; i<n; i++) {
    total += (ptr[i].service + waiting[i]) - ptr[i].arrival;
  }
  printf("\nᵢ--------------------------------------------------ᵢ"
         "\n|       FIFO (First-In-First-Out) schedule         |"
         "\n|--------------ᵢ-----------------ᵢ-----------------|"
         "\n|    Process   |     Arrival     |     Service     |"
         "\n|--------------|-----------------|-----------------|");
  for (i=0; i<n; i++) {
    printf("\n|      %c       |      %*dms       |       %*dms      |"
           "\n|--------------ᵢ-----------------ᵢ-----------------|",
           'A' + i, 2, ptr[i].arrival, 2, ptr[i].service);
  }
  printf("\n|                    FIFO                          |"
         "\n|         Total turnaround time:      %*dms         |"
         "\n|       Average turnaround time:   %*.2fms         |"
         "\nᵢ--------------ᵢ-----------------ᵢ-----------------ᵢ\n",
         2, total, 2, (float)total/n);
}
void sjf() {

}
void srt() {

}
void all() {

}
int main(void) {
  int c;
  while (c != 5) {
    printf("\n\n1. FIFO\n2. SJF \n3. SRT \n4. All \n5. Quit\nEnter #: ");
    scanf("%d", &c);
    switch (c) {
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
        all();
      default:
        break;
    }
  }
  collection();
  return 0;
}