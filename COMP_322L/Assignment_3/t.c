// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <pthread.h>
// #include <stdbool.h>
// #include <time.h>

// int nResources,
//     nProcesses;
// int *resources;
// int **allocated;
// int **maxRequired;
// int **need;
// int *safeSeq;
// int nProcessRan = 0;

// pthread_mutex_t lockResources;
// pthread_cond_t condition;

// // get safe sequence is there is one else return false
// bool getSafeSeq();
// // process function
// void *processCode(void *);

// int main(int argc, char **argv)
// {
//   srand(time(NULL));

//   printf("\nNumber of processes? ");
//   scanf("%d", &nProcesses);

//   printf("\nNumber of resources? ");
//   scanf("%d", &nResources);

//   resources = (int *)malloc(nResources * sizeof(*resources));
//   printf("\nCurrently Available resources (R1 R2 ...)? ");
//   for (int i = 0; i < nResources; i++)
//     scanf("%d", &resources[i]);

//   allocated = (int **)malloc(nProcesses * sizeof(*allocated));
//   for (int i = 0; i < nProcesses; i++)
//     allocated[i] = (int *)malloc(nResources * sizeof(**allocated));

//   maxRequired = (int **)malloc(nProcesses * sizeof(*maxRequired));
//   for (int i = 0; i < nProcesses; i++)
//     maxRequired[i] = (int *)malloc(nResources * sizeof(**maxRequired));

//   // allocated
//   printf("\n");
//   for (int i = 0; i < nProcesses; i++)
//   {
//     printf("\nResource allocated to process %d (R1 R2 ...)? ", i + 1);
//     for (int j = 0; j < nResources; j++)
//       scanf("%d", &allocated[i][j]);
//   }
//   printf("\n");

//   // maximum required resources
//   for (int i = 0; i < nProcesses; i++)
//   {
//     printf("\nMaximum resource required by process %d (R1 R2 ...)? ", i + 1);
//     for (int j = 0; j < nResources; j++)
//       scanf("%d", &maxRequired[i][j]);
//   }
//   printf("\n");

//   // calculate need matrix
//   need = (int **)malloc(nProcesses * sizeof(*need));
//   for (int i = 0; i < nProcesses; i++)
//     need[i] = (int *)malloc(nResources * sizeof(**need));

//   for (int i = 0; i < nProcesses; i++)
//     for (int j = 0; j < nResources; j++)
//       need[i][j] = maxRequired[i][j] - allocated[i][j];

//   // get safe sequence
//   safeSeq = (int *)malloc(nProcesses * sizeof(*safeSeq));
//   for (int i = 0; i < nProcesses; i++)
//     safeSeq[i] = -1;

//   if (!getSafeSeq())
//   {
//     printf("\nUnsafe State! The processes leads the system to a unsafe state.\n\n");
//     exit(-1);
//   }

//   printf("\n\nSafe Sequence Found : ");
//   for (int i = 0; i < nProcesses; i++)
//   {
//     printf("%-3d", safeSeq[i] + 1);
//   }

//   printf("\nExecuting Processes...\n\n");
//   sleep(1);

//   // run threads
//   pthread_t processes[nProcesses];
//   pthread_attr_t attr;
//   pthread_attr_init(&attr);

//   int processNumber[nProcesses];
//   for (int i = 0; i < nProcesses; i++)
//     processNumber[i] = i;

//   for (int i = 0; i < nProcesses; i++)
//     pthread_create(&processes[i], &attr, processCode, (void *)(&processNumber[i]));

//   for (int i = 0; i < nProcesses; i++)
//     pthread_join(processes[i], NULL);

//   printf("\nAll Processes Finished\n");

//   // free resources
//   free(resources);
//   for (int i = 0; i < nProcesses; i++)
//   {
//     free(allocated[i]);
//     free(maxRequired[i]);
//     free(need[i]);
//   }
//   free(allocated);
//   free(maxRequired);
//   free(need);
//   free(safeSeq);
// }

// bool getSafeSeq()
// {
//   // get safe sequence
//   int tempRes[nResources];
//   for (int i = 0; i < nResources; i++)
//     tempRes[i] = resources[i];

//   bool finished[nProcesses];
//   for (int i = 0; i < nProcesses; i++)
//     finished[i] = false;
//   int nfinished = 0;
//   while (nfinished < nProcesses)
//   {
//     bool safe = false;

//     for (int i = 0; i < nProcesses; i++)
//     {
//       if (!finished[i])
//       {
//         bool possible = true;

//         for (int j = 0; j < nResources; j++)
//           if (need[i][j] > tempRes[j])
//           {
//             possible = false;
//             break;
//           }

//         if (possible)
//         {
//           for (int j = 0; j < nResources; j++)
//             tempRes[j] += allocated[i][j];
//           safeSeq[nfinished] = i;
//           finished[i] = true;
//           ++nfinished;
//           safe = true;
//         }
//       }
//     }

//     if (!safe)
//     {
//       for (int k = 0; k < nProcesses; k++)
//         safeSeq[k] = -1;
//       return false; // no safe sequence found
//     }
//   }
//   return true; // safe sequence found
// }

// // process code
// void *processCode(void *arg)
// {
//   int p = *((int *)arg);

//   // lock resources
//   pthread_mutex_lock(&lockResources);

//   // condition check
//   while (p != safeSeq[nProcessRan])
//     pthread_cond_wait(&condition, &lockResources);

//   // process
//   printf("\n--> Process %d", p + 1);
//   printf("\n\tAllocated : ");
//   for (int i = 0; i < nResources; i++)
//     printf("%3d", allocated[p][i]);

//   printf("\n\tNeeded : ");
//   for (int i = 0; i < nResources; i++)
//     printf("%3d", need[p][i]);

//   printf("\n\tAvailable : ");
//   for (int i = 0; i < nResources; i++)
//     printf("%3d", resources[i]);

//   printf("\n");
//   sleep(1);

//   printf("\tResource Allocated!");
//   printf("\n");
//   sleep(1);
//   printf("\tProcess Code Running...");
//   printf("\n");
//   sleep(rand() % 3 + 2); // process code
//   printf("\tProcess Code Completed...");
//   printf("\n");
//   sleep(1);
//   printf("\tProcess Releasing Resource...");
//   printf("\n");
//   sleep(1);
//   printf("\tResource Released!");

//   for (int i = 0; i < nResources; i++)
//     resources[i] += allocated[p][i];

//   printf("\n\tNow Available : ");
//   for (int i = 0; i < nResources; i++)
//     printf("%3d", resources[i]);
//   printf("\n\n");

//   sleep(1);

//   // condition broadcast
//   nProcessRan++;
//   pthread_cond_broadcast(&condition);
//   pthread_mutex_unlock(&lockResources);
//   pthread_exit(NULL);
// }
// // 3 resources
// // 5 processes
// // Available
// // 6 7 12
// // Max
// // 4 5 6
// // 3 1 2
// // 1 2 2
// // 0 3 1
// // 5 4 7
// // Allocation
// // 0 0 0
// // 0 0 0
// // 0 0 0
// // 0 0 0
// // 0 0 0

#include <stdio.h>

int n, r, need[10][10], // resource need of the form need[NUMBER OF CUSTOMERS][NUMBER OF RESOURCES];

    max[10][10], //

    allocation[10][10], //resource allocation of form int allocation[NUMBER OF CUSTOMERS][NUMBER OF RESOURCES];

    a[10];

int i, j, k, t, temp[10], p = 0, in[10] = {0}, x = 0;

void needed();

void alloc();

void nuavail();

int main(void)
{

  //Create n customer threads for resource request and release

  printf("\nEnter the no. of Customer :");

  scanf("%d", &n);

  printf("\nEnter the no. of resources to be allocated:");

  scanf("%d", &r);

  for (i = 1; i <= n; i++)

  {

    printf("\nEnter the current allocation to customer %d", i);

    //int need[NUMBER OF CUSTOMERS][NUMBER OF RESOURCES];

    printf("\n--------------Current Allocation--------------");

    for (j = 1; j <= r; j++)

    {

      scanf("%d", &allocation[i][j]);
    }
  }

  //To hold the maximum demand of resources for each customer

  for (i = 1; i <= n; i++)

  {

    printf("\n--------------Maximum resource-----------------");

    printf("\nEnter the Max.resource demand for customer %d", i);

    for (j = 1; j <= r; j++)

    {

      scanf("%d", &max[i][j]);
    }
  }

  printf("\n---------available resource ---------------------");

  printf("\nEnter the available resources to be allocated\n");

  //code to allocate available resources for new customer

  for (i = 1; i <= r; i++)

  {

    scanf("%d", &a[i]);
  }

  for (i = 1; i <= n; i++)

  {

    for (j = 1; j <= r; j++)

    {

      need[i][j] = max[i][j] - allocation[i][j];
    }
  }

  needed();

  alloc();

  while (p < n)

  {

    for (i = 1; i <= n; i++)

    {

      t = 0;

      if (in[i] == 0)

      {

        for (j = 1; j <= r; j++)

        {

          if (a[j] >= need[i][j])

            t++;
        }
      }

      if (t == r)

      {

        if (in[i] != 1)

        {

          x++;

          temp[x] = i;

          in[i] = 1;

          printf("\n-------------------Safe state-----------------");

          printf("\nNeed of Process p%d is succesfully satisfied", i);

          printf("\nSysmtem is in Safe state. Customer request can be granted");

          p++;

          //banker will grant a request if it satisfies safe condition

          for (k = 1; k <= n; k++)

          {

            a[k] = a[k] + allocation[i][k];

            allocation[i][k] = 0;
          }

          nuavail();
        }
      }
    }

    //code to check the system for safe or unsafe and to deny request if it is unsafe

    if (p == 0)

    {

      printf("\n--------------unsafe state conditio-------------");

      printf("\nDeadlock condition occurred. All resources allocated");

      printf("\nUnsafe state. Wait untill the resources to be free");

      break;
    }
  }

  if (p == n)

  {

    printf("\n-----------Safe sequence of Processes-------------");

    printf("\n The Safe state sequence is");

    for (i = 1; i <= n; i++)

    {

      printf("\tp%d", temp[i]);
    }
  }
}

void nuavail()

{

  int l, m;

  printf("\n");

  printf("\nNew available resources");

  for (l = 1; l <= r; l++)

  {

    printf("\t%d", a[l]);
  }

  alloc();
}

void needed()

{

  int l, m;

  printf("\nThe Need matrix for the customer");

  printf("\n-------------------------------------------");

  for (l = 1; l <= r; l++)

  {

    printf("\t r%d", l);
  }

  for (l = 1; l <= n; l++)

  {

    printf("\np%d", l);

    for (m = 1; m <= r; m++)

    {

      printf("\t%d", need[l][m]);
    }
  }
}

void alloc()

{

  int l, m;

  printf("\n-------Resource allocation Matrix-------------");

  printf("\nResource Allocation table ");

  printf("\n---------------------------------------------");

  printf("\n");

  for (l = 1; l <= r; l++)

  {

    printf("\t r%d", l);
  }

  for (l = 1; l <= n; l++)

  {

    printf("\n p%d \t", l);

    for (m = 1; m <= r; m++)

    {

      printf("\t %d", allocation[l][m]);
    }
  }
}

int current[5][5], maximum_claim[5][5], available[5];
int allocation[5] = {0, 0, 0, 0, 0};
int maxres[5], running[5], safe = 0;
int counter = 0, i, j, exec, resources, processes, k = 1;

int main(void)
{
  printf("\nEnter number of processes: ");
  scanf("%d", &processes);

  for (i = 0; i < processes; i++)
  {
    running[i] = 1;
    counter++;
  }

  printf("\nEnter number of resources: ");
  scanf("%d", &resources);

  printf("\nEnter Claim Vector:");
  for (i = 0; i < resources; i++)
  {
    scanf("%d", &maxres[i]);
  }

  printf("\nEnter Allocated Resource Table:\n");
  for (i = 0; i < processes; i++)
  {
    for (j = 0; j < resources; j++)
    {
      scanf("%d", &current[i][j]);
    }
  }

  printf("\nEnter Maximum Claim Table:\n");
  for (i = 0; i < processes; i++)
  {
    for (j = 0; j < resources; j++)
    {
      scanf("%d", &maximum_claim[i][j]);
    }
  }

  printf("\nThe Claim Vector is: ");
  for (i = 0; i < resources; i++)
  {
    printf("\t%d", maxres[i]);
  }

  printf("\nThe Allocated Resource Table:\n");
  for (i = 0; i < processes; i++)
  {
    for (j = 0; j < resources; j++)
    {
      printf("\t%d", current[i][j]);
    }
    printf("\n");
  }

  printf("\nThe Maximum Claim Table:\n");
  for (i = 0; i < processes; i++)
  {
    for (j = 0; j < resources; j++)
    {
      printf("\t%d", maximum_claim[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < processes; i++)
  {
    for (j = 0; j < resources; j++)
    {
      allocation[j] += current[i][j];
    }
  }

  printf("\nAllocated resources:");
  for (i = 0; i < resources; i++)
  {
    printf("\t%d", allocation[i]);
  }

  for (i = 0; i < resources; i++)
  {
    available[i] = maxres[i] - allocation[i];
  }

  printf("\nAvailable resources:");
  for (i = 0; i < resources; i++)
  {
    printf("\t%d", available[i]);
  }
  printf("\n");

  while (counter != 0)
  {
    safe = 0;
    for (i = 0; i < processes; i++)
    {
      if (running[i])
      {
        exec = 1;
        for (j = 0; j < resources; j++)
        {
          if (maximum_claim[i][j] - current[i][j] > available[j])
          {
            exec = 0;
            break;
          }
        }
        if (exec)
        {
          printf("\nProcess%d is executing\n", i + 1);
          running[i] = 0;
          counter--;
          safe = 1;

          for (j = 0; j < resources; j++)
          {
            available[j] += current[i][j];
          }
          break;
        }
      }
    }
    if (!safe)
    {
      printf("\nThe processes are in unsafe state.\n");
      break;
    }
    else
    {
      printf("\nThe process is in safe state");
      printf("\nAvailable vector:");

      for (i = 0; i < resources; i++)
      {
        printf("\t%d", available[i]);
      }

      printf("\n");
    }
  }
  return 0;
}
// number of processes
// number of resources
// numbers of units within each resource
// maximum claims of each process

// int R[m]:  number of units of each resource
//            m is the number of resources
// int R[j]:  number of units of resource Rⱼ

// int P[n][m]:   maximum claims
// int P[i][j]:   maximum number of units of resource Rⱼ that process pᵢ requests

// user inputs commands of the form:
//    request(i, j, k) or release(i, j, k)
// i is a process number
// j is a resource number
// k is the number of units of Rⱼ the process Pᵢ is requesting or releasing
// For each request operation, the program responds: granted or denied