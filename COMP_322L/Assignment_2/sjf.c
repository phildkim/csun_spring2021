#include <stdio.h>
typedef struct
{
  int pid, at, bt, bt1, ct, tat, wt, f;
} process;
int main()
{
  int n, i, j, st = 0, c, tot = 0;
  float atat = 0, awt = 0;
  printf("enter number of processes >> ");
  scanf("%d", &n);
  process a[n], temp;
  for (i = 0; i < n; i++)
  {
    a[i].pid = i + 1;
    a[i].f = 0;
    printf("enter arrival time : ");
    scanf("%d", &a[i].at);
    printf("enter burst time : ");
    scanf("%d", &a[i].bt);
    a[i].bt1 = a[i].bt;
    printf("--------------------------- ");
  }
  while (1)
  {
    int min = 999, c = n;
    if (tot == n)
      break;
    for (i = 0; i < n; i++)
    {
      if ((a[i].at <= st) && (a[i].f == 0) && (a[i].bt < min))
      {
        min = a[i].bt;
        c = i;
      }
    }
    if (c == n)
      st++;
    else
    {
      a[c].ct = st + 1;
      st = st + 1;
      a[c].bt--;
      if (a[c].bt == 0)
      {
        tot++;
        a[c].f = 1;
        a[c].tat = a[c].ct - a[c].at;
        atat = atat + a[c].tat;
        a[c].wt = a[c].tat - a[c].bt1;
        awt = awt + a[c].wt;
      }
    }
  }
  printf(" average turn around time is %.2f ", (float)(atat / n));
  printf("average waiting time is %.2f", (float)(awt / n));
}
