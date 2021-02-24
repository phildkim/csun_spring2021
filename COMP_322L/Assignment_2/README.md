# Batch scheduling algorithms

***
```
repeat until Rᵢ == 0 for all n processes    /* repeat until all processes have terminated */
  while no process is active, increment t   /* if no process is ready to run, just advance t */
  choose active processes pᵢ to run next
      according to scheduling algorithm     /* Ex: FIFO, SJF, SRT */
   decrement Rᵢ                             /* pᵢ has accumulated 1 CPU time unit */
   if Rᵢ == 0                               /* process i has terminated */
      set active flag of pᵢ = 0             /* process i is excluded from further consideration */
      TTᵢ = t - Aᵢ                          /* the turnaround time of process i is the time since arrival, TTᵢ, until the current time t */
compute the average turnaround time,
  ATT, by averaging all values TTᵢ
```

***

## FIFO

The FIFO (First-In-First-Out) algorithm, also known as FCFS
(First-Come-First-Served), schedules processes strictly according
to the process arrival time. The earlier the arrival, the higher
the priority. Theoretically, multiple processes could have the
same arrival time, in which case the arbitration rule can pick a
process at random. In practice, all requests are processed
sequentially and thus all processes have different arrival times.

Process | Arrival Time | Service Time
---------|----------|---------
 A | 0 ms | 18 ms
 B | 2 ms | 7 ms
 C | 2 ms | 10 ms

A: 0-18ms
B: 18-25ms
C: 25-35ms

Process | Waiting Time | Turnaround Time
---------|----------|---------
 A | 0 ms | 18 ms
 B | 16 ms | 23 ms
 C | 23 ms | 33 ms

**Total turnaround time:** (18 + 23 + 33) = **74ms**

**Average turnaround time:** (74/3) = **24.66ms**

***

## SJF

The SJF (Shortest Job First) algorithm, also known as SJN
(Shortest Job Next), schedules processes according to the total
CPU time requirements. The shorter the required CPU time, the
higher the priority. If multiple processes have the same CPU time
requirement, then the arbitration rule can select a process based
on the arrival times.

Process | Arrival Time | Service Time
---------|----------|---------
 A | 3 ms | 5 ms
 B | 0 ms | 4 ms
 C | 4 ms | 2 ms
 D | 5 ms | 4 ms

B: 0-4ms
C: 4-6ms
D: 6-10
A: 10-15ms

Process | Waiting Time | Turnaround Time
---------|----------|---------
 A | 7 ms | 12 ms
 B | 0 ms | 4 ms
 C | 0 ms | 2 ms
 D | 1 ms  | 5 ms

Total waiting time: (7 + 0 + 0 + 1) = 8ms
Average waiting time: (8/4) = 2ms

**Total turnaround time:** (12 + 4 + 2 + 5) = 23ms
**Average turnaround time:** (23/4) = 5.75ms

***

## SRT

The SRT (Shortest Remaining Time) algorithm schedules processes
according to the remaining CPU time needed to complete the work.
The shorter the remaining CPU time, the higher the priority. If
multiple processes have the same remaining time requirement, then
the arbitration rule can select a process based on the arrival
times.

Process | Arrival Time | Service Time
---------|----------|---------
 A | 1 ms | 6 ms
 B | 1 ms | 8 ms
 C | 2 ms | 7 ms
 D | 3 ms | 3 ms

A: 1-3ms
D: 3-6ms
A: 6-10
C: 10-17ms
B: 17-25ms

Process | Waiting Time | Turnaround Time
---------|----------|---------
 A | 3 ms | 9 ms
 B | 16 ms | 24 ms
 C | 8 ms | 15 ms
 D | 0 ms  | 3 ms

Total waiting time: (3 + 16 + 8 + 0) = 27ms
Average waiting time: (27/4) = 6.75ms

**Total turnaround time:** (9 + 24 + 15 + 3) = 51ms
**Average turnaround time:** (51/4) = 12.75ms
