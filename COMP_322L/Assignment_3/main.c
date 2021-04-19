/**
  *  1. first reads the description of a system from the command line or from a file:
  *      - number of processes
  *      - number of resources
  *      - numbers of units within each resource
  *      - numbers of maximum claims of each process
  *
  *  2. Creates the current representation of the system (the set of arrays).
  *
  *  3. Then enters an interactive session during which the user inputs commands of the form:
  *      - request(i, j, k)
  *      - release(i, j, k)
  *      - i is a process number
  *      - j is a resource number
  *      - k is the number of units of Rⱼ the process Pᵢ is requesting or releasing
  *      - For each request operation, the program responds whether the request has been granted or denied
  *
  *   To run program:
  *   Option (1)              Option (2)
  *     $ gcc main.c          $ gcc main.c
  *     $ ./a.out test0.txt   $ ./a.out
  *
  *   Textfile Format:
  *   3         // # of process
  *   4         // # of resource
  *   1 2 5 1   // allocated p[1]
  *   1 1 3 3   // allocated p[2]
  *   1 2 1 0   // allocated p[3]
  *   3 3 2 2   // maximum p[1]
  *   1 2 3 4   // maximum p[2]
  *   1 3 5 0   // maximum p[3]
  *   3 0 1 2   // available resource
  *
  **/
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
struct node {
  int **allocate;
  int **maximum;
  int **required;
  int *available;
}*ptr=NULL;
typedef struct node node;
pthread_mutex_t deadlock;
pthread_cond_t condition;
int *sequences;
int n, m, t = 0;
bool request() {
  int i, j, k, c = 0;
  int temp[m];
  for (i = 0; i < m; i++)
    temp[i] = ptr->available[i];
  bool finished[n];
  for (i = 0; i < n; i++)
    finished[i] = false;
  while (c < n) {
    bool safe = false;
    for (i = 0; i < n; i++) {
      if (!finished[i]) {
        bool possible = true;
        for (j = 0; j < m; j++)
          if (ptr->required[i][j] > temp[j]) {
            possible = false;
            break;
          }
        if (possible) {
          for (j = 0; j < m; j++)
            temp[j] += ptr->allocate[i][j];
          sequences[c] = i;
          finished[i] = true;
          ++c;
          safe = true;
        }
      }
    }
    if (!safe) {
      for (k = 0; k < n; k++)
        sequences[k] = -1;
      return false; // no safe sequence found
    }
  }
  return true; // safe sequence found
}
void *processCode(void *arg) {
  int i;
  int p = *((int *)arg);
  // lock resources
  pthread_mutex_lock(&deadlock);
  // condition check
  while (p != sequences[t])
    pthread_cond_wait(&condition, &deadlock);
  // process
  printf("\n\n--> Process %d", p + 1);
  printf("\nAllocated Resources:\t");
  for (i = 0; i < m; i++)
    printf("%3d", ptr->allocate[p][i]);
  printf("\nRequired Resources:\t");
  for (i = 0; i < m; i++)
    printf("%3d", ptr->required[p][i]);
  printf("\nAvailable Resources:\t");
  for (i = 0; i < m; i++)
    printf("%3d", ptr->available[i]);
  sleep(rand() % 3 + 2); // process code
  for (i = 0; i < m; i++)
    ptr->available[i] += ptr->allocate[p][i];
  printf("\nNow Available Resources:");
  for (i = 0; i < m; i++)
    printf("%3d", ptr->available[i]);
  sleep(1);
  // condition broadcast
  t++;
  pthread_cond_broadcast(&condition);
  pthread_mutex_unlock(&deadlock);
  pthread_exit(NULL);
}
void print(int **arr, int n, int m) {
  int i, j;
  printf("\n\t\b\b");
  for (int i = 0; i < m; i++)
    printf("%5c", i + 'A');
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      j == 0 ? printf("P[%d]:%*s%d", i + 1, 5, "", arr[i][j]) : printf("%*d", 5, arr[i][j]);
    printf("\n");
  }
  printf("\n");
}
void readfile(char **argv) {
  int i, j;
  FILE *sys = fopen(argv[1], "r");
  fscanf(sys, "%d", &n);
  fscanf(sys, "%d", &m);
  // dynamically allocated memory
  ptr = (struct node *)malloc(n * sizeof(struct node));
  // allocated resources, maximum resources, required resources, sequences
  ptr->allocate = (int **)malloc(n * sizeof(*ptr->allocate));
  ptr->maximum = (int **)malloc(n * sizeof(*ptr->maximum));
  ptr->required = (int **)malloc(n * sizeof(*ptr->required));
  sequences = (int *)malloc(n * sizeof(*sequences));
  for (i = 0; i < n; i++) {
    ptr->allocate[i] = (int *)malloc(n * sizeof(**ptr->allocate));
    ptr->maximum[i] = (int *)malloc(n * sizeof(**ptr->maximum));
    ptr->required[i] = (int *)malloc(n * sizeof(**ptr->required));
    sequences[i] = -1;
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      fscanf(sys, "%d", &ptr->allocate[i][j]);
  printf("\nAllocated Resources:");
  print(ptr->allocate, n, m);

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      fscanf(sys, "%d", &ptr->maximum[i][j]);
  printf("\nMaximum Resources:");
  print(ptr->maximum, n, m);

  ptr->available = (int *)malloc(m * sizeof(*ptr->available));
  for (i = 0; i < m; i++)
    fscanf(sys, "%d", &ptr->available[i]);
  fclose(sys);
  printf("\nCurrently Available Resources:\n");
  for (i = 0; i < m; i++)
    printf("%*d", 4, ptr->available[i]);

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      ptr->required[i][j] = ptr->maximum[i][j] - ptr->allocate[i][j];
  printf("\n\nRequired Resources:");
  print(ptr->required, n, m);
}
void readinput() {
  int i, j;
  printf("\nNumber of processes:\t");
  scanf("%d", &n);
  printf("Number of resources:\t");
  scanf("%d", &m);
  // dynamically allocated memory
  ptr = (struct node *)malloc(n * sizeof(struct node));
  // allocated resources, maximum resources, required resources, sequences
  ptr->allocate = (int **)malloc(n * sizeof(*ptr->allocate));
  ptr->maximum = (int **)malloc(n * sizeof(*ptr->maximum));
  ptr->required = (int **)malloc(n * sizeof(*ptr->required));
  sequences = (int *)malloc(n * sizeof(*sequences));
  for (i = 0; i < n; i++) {
    ptr->allocate[i] = (int *)malloc(n * sizeof(**ptr->allocate));
    ptr->maximum[i] = (int *)malloc(n * sizeof(**ptr->maximum));
    ptr->required[i] = (int *)malloc(n * sizeof(**ptr->required));
    sequences[i] = -1;
  }
  printf("\nAllocated Resources:\n");
  for (i = 0; i < n; i++) {
    printf("P[%d]:\t", i + 1);
    for (j = 0; j < m; j++)
      scanf("%d", &ptr->allocate[i][j]);
  }
  printf("\nAllocated Resources:\n");
  print(ptr->allocate, n, m);
  printf("\nMaximum Resources:\n");
  for (i = 0; i < n; i++) {
    printf("P[%d]:\t", i + 1);
    for (j = 0; j < m; j++)
      scanf("%d", &ptr->maximum[i][j]);
  }
  printf("\nMaximum Resources:\n");
  print(ptr->maximum, n, m);
  // currently available resources
  ptr->available = (int *)malloc(m * sizeof(*ptr->available));
  printf("\nCurrently Available Resources:\n");
  for (i = 0; i < m; i++) {
    printf("R[%c]:\t", i + 'A');
    scanf("%d", &ptr->available[i]);
  }

  printf("\nCurrently Available Resources:\n");
  for (i = 0; i < m; i++)
    printf("%d", ptr->available[i]);

  printf("\nRequired Resources:");
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      ptr->required[i][j] = ptr->maximum[i][j] - ptr->allocate[i][j];
  print(ptr->required, n, m);
}
void collection() {
  if (ptr!=NULL)
    free((void*)ptr);
  free(sequences);
}
int main(int argc, char **argv) {
  srand(time(NULL));
  int i, j;
  argv[1] ? readfile(argv) : readinput();
  // request denied or granted
  if (!request()) {
    printf("\nREQUEST DENIED\n");
    exit(-1);
  }
  printf("Executing Processes\n");
  sleep(1);
  // run threads
  pthread_t processes[n];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  int pid[n];
  for (i = 0; i < n; i++)
    pid[i] = i;
  for (i = 0; i < n; i++)
    pthread_create(&processes[i], &attr, processCode, (void *)(&pid[i]));
  for (i = 0; i < n; i++)
    pthread_join(processes[i], NULL);
  printf("\nAll Processes Complete\n\nREQUEST GRANTED\n\nSafe Sequence:\n");
  for (int i = 0; i < n-1; i++)
    printf("P[%d] -> ", sequences[i] + 1);
  printf("P[%d]", sequences[n-1]);
  printf("\n\n");
  collection();
  return 0;
}