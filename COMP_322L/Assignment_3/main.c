#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
struct node {
  int **allocated;
  int **maximum;
  int **required;
  int *available;
} *ptr = NULL;
typedef struct node node;
pthread_mutex_t locked;
pthread_cond_t condition;
const char *str = "Enter the ";
int *state_safe;
int n, m, t = 0;

void collection() {
  if (ptr != NULL)
    free((void*)ptr);
}

void print(int** arr) {
  int i, j;
  printf("\n\t\b\b");
  for (int i = 0; i < m; i++)
    printf("%4c", i + 'A');
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      j == 0 ? printf("P[%d]:%*s%d", i + 1, 4, "", arr[i][j]) : printf("%*d", 4, arr[i][j]);
    printf("\n");
  }
  printf("\n");
}

void process_desc(const char *str, FILE *sys, int **arr) {
  int i, j;
  printf("%s\n", str);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (sys == NULL) {
        printf("P[%d] - Resource[%c]: ", i + 1, j + 'A');
        scanf("%d", &arr[i][j]);
      } else {
        fscanf(sys, "%d", &arr[i][j]);
      }
    }
  }
}

void resource_desc(const char *str, FILE *sys, int *arr) {
  int i, j;
  printf("%s\n", str);
  for (int i = 0; i < m; i++) {
    if (sys == NULL) {
      printf("Resource[%c]: ", i + 'A');
      scanf("%d", &arr[i]);
    } else {
      fscanf(sys, "%d", &arr[i]);
    }
  }
}

void *request(void *arg) {
  int p = *((int *)arg);
  pthread_mutex_lock(&locked);
  while (p != state_safe[t])
    pthread_cond_wait(&condition, &locked);
  printf("\n\nProcess[%d]", p + 1);
  printf("\nAllocated resources: ");
  for (int i = 0; i < m; i++)
    printf("%3d", ptr->allocated[p][i]);
  printf("\nRequired resources:  ");
  for (int i = 0; i < m; i++)
    printf("%3d", ptr->required[p][i]);
  printf("\nProcess resouces Rᵢ");
  sleep(2);
  printf("\n....");
  sleep(2);
  printf("\n....");
  sleep(2);
  printf("\n....");
  printf("\nReleased resources: ");
  for (int i = 0; i < m; i++)
    ptr->available[i] += ptr->allocated[p][i];
  printf("\nAvailable resources: ");
  for (int i = 0; i < m; i++)
    printf("%3d", ptr->available[i]);
  sleep(1);
  t++;
  pthread_cond_broadcast(&condition);
  pthread_mutex_unlock(&locked);
  pthread_exit(NULL);
}

bool banker(struct node *arr) {
  int tmp[m];
  for (int i = 0; i < m; i++)
    tmp[i] = arr->available[i];
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
          if (arr->required[i][j] > tmp[j]) {
            state = false;
            break;
          }
          if (state) {
            for (int j = 0; j < m; j++)
              tmp[j] += arr->allocated[i][j];
            state_safe[k] = i;
            found[i] = true;
            ++k;
            granted = true;
          }
      }
    }
    if (!granted) {
      for (int k = 0; k < n; k++)
        state_safe[k] = -1;
      return false; // denied
    }
  }
  return true; // granted
}

int main(int argc, char **argv) {
  FILE *sys = fopen(argv[1], "r");
  int i, j, k;
  // read system description from command line or console input
  if (sys != NULL) {
    fscanf(sys, "%d", &n);
    fscanf(sys, "%d", &m);
  } else {
    printf("Enter the number of processes in system:\t");
    scanf("%d", &n);
    printf("Enter the number of resource types:\t\t");
    scanf("%d", &m);
  }
  // allocate dynamic memory of struct node
  ptr = (struct node *)malloc(n * sizeof(struct node));
  // initialize available system resources
  ptr->available = (int *)malloc(m * sizeof(ptr->available));
  str = "\nEnter available system resources:";
  resource_desc(str, sys, ptr->available);
  // initialize allocated system resources
  ptr->allocated = (int **)malloc(n * sizeof(*ptr->allocated));
  for (i = 0; i < n; i++)
    ptr->allocated[i] = (int *)malloc(n * sizeof(**ptr->allocated));
  str = "\nEnter allocated system resources:";
  process_desc(str, sys, ptr->allocated);
  // initialize maximum system resources
  ptr->maximum = (int **)malloc(n * sizeof(*ptr->maximum));
  for (i = 0; i < n; i++)
    ptr->maximum[i] = (int *)malloc(n * sizeof(**ptr->maximum));
  str = "\nEnter maximum system resources:";
  process_desc(str, sys, ptr->maximum);
  // initialize required system resources
  ptr->required = (int **)malloc(n * sizeof(*ptr->required));
  for (i = 0; i < n; i++)
    ptr->required[i] = (int *)malloc(n * sizeof(**ptr->required));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      ptr->required[i][j] = ptr->maximum[i][j] - ptr->allocated[i][j];
  }
  // close system file
  fclose(sys);
  // print available system resources
  printf("\nAvailable system resources\n");
  for (int i = 0; i < m; i++)
    printf("%*c", 4, i + 'A');
  printf("\n");
  for (int i = 0; i < m; i++)
    printf("%*s%d", 3, "", ptr->available[i]);
  // print allocated system resources
  printf("\n\nAllocated system resources");
  print(ptr->allocated);
  // print maximum system resources
  printf("Maximum system resources");
  print(ptr->maximum);
  // print required system resources
  printf("Required system resources");
  print(ptr->required);
  // return denied if unsafe
  state_safe = (int *)malloc(n * sizeof(*state_safe));
  for (int i = 0; i < n; i++)
    state_safe[i] = -1;
  if (!banker(ptr)) {
    printf("Request denied\n");
    exit(-1);
  }
  // return granted if safe and sequence processes
  printf("Request granted\n");
  printf("\nSequence processes: ");
  for (int i = 0; i < n; i++)
    printf("%-3d", state_safe[i] + 1);
  // pthread to simulate deadlock avoidance
  printf("\nExecute process");
  sleep(3);
  pthread_t processes[n];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  int pid[n];
  for (int i = 0; i < n; i++)
    pid[i] = i;
  for (int i = 0; i < n; i++)
    pthread_create(&processes[i], &attr, request, (void *)(&pid[i]));
  for (int i = 0; i < n; i++)
    pthread_join(processes[i], NULL);
  printf("\n\nExecuting Processes Complete\n\n");
  // deallocate dynamic memory
  free(state_safe);
  collection();
  return 0;
}
