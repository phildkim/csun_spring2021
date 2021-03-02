#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct node {
  int at, bt, it, ft, tt, wt, ps;
}*ptr = NULL;
typedef struct node node;
const char *schedule = "  FIFO  SJF  SRT  ";
/* initialize process scheduler */
int init() {
  int i, n;
  /* get no. of process */
  printf("ENTER PROCESSES(?) TOTAL:\t");
  scanf("%d", &n);
  /* allocate dynamic memory of struct node */
  for (i = 0; i < n; i++)
    ptr = (node *)malloc(n * sizeof(node));
  /* store arrival and service time from user input */
  for (i = 0; i < n; i++) {
    printf("\nPROCESS(%c) ARRIVAL TIME:\t", i+'A');
    scanf("%d", &ptr[i].at);
    printf("PROCESS(%c) SERVICE TIME:\t", i+'A');
    scanf("%d", &ptr[i].bt);
    ptr[i].wt = 0;
    ptr[i].ps = i;
  }
  return n;
}
void prt(const char *str, int p[], int t, int n) {
  int i, lt, rt;
  lt = (strlen(str) < 17) ? 10 : 0;
  rt = (strlen(str) < 17) ? -7 : 0;
  printf("\nᵢ---------------------------------------------ᵢ"
         "\n|              %*s%*s              |"
         "\n|--------------ᵢ--------------ᵢ---------------|"
         "\n|    Process   |    Arrival   |    Service    |",
         lt, str, rt, "");
  for (i = 0; i < n; i++)
    printf("\n|--------------|--------------|---------------|"
           "\n|       %c      |     %*d ms    |     %*d ms     |",
           p[i] + 'A', 2, ptr[i].at, 2, ptr[i].bt);
  printf("\n|--------------ᵢ--------------ᵢ---------------|"
         "\n|              %*s%*s              |"
         "\n|       Total turnaround time:     %2d ms      |"
         "\n|     Average turnaround time:  %05.2f ms      |"
         "\nᵢ---------------------------------------------ᵢ",
         lt, str, rt, "", t, (float)t / n);
}
/* fifo process scheduler */
void fifo() {
  char str[18];
  int i, n, total = 0;
  /* initialize fifo process scheduler */
  n = init();
  /* create tmp to store waiting time */
  int tmp[n], pid[n];
  tmp[0] = 0;
  for (i = 1; i < n; i++) {
    pid[i] = ptr[i].ps;
    tmp[i] = tmp[i - 1] + ptr[i - 1].bt;
    /* Time Difference between turn around time and burst time */
    ptr[i].wt = tmp[i] - ptr[i].at;
    /* Waiting Time = Turn Around Time – Burst Time */
    if (ptr[i].wt < 0)
      ptr[i].wt = 0;
  }
  for (i = 0; i < n; i++)
    ptr[i].tt = ptr[i].bt + ptr[i].wt;
  /* Turn Around Time = Completion Time – Arrival Time */
  for (i = 0; i < n; i++)
    total += ptr[i].tt;
  memcpy(str, &schedule[2], 7);
  str[6] = '\0';
  /* print fifo process scheduler */
  prt(str, pid, total, n);
}
/* sjf process scheduler */
void sjf() {
  char str[18];
  struct node job;
  int i, j, n, min, avgtt = 0, avgwt = 0;
  /* initialized sjf process scheduler */
  n = init();
  int pid[n];
  /* Sort all the process according to the arrival time. */
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (ptr[i].at > ptr[j].at) {
        job = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = job;
      }
    }
  }
  min = 0;
  j = 1;
  /* Then select that process which has minimum arrival time and minimum Burst time. */
  while (j < n && ptr[j].at == ptr[0].at) {
    if (ptr[j].bt < ptr[min].bt)
      min = j;
    j++;
  }
  job = ptr[0];
  ptr[0] = ptr[min];
  ptr[min] = job;
  /* After completion of process make a pool of process which after till the completion of previous process and select that process among the pool which is having minimum Burst time. */
  for (i = 1; i < n; i++) {
    min = i;
    j = i + 1;
    while (j < n && ptr[j].at <= ptr[i - 1].ft) {
      if (ptr[j].bt < ptr[min].bt)
        min = j;
      j++;
    }
    job = ptr[i];
    ptr[i] = ptr[min];
    ptr[min] = job;
  }
  for (i = 0; i < n; i++) {
    /* Turn Around Time = Completion Time – Arrival Time */
    ptr[i].tt = ptr[i].ft - ptr[i].at;
    ptr[i].wt = ptr[i].tt - ptr[i].bt;
    avgtt += ptr[i].tt;
    avgwt += ptr[i].wt;
    pid[i] = i;
  }
  memcpy(str, &schedule[8], 4);
  str[4] = '\0';
  /* print sjf process scheduler */
  prt(str, pid, abs(avgtt), n);
}
/* srt process scheduler */
void srt() {
  float tavg = 0.0, wavg = 0.0;
  int n, i, j, k, r = 0, min, tmp;
  char str[18];
  /* initialized sjf process scheduler */
  n = init();
  int procs[n*20], finish[n], pid[n];
  for (i = 0; i < n; i++)
    r += ptr[i].bt;
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        if (ptr[i].at > ptr[j].at) {
          tmp = ptr[i].at;
          ptr[i].at = ptr[j].at;
          ptr[j].at = tmp;
          tmp = ptr[i].bt;
          ptr[i].bt = ptr[j].bt;
          ptr[j].bt = tmp;
        }
      }
    }
  /* runs until it complete or a new process is added in the cpu Scheduler that requires smaller amount of time for execution */
  for (i = 0; i < r; i++) {
    min = 3200;
    for (j = 0; j < n; j++) {
      if ((ptr[j].bt != 0) && (ptr[j].at <= i) && (ptr[j].bt < min)) {
        min = ptr[j].bt;
        k = j;
      }
    }
    ptr[k].bt--;
    procs[i] = k;
  }
  k = 0;
  for (i = 0; i < r; i++) {
    for (j = 0; j < n; j++) {
      if (procs[i] == j) {
        ptr[j].ft = i;
        ptr[j].wt++;
      }
    }
  }
  for (i = 0; i < n; i++) {
    tavg = tavg + ((ptr[i].ft - ptr[i].at) + 1);
    pid[i] = i + 1;
  }
  memcpy(str, &schedule[13], 4);
  str[4] = '\0';
  /* print srt process scheduler */
  prt(str, pid, tavg, n);
}
int main(void) {
  int c, t;
  while (c != 4) {
    printf("\n1. FIFO\n2. SJF \n3. SRT\n4. Quit\nEnter #: ");
    scanf("%d", &c);
    switch (c) {
    case 1:
      /* First-In-First-Out */
      fifo();
      break;
    case 2:
      /* Shortest Job First */
      sjf();
      break;
    case 3:
      /* Shortest Remaining Time */
      srt();
      break;
    default:
      break;
    }
  }
  return 0;
}
