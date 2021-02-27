

#include <stdio.h>
#include <limits.h>
/**
 *  repeat until Rᵢ == 0 for all n processes  // repeat until all processes have terminated
 *    while no process is active, increment t // if no process is ready to run, just advance t
 *    choose active processes pᵢ to run next
 *      according to scheduling algorithm     // Ex: FIFO, SJF, SRT
 *    decrement Rᵢ                            // pᵢ has accumulated 1 CPU time unit
 *    if Rᵢ == 0                              // process i has terminated
 *      set active flag of pᵢ = 0             // process i is excluded from further consideration
 *      TTᵢ = t - Aᵢ                          // the turnaround time of process i is the time
 *                                            // since arrival, TTᵢ, until the current time t
 *  compute the average turnaround time,
 *    ATT, by averaging all values TTᵢ
 **/
void fifo() {
  // The FIFO algorithm schedules processes according to the process arrival time.
  int i, n, turnaround_total = 0;
  printf("Enter the number of process: ");
  scanf("%d", &n);
  int arr[n];
  int ser[n];
  int waiting[n];
  waiting[0] = 0;
  for (i = 0; i < n; i++) {
    printf("Process %c arrival time and service time: ", 'A' + i);
    scanf("%d %d", &arr[i], &ser[i]);
  }
  for (i=1;i<n;i++)
    waiting[i]=ser[i-1]+waiting[i-1];
  for (i=0;i<n;i++)
    turnaround_total += (ser[i] + waiting[i]) - arr[i];
  print(arr, ser, n);
  printf("   FIFO turnaround tot time: %dms", turnaround_total);
  printf("\n   FIFO turnaround avg time: %.2fms\n\n", (float)turnaround_total / n);
}
/**
 *  repeat until Rᵢ == 0 for all n processes  // repeat until all processes have terminated
 *    while no process is active, increment t // if no process is ready to run, just advance t
 *    choose active processes pᵢ to run next
 *      according to scheduling algorithm     // Ex: FIFO, SJF, SRT
 *    decrement Rᵢ                            // pᵢ has accumulated 1 CPU time unit
 *    if Rᵢ == 0                              // process i has terminated
 *      set active flag of pᵢ = 0             // process i is excluded from further consideration
 *      TTᵢ = t - Aᵢ                          // the turnaround time of process i is the time
 *                                            // since arrival, TTᵢ, until the current time t
 *  compute the average turnaround time,
 *    ATT, by averaging all values TTᵢ
 **/
void sjf() {
  // The SJF algorithm schedules processes according to total CPU time requirements.
  int i, t, n, r = 0, min, turnaround_total = 0;
  printf("Enter the number of process: ");
  scanf("%d", &n);
  int arr[n * 2 + 1];
  int ser[n * 2 + 1];
  int temp[n * 2 + 1];
  int waiting[n];
  for (i = 0; i < n; i++) {
    printf("Process %c arrival time and service time: ", 'A' + i);
    scanf("%d %d", &arr[i], &ser[i]);
    temp[i] = ser[i];
  }
  ser[n*2] = INT_MAX;
  for (t = 0; r != n; t++) {
    min = n*2;
    for (i = 0; i < n; i++) {
      if (arr[i] <= t && ser[i] < ser[min] && ser[i] > 0)
        min = i;
    }
    ser[min]--;
    if (ser[min] == 0) {
      r++;
      turnaround_total += (t + 1) - arr[min];
    }
  }
  print(arr, ser, n);
  printf("   SJF turnaround tot time: %dms", turnaround_total);
  printf("\n   SJF turnaround avg time: %.2fms\n\n", (float)turnaround_total / n);
}
/**
 *  repeat until Rᵢ == 0 for all n processes  // repeat until all processes have terminated
 *    while no process is active, increment t // if no process is ready to run, just advance t
 *    choose active processes pᵢ to run next
 *      according to scheduling algorithm     // Ex: FIFO, SJF, SRT
 *    decrement Rᵢ                            // pᵢ has accumulated 1 CPU time unit
 *    if Rᵢ == 0                              // process i has terminated
 *      set active flag of pᵢ = 0             // process i is excluded from further consideration
 *      TTᵢ = t - Aᵢ                          // the turnaround time of process i is the time
 *                                            // since arrival, TTᵢ, until the current time t
 *  compute the average turnaround time,
 *    ATT, by averaging all values TTᵢ
 **/
void srt() {
  // The SRT algorithm schedules processes according to remaining CPU time needed to complete
  int i, t, n, r = 0, min, turnaround_total = 0;
  printf("Enter the number of process: ");
  scanf("%d", &n);
  int arr[n * 2 + 1];
  int ser[n * 2 + 1];
  int temp[n * 2 + 1];
  int waiting[n];
  for (i = 0; i < n; i++) {
    printf("Process %c arrival time and service time: ", 'A' + i);
    scanf("%d %d", &arr[i], &ser[i]);
    temp[i] = ser[i];
  }
  ser[n * 2] = INT_MAX;
  for (t = 0; r != n; t++) {
    min = n*2;
    for (i = 0; i < n; i++) {
      if (arr[i] <= t && ser[i] < ser[min] && ser[i] > 0)
          min = i;
    }
    ser[min]--;
    if (ser[min] == 0) {
      r++;
      turnaround_total += (t + 1) - arr[min];
    }
  }
  print(arr, ser, n);
  printf("   SRT turnaround tot time: %dms", turnaround_total);
  printf("\n   SRT turnaround avg time: %.2fms\n\n", (float)turnaround_total / n);
}
/**
 * Print process, waiting time, turnaround time as a table
 **/
void print(int arr[], int ser[], int n) {
  printf(" _________________________________________ \n|   process   |   arrival   |   service   |\n");
  for (int i=0;i<n;i++){
    printf("|-------------|-------------|-------------|\n|      %c      |    %*dms     |    %*dms     |\n", 'A' + i, 2, arr[i], 2, ser[i]);
  }
  printf("-------------------------------------------\n");
}
int main(void) {
  int n;
  while (n != 4) {
    printf("\nBatch scheduling algorithms:\n1. First-In-First-Out (FIFO)\n2. Shortest Job First (SJF)\n3. Shortest Remaining Time (SRT)\n4. Compare FIFO, SJF, SRT\n5. Quit\nEnter algorithm #: ");
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
  return 0;
}
