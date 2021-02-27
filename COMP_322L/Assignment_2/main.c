#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//  repeat until Rᵢ == 0 for all n processes    /* repeat until all processes have terminated */
//    while no process is active, increment t   /* if no process is ready to run, just advance t */
//    choose active processes pᵢ to run next
//      according to scheduling algorithm       /* Ex: FIFO, SJF, SRT */
//    decrement Rᵢ                              /* pᵢ has accumulated 1 CPU time unit */
//    if Rᵢ == 0                                /* process i has terminated */
//      set active flag of pᵢ = 0               /* process i is excluded from further consideration */
//      TTᵢ = t - Aᵢ                            /* the turnaround time of process i is the time
//                                                 since arrival, TTᵢ, until the current time t */
//  compute the average turnaround time,
//    ATT, by averaging all values TTᵢ
struct process {
  int arrival;
  int service;
};
void fifo() {
  int n, total = 0;
  struct process fifo;
  printf("\nNumber of process: ");
  scanf("%d", &n);


} // fifo schedules processes according to the process arrival time
void sjf() {
  int total = 0;

} // sjf schedules processes according to total CPU time requires
void srt() {
  int total = 0;

} // srt schedules processes according to remaining CPU time needed to complete
void prt(int arr[], int ser[], int n) {
  for (int i = 0; i < n; i++) {
    printf("\n|      %c      |      %*dms    |     %*dms    |", 'A' + i, 2, arr[i], 2, ser[i]);
  }
} // print table of process, arrival time and service time

int main(void) {
  int n,p=0;
  struct process = NULL;
  while (n != 5) {
    printf("\n\n1. FIFO\n2. SJF \n3. SRT \n4. All \n5. Quit\nEnter #: ");
    scanf("%d", &n);
    prinf("No. of process: ");
    scanf("%d", &p);

    switch (n) {
    case 1:
      printf("\nᵢ-----------------------------------------ᵢ"
             "\n|    FIFO (First-In-First-Out) schedule   |"
             "\n|-------------ᵢ-------------ᵢ-------------|"
             "\n|   Process   |   Arrival   |   Service   |"
             "\n|-------------|-------------|-------------|");
      break;
    case 2:
      printf("\nᵢ-----------------------------------------ᵢ"
             "\n|    SJF (Shortest Job First) schedule    |"
             "\n|-------------ᵢ-------------ᵢ-------------|"
             "\n|   Process   |   Arrival   |   Service   |"
             "\n|-------------|-------------|-------------|");
      break;
    case 3:
      printf("\nᵢ-----------------------------------------ᵢ"
             "\n|  SRT (Shortest Remaining Time) schedule |"
             "\n|-------------ᵢ-------------ᵢ-------------|"
             "\n|   Process   |   Arrival   |   Service   |"
             "\n|-------------|-------------|-------------|");
      break;
    case 4:
      printf("\nᵢ-----------------------------------------ᵢ"
             "\n|             FIFO, SJT, SRT              |"
             "\n|-------------ᵢ-------------ᵢ-------------|"
             "\n|   Process   |   Arrival   |   Service   |"
             "\n|-------------|-------------|-------------|");
      break;
    default:
      break;
    }
  }
  return 0;
}
/**
 *    ᵢ-----------------------------------------ᵢ
 *    |    FIFO (First-In-First-Out) schedule   |
 *    |-------------ᵢ-------------ᵢ-------------|
 *    |   Process   |   Arrival   |   Service   |
 *    |-------------|-------------|-------------|
 *    |      A      |      0ms    |     18ms    |
 *    |-------------|-------------|-------------|
 *    |      B      |      2ms    |      7ms    |
 *    |-------------|-------------|-------------|
 *    |      C      |      2ms    |     10ms    |
 *    |-------------ᵢ-------------ᵢ-------------|
 *    |                   FIFO                  |
 *    |      Total turnaround time:     74ms    |
 *    |    Average turnaround time:  24.66ms    |
 *    ᵢ-----------------------------------------ᵢ
 *
 *    ᵢ-----------------------------------------ᵢ
 *    |    SJF (Shortest Job First) schedule    |
 *    |-------------ᵢ-------------ᵢ-------------|
 *    |   Process   |   Arrival   |   Service   |
 *    |-------------|-------------|-------------|
 *    |      A      |      3ms    |      5ms    |
 *    |-------------|-------------|-------------|
 *    |      B      |      0ms    |      4ms    |
 *    |-------------|-------------|-------------|
 *    |      C      |      4ms    |      2ms    |
 *    |-------------|-------------|-------------|
 *    |      D      |      5ms    |      4ms    |
 *    |-------------ᵢ-------------ᵢ-------------|
 *    |                   SJF                   |
 *    |      Total turnaround time:     23ms    |
 *    |    Average turnaround time:   5.75ms    |
 *    ᵢ-----------------------------------------ᵢ
 *
 *    ᵢ-----------------------------------------ᵢ
 *    |  SRT (Shortest Remaining Time) schedule |
 *    |-------------ᵢ-------------ᵢ-------------|
 *    |   Process   |   Arrival   |   Service   |
 *    |-------------|-------------|-------------|
 *    |      A      |      1ms    |      6ms    |
 *    |-------------|-------------|-------------|
 *    |      B      |      1ms    |      8ms    |
 *    |-------------|-------------|-------------|
 *    |      C      |      2ms    |      7ms    |
 *    |-------------|-------------|-------------|
 *    |      D      |      3ms    |      3ms    |
 *    |-------------ᵢ-------------ᵢ-------------|
 *    |                   SRT                   |
 *    |      Total turnaround time:     51ms    |
 *    |    Average turnaround time:  12.75ms    |
 *    ᵢ-----------------------------------------ᵢ
 *
 *    ᵢ-----------------------------------------ᵢ
 *    |             FIFO, SJT, SRT              |
 *    |-------------ᵢ-------------ᵢ-------------|
 *    |   Process   |   Arrival   |   Service   |
 *    |-------------|-------------|-------------|
 *    |      A      |      3ms    |      5ms    |
 *    |-------------|-------------|-------------|
 *    |      B      |      0ms    |      4ms    |
 *    |-------------|-------------|-------------|
 *    |      C      |      4ms    |      2ms    |
 *    |-------------|-------------|-------------|
 *    |      D      |      5ms    |      4ms    |
 *    |-------------ᵢ-------------ᵢ-------------|
 *    |                   FIFO                  |
 *    |      Total turnaround time:     23ms    |
 *    |    Average turnaround time:   5.75ms    |
 *    ᵢ-----------------------------------------ᵢ
 *    |                   SJF                   |
 *    |      Total turnaround time:     23ms    |
 *    |    Average turnaround time:   5.75ms    |
 *    ᵢ-----------------------------------------ᵢ
 *    |                   SRT                   |
 *    |      Total turnaround time:     23ms    |
 *    |    Average turnaround time:   5.75ms    |
 *    ᵢ-----------------------------------------ᵢ
 *
 */