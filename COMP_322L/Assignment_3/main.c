#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
/**
 * stuct process:
 *  Dynamically Allocated 2D Array
 */
struct process {
  int **allocated;
  int **maximum;
  int **required;
} *P = NULL;
/**
 * stuct resource:
 *  Dynamically Allocated Array
 */
struct resource {
  int *available;
} *R = NULL;
typedef struct node process;
typedef struct node resource;
/**
 *  A mutex has two possible states:
 *    - unlocked (not owned by any thread)
 *    - locked (owned by one thread)
 *  A mutex can never be owned by two different threads simultaneously.
 *  A thread attempting to lock that is already locked is suspended until the owning thread unlocks.
 */
pthread_mutex_t denied;
pthread_cond_t condition;
int n, m, thread = 0;
int *safe;
/**
 *  Garbage Collection
 */
void collection() {
  if (P!=NULL)
    free((void *)P);
  if (R != NULL)
    free((void*)R);
}
/**
 *  Print Dynamically Allocated 2D Array
 */
void printmat(const char* str, int** arr) {
  int i, j;
  printf("\n%s:", str);
  printf("\n\t\b\b");
  for (int i = 0; i < m; i++)
    printf("%3c", i + 'A');
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      j == 0 ? printf("P[%d]:%*s%d", i + 1, 3, "", arr[i][j]) : printf("%*d", 3, arr[i][j]);
    printf("\n");
  }
  printf("\n");
}
/**
 * Print Dynamically Allocated Array
 */
void printarr(const char* str, int *arr) {
  int i, j;
  printf("%s:\n", str);
  for (int i = 0; i < m; i++)
    printf("%*c", 3, i+'A');
  printf("\n");
  for (int i = 0; i < m; i++)
    printf("%*d", 3, arr[i]);
  printf("\n\n");
}
/**
 * Initialized Allocated Dynamic Memory with System Info.
 *    - total system resources
 *    - available system resources
 *    - currently allocated resources
 *    - maximum resources
 *    - required resources
 */
void init(struct process *P, struct resource *R, FILE *system) {
  const char *str = "resources";
  int i, j;
  /**
   *  If Available[i] = k,
   *  then k instances of resource Rᵢ are available.
   */
  printf("Enter available system resources:\n");
  R->available = (int *)malloc(m * sizeof(R->available));
  for (int i = 0; i < m; i++) {
    if (system == NULL)
        printf("Process[%d] - Resource[%c]: ", i + 1, j + 'A');
    system != NULL ? fscanf(system, "%d", &R->available[i]) : scanf("%d", &R->available[i]);
  }
  str = "Available system resources";
  printarr(str, R->available);
  /**
   *  If allocated[i,j] = k,
   *  then Pᵢ is currently allocated k instances of resource type Rⱼ.
   */
  printf("Enter processes (currently allocated resources):\n");
  P->allocated = (int **)malloc(n * sizeof(*P->allocated));
  for (i = 0; i < n; i++)
    P->allocated[i] = (int *)malloc(n * sizeof(**P->allocated));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (system == NULL)
        printf("Process[%d] - Resource[%c]: ", i + 1, j + 'A');
      system != NULL ? fscanf(system, "%d", &P->allocated[i][j]) : scanf("%d", &P->allocated[i][j]);
    }
  }
  str = "Currently allocated resources";
  printmat(str, P->allocated);
  /**
   *  If maximum[i,j] = k,
   *  then process Pᵢ can request maximum k instances of resource type Rⱼ.
   */
  printf("Enter processes (maximum resources):\n");
  P->maximum = (int **)malloc(n * sizeof(*P->maximum));
  for (i = 0; i < n; i++)
    P->maximum[i] = (int *)malloc(n * sizeof(**P->maximum));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (system == NULL)
        printf("Process[%d] - Resource[%c]: ", i + 1, j + 'A');
      system != NULL ? fscanf(system , "%d", &P->maximum[i][j]) : scanf("%d", &P->maximum[i][j]);
    }
  }
  str = "Maximum resources";
  printmat(str, P->maximum);
  /**
   *  If required[i,j] = k,
   *  then process Pᵢ may need k more instances of resource type Rⱼ to complete the task.
   */
  P->required = (int **)malloc(n * sizeof(*P->required));
  for (i = 0; i < n; i++)
    P->required[i] = (int *)malloc(n * sizeof(**P->required));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      P->required[i][j] = P->maximum[i][j] - P->allocated[i][j];
  }
  str = "Required resources";
  printmat(str, P->required);
}
/**
 * For each request operation, checks request if granted or denied.
 */
bool request(struct process *P, struct resource *R) {
  int tmp[m];
  for (int i = 0; i < m; i++)
    tmp[i] = R->available[i];
  bool found[n];
  for (int i = 0; i < n; i++)
    found[i] = false;
  int k = 0;
  // Algorithm to find the whether request has been granted or denied
  while (k < n) {
    bool granted = false;
    for (int i = 0; i < n; i++) {
      if (!found[i]) {
        bool state = true;
        for (int j = 0; j < m; j++)
          if (P->required[i][j] > tmp[j]) {
            state = false;
            break;
          }
          if (state) {
            for (int j = 0; j < m; j++)
              tmp[j] += P->allocated[i][j];
            safe[k] = i;
            found[i] = true;
            ++k;
            granted = true;
          }
      }
    }
    if (!granted) {
      for (int k = 0; k < n; k++)
        safe[k] = -1;
      return false; // denied
    }
  }
  return true; // granted
}
/**
 * Dynamic deadlock avoidance simulation
 */
void *respond(void *arg) {
  int p = *((int *)arg);
  pthread_mutex_lock(&denied);
  // condition check
  while (p != safe[thread])
    pthread_cond_wait(&condition, &denied);
  // process
  printf("\n--> Process %d", p + 1);
  printf("\n\tAllocated: ");
  for (int i = 0; i < m; i++)
    printf("%3d", P->allocated[p][i]);
  printf("\n\tRequired:  ");
  for (int i = 0; i < m; i++)
    printf("%3d", P->required[p][i]);
  printf("\n\tAvailable: ");
  for (int i = 0; i < m; i++)
    printf("%3d", R->available[i]);
  printf("\nProcessing Pᵢ ...");
  sleep(2);
  printf("\n              ...");
  sleep(1);
  printf("\n              ...");
  sleep(3);
  printf("\nResource Released");
  for (int i = 0; i < m; i++)
    R->available[i] += P->allocated[p][i];
  printf("\n\tAvailable: ");
  for (int i = 0; i < m; i++)
    printf("%3d", R->available[i]);
  printf("\n\n");
  sleep(1);
  thread++;
  pthread_cond_broadcast(&condition);
  pthread_mutex_unlock(&denied);
  pthread_exit(NULL);
}

int main(int argc, char **argv) {
  srand(time(NULL));
  int i, j, k;
  FILE *system = fopen(argv[1], "r");
  if (system != NULL) {
    // if command line used
    fscanf(system, "%d", &n);
    fscanf(system, "%d", &m);
  } else {
    // console user input
    printf("Enter the number of processes in system:\t");
    scanf("%d", &n);
    printf("Enter the number of resource types:\t\t");
    scanf("%d", &m);
  }
  R = (struct resource *)malloc(m * sizeof(struct resource));
  P = (struct process *)malloc(n * sizeof(struct process));
  // initialize dynamic allocated arrays with system information
  init(P, R, system);
  fclose(system);
  // check whether the request has been granted or denied
  safe = (int *)malloc(n * sizeof(*safe));
  for (int i = 0; i < n; i++)
    safe[i] = -1;
  if (!request(P, R)) {
    printf("Request has been denied.\n");
    exit(-1);
  }
  printf("Request has been granted.\n");
  printf("Safe Sequence Found: ");
  for (int i = 0; i < n; i++) {
    printf("%-3d", safe[i] + 1);
  }
  printf("\nExecuting Processes...\n");
  sleep(1);
  // pthread to simulate dynamic deadlock avoidance
  pthread_t processes[n];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  int processNumber[n];
  for (int i = 0; i < n; i++)
    processNumber[i] = i;
  for (int i = 0; i < n; i++)
    pthread_create(&processes[i], &attr, respond, (void *)(&processNumber[i]));
  for (int i = 0; i < n; i++)
    pthread_join(processes[i], NULL);
  printf("Executing Processes Complete\n");
  free(safe);
  collection();
  return 0;
}
