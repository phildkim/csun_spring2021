# Batch scheduling algorithms

***

```c
/* repeat until all processes have terminated */
repeat until Rᵢ == 0 for all n processes
  /* if no process is ready to run, just advance t */
  while no process is active, increment t
  /* Ex: FIFO, SJF, SRT */
  choose active processes pᵢ to run next
      /* pᵢ has accumulated 1 CPU time unit */
      according to scheduling algorithm
   /* process i has terminated */
   decrement Rᵢ
   if Rᵢ == 0
      /* process i is excluded from further consideration */
      set active flag of pᵢ = 0
      /* the turnaround time of process i is the time since arrival TTᵢ */
      TTᵢ = t - Aᵢ
/* until the current time t */
compute the average turnaround time,
  ATT, by averaging all values TTᵢ
```

***

## FIFO

The FIFO (First-In-First-Out) algorithm, also known as FCFS (First-Come-First-Served), schedules processes strictly according to the process arrival time. The earlier the arrival, the higher the priority. Theoretically, multiple processes could have the same arrival time, in which case the arbitration rule can pick a process at random. In practice, all requests are processed sequentially and thus all processes have different arrival times.

***

1. Completion Time: Time at which process completes its execution.
2. Turn Around Time: Time Difference between completion time and arrival time.
   * Turn Around Time = Completion Time – Arrival Time
3. Waiting Time(W.T): Time Difference between turn around time and burst time.
4. Waiting Time = Turn Around Time – Burst Time
5. Service time means amount of time after which a process can start execution.
6. It is summation of burst time of previous processes (Processes that came before)

***

```c
int n,i;

for (i=0; i<n; i++) {
  wt[i] = bt[i] – at[i];
}

```

Process | Arrival Time | Service Time | Turnaround Time
---------|----------|---------|---------
 A | 0 ms | 18 ms | 18 ms
 B | 2 ms | 7 ms | 23 ms
 C | 2 ms | 10 ms | 33 ms

**Total turnaround time:** (18 + 23 + 33) = **74ms**

**Average turnaround time:** (74/3) = **24.66ms**

***

Process | Arrival Time | Service Time | Turnaround Time
---------|----------|---------|---------
 A | 0 ms | 3 ms | 3 ms
 B | 2 ms | 6 ms | 7 ms
 C | 4 ms | 4 ms | 9 ms
 D | 6 ms | 5 ms | 12 ms
 E | 8 ms | 2 ms | 12 ms

**Total turnaround time:** (3+7+9+12+12) = **43ms**

**Average turnaround time:** (43/5) = **8.6ms**

***

## SJF (non-preemptive)

The SJF (Shortest Job First) algorithm, also known as SJN
(Shortest Job Next), schedules processes according to the total
CPU time requirements. The shorter the required CPU time, the
higher the priority. If multiple processes have the same CPU time
requirement, then the arbitration rule can select a process based
on the arrival times.

**Non-preemptive**: Once selected for execution , a process continues to run until the end of its CPU burst .It is also known as Shortest Job First (SJF).

1. Sort all the process according to the arrival time.
2. Then select that process which has minimum arrival time and minimum Burst time.
3. After completion of process make a pool of process which after till the completion of previous process and select that process among the pool which is having minimum Burst time.

* Completion Time: Time at which process completes its execution.
* Turn Around Time: Time Difference between completion time and arrival time.
  * Turn Around Time = Completion Time – Arrival Time
* Waiting Time(W.T): Time Difference between turn around time and burst time.
  * Waiting Time = Turn Around Time – Burst Time

Process | Arrival Time | Service Time | Turnaround Time
---------|----------|---------|---------
 A | 3 ms | 2 ms | 2 ms
 B | 6 ms | 3 ms | 5 ms
 C | 4 ms | 4 ms | 6 ms

**Total turnaround time:** (2+5+6) = 13

**Average turnaround time:** (13/3) = 4.33ms

***

## SRT (preemptive)

The SRT (Shortest Remaining Time) algorithm schedules processes according to the remaining CPU time needed to complete the work. The shorter the remaining CPU time, the higher the priority. If multiple processes have the same remaining time requirement, then the arbitration rule can select a process based on the arrival
times.

**Preemptive**: The process which is currently in execution , runs until it complete or a new process is added in the cpu Scheduler that requires smaller amount of time for execution. It is also known as shortest remaining time first(SRTF).

***

Process | Arrival Time | Service Time | Turnaround Time
---------|----------|---------|---------
 A | 2 ms | 3 ms | 4 ms
 B | 0 ms | 4 ms | 2 ms
 C | 4 ms | 2 ms | 7 ms
 D | 5 ms | 4 ms | 8 ms

**Total turnaround time:** (4+2+7+8) = 21.00 ms

**Average turnaround time:** (21/4) = 5.25 ms
