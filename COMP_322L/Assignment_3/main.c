/**
 * To use command line:
 *    $ gcc main.c
 *    $ ./a.out test.txt
 *
 * Textfile format:
 * 3          // Process
 * 4          // Resource
 * 1 2 5 1    // P[1] allocated resource
 * 1 1 3 3    // P[2] allocated resource
 * 1 2 1 0    // P[3] allocated resource
 * 3          // Process
 * 4          // Resource
 * 3 3 2 2    // P[1] maximum resource
 * 1 2 3 4    // P[2] maximum resource
 * 1 3 5 0    // P[3] maximum resource
 * 1          // Process
 * 4          // Resource
 * 3 0 1 2    // R[1] available resource
 *
 * test0 = denied
 * test1 = P1 -> P3 -> P4 -> P0 -> P2
 * test2 = P1 -> P3 -> P4 -> P0 -> P2
 * test3 = P1 -> P3 -> P2 -> P0 -> P4
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct node {
  int **allocated;
  int **maximum;
  int **required;
  int *available;
} *ptr = NULL;
typedef struct node node;
void init(FILE *s, int **arr, int n, int m) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (s == NULL) {
        printf("P[%d] - Resource[%c]: ", i + 1, j + 'A');
        scanf("%d", &arr[i][j]);
      } else {
        fscanf(s, "%d", &arr[i][j]);
      }
    }
  }
}
void print(int **arr, int n, int m) {
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
void collection() {
  if (ptr != NULL)
    free((void *)ptr);
}
int main(int argc, char **argv) {
  int i, j, k, n, m, t;
  FILE *sys = fopen(argv[1], "r");
  if (!argv[1]) {
    printf("Enter the number of processes in system:\t");
    scanf("%d", &n);
    printf("Enter the number of resource types:\t\t");
    scanf("%d", &m);
    // allocate dynamic memory of struct node
    ptr = (struct node *)malloc(n * sizeof(struct node));
    // available system resources
    ptr->available = (int *)malloc(m * sizeof(ptr->available));
    printf("\nEnter available resources:\n");
    for (i = 0; i < m; i++){
      printf("Resource[%c]: ", i + 'A');
      scanf("%d", &ptr->available[i]);
    }
    // allocated system resources
    printf("\nEnter allocated resources:\n");
    ptr->allocated = (int **)malloc(n * sizeof(*ptr->allocated));
    for (i = 0; i < n; i++)
      ptr->allocated[i] = (int *)malloc(n * sizeof(**ptr->allocated));
    init(sys, ptr->allocated, n, m);
    // maximum system resources
    printf("\nEnter maximum resources:\n");
    ptr->maximum = (int **)malloc(n * sizeof(*ptr->maximum));
    for (i = 0; i < n; i++)
      ptr->maximum[i] = (int *)malloc(n * sizeof(**ptr->maximum));
    init(sys, ptr->maximum, n, m);
  } else {
    fscanf(sys, "%d", &n);
    fscanf(sys, "%d", &m);
    // allocate dynamic memory of struct node
    ptr = (struct node *)malloc(n * sizeof(struct node));
    ptr->allocated = (int **)malloc(n * sizeof(*ptr->allocated));
    for (i = 0; i < n; i++)
      ptr->allocated[i] = (int *)malloc(n * sizeof(**ptr->allocated));
    init(sys, ptr->allocated, n, m);
    fscanf(sys, "%d", &n);
    fscanf(sys, "%d", &m);
    ptr->maximum = (int **)malloc(n * sizeof(*ptr->maximum));
    for (i = 0; i < n; i++)
      ptr->maximum[i] = (int *)malloc(n * sizeof(**ptr->maximum));
    init(sys, ptr->maximum, n, m);
    fscanf(sys, "%d", &t);
    fscanf(sys, "%d", &m);
    ptr->available = (int *)malloc(t * sizeof(ptr->available));
    for (i = 0; i < m; i++)
      fscanf(sys, "%d", &ptr->available[i]);
    fclose(sys);
  }
  // required system resources
  ptr->required = (int **)malloc(n * sizeof(*ptr->required));
  for (i = 0; i < n; i++)
    ptr->required[i] = (int *)malloc(n * sizeof(**ptr->required));
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      ptr->required[i][j] = ptr->maximum[i][j] - ptr->allocated[i][j];
  // print Available, Allocated, Maximum, Required
  printf("\nAvailable System Sources:\n\t");
  for (i = 0; i < m; i++)
    printf("%*d", 3, ptr->available[i]);
  printf("\n");
  printf("\nAllocated System Sources:");
  print(ptr->allocated, n, m);
  printf("Maximum System Sources:");
  print(ptr->maximum, n, m);
  printf("Required System Sources:");
  print(ptr->required, n, m);
  // check request has been granted or denied
  int safeSequence[n], work[m], count = 0;
  bool finish[n];
  for (i = 0; i < n; i++)
    finish[i] = 0;
  for (int i = 0; i < m; i++)
    work[i] = ptr->available[i];
  while (count < n) {
    bool found = false;
    for (int p = 0; p < n; p++) {
      if (finish[p] == 0) {
        for (j = 0; j < m; j++)
          if (ptr->required[p][j] > work[j])
            break;
        if (j == m) {
          for (k = 0; k < m; k++)
            work[k] += ptr->allocated[p][k];
          safeSequence[count++] = p;
          // Mark this p as finished
          finish[p] = 1;
          found = true;
        }
      }
    }
    // If safe sequence not found.
    if (found == false) {
      printf("Request has been denied\n");
      exit(-1);
    }
  }
  printf("Request has been granted\n");
  for (int i = 0; i < n - 1; i++)
    printf("P[%d] -> ", safeSequence[i]);
  printf("P[%d]", safeSequence[n - 1]);
      printf("\n");
  collection();
  return 0;
}
