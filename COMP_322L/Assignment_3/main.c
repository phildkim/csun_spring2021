#include <stdio.h>
#include <stdlib.h>
/**
 * struct node
 *    2D Dynamically Allocated Memory
 *    P: max resources for each process
 *    R: available resources
 *    A: allocated resource
 *    N: P - A
 */
struct node {
  int **P, **R, **A, **N;
} *ptr = NULL;
typedef struct node node;
/**
 * garbage collection
 */
void collection() {
  if (ptr != NULL)
    free((void*)ptr);
}
/**
 * print 2D dynamic array
 */
void print(const char* str, int **arr, int n, int m) {
  int i, j;
  printf("\n%s", str);
  for (i = 0; i < n; i++) {
    printf("\n");
    for (j = 0; j < m; j++)
      printf(" %*d\t", 4, arr[i][j]);
  }
  printf("\n");
}
/**
 * initialize dynamic arrays by either command line or user input.
 *    Example:
 *        $ gcc main.c
 *        $ ./a.out test.txt
 */
void init(struct node *p, FILE *system, int n, int m) {
  int i, j, k;
  p->P = (int **)malloc(n * sizeof(*p->P));//maximum
  p->A = (int **)malloc(n * sizeof(*p->A));//allocated
  p->N = (int **)malloc(n * sizeof(*p->N));//needed
  for (i = 0; i < n; i++) {
    p->P[i] = (int *)malloc(n * sizeof(**p->P));
    p->A[i] = (int *)malloc(n * sizeof(**p->A));
    p->N[i] = (int *)malloc(n * sizeof(**p->N));
  }
  // allocated
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      system != NULL ? fscanf(system, "%d", &p->A[i][j]) : scanf("%d", &p->A[i][j]);
  if (system != NULL) {
    fscanf(system, "%d", &n);
    fscanf(system, "%d", &m);
  }
  // maximum
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      system != NULL ? fscanf(system, "%d", &p->P[i][j]) : scanf("%d", &p->P[i][j]);
  if (system != NULL) {
    fscanf(system, "%d", &k);
    fscanf(system, "%d", &m);
  } else {
    printf("n: ");
    scanf("%d", &k);
    printf("m: ");
    scanf("%d", &m);
  }
  // available resources
  p->R = (int **)malloc(k * sizeof(*p->R));
  for (i = 0; i < m; i++)
    p->R[i] = (int *)malloc(m * sizeof(**p->R));
  for (i = 0; i < m; i++)
    system != NULL ? fscanf(system, "%d", &p->R[0][i]) : scanf("%d", &p->R[0][i]);
  // needed resources
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      p->N[i][j] = p->P[i][j] - p->A[i][j];
}
/**
 *
 */
int respond(struct node* p, int a[], int n, int m) {
  int i, j, k, x = 0;
  int F[n], W[1][n];
  int pflag = 0, flag = 0;
  for (i = 0; i < n; i++)
    F[i] = 0;
  for (i = 0; i < m; i++)
    W[0][i] = p->R[0][i];
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      if (F[i] == 0) {
        flag = 0;
        for (j = 0; j < m; j++) {
          if (p->N[i][j] > W[0][j])
            flag = 1;
        }
        if (flag == 0 && F[i] == 0) {
          for (j = 0; j < m; j++)
            W[0][j] += p->A[i][j];
          F[i] = 1;
          pflag++;
          a[x++] = i;
        }
      }
    }
    if (pflag == n)
      return 1;
  }
  return 0;
}
/**
 *
 */
int banker(struct node* p, int n, int m) {
  int i, j, a[n];
  j = respond(p, a, n, m);
  if (j != 0) {
    printf("\n\n");
    for (i = 0; i < n; i++)
      printf(" P[%d]  ", a[i]);
    printf("\n A safety sequence has been detected.\n");
    return 1;
  } else {
    printf("\n Deadlock has occured.\n");
    return 0;
  }
}
/**
 *
 */
void request(struct node* p, int pid, int n, int m) {
  int req[1][n];
  int i;
  printf("\n Enter additional request :- \n");
  for (i = 0; i < m; i++) {
    printf(" Request for resource %d : ", i + 1);
    scanf("%d", &req[0][i]);
  }
  for (i = 0; i < m; i++) {
    printf("%d ", p->N[pid][i]);
    if (req[0][i] > p->N[pid][i]) {
      printf("\n Error encountered.\n");
      collection();
      exit(0);
    }
  }
  for (i = 0; i < m; i++) {
    printf("%d ", p->R[0][i]);
    if (req[0][i] > p->R[0][i]) {
      printf("\n Resources unavailable.\n");
      collection();
      exit(0);
    }
  }
  for (i = 0; i < m; i++) {
    p->R[0][i] -= req[0][i];
    p->A[pid][i] += req[0][i];
    p->N[pid][i] -= req[0][i];
  }
}


int main(int argc, char **argv) {
  int b, n, m, ch, pid;
  const char *str = "allocated resource";
  const char *str1 = "maximum resource";
  const char *str2 = "needed resource";
  FILE *system = fopen(argv[1], "r");
  if (system != NULL) {
    fscanf(system, "%d", &n);
    fscanf(system, "%d", &m);
    ptr = (node *)malloc(n * sizeof(node));
    init(ptr, system, n, m);
    fclose(system);
  } else {
    printf("number of process:\t"); // 5
    scanf("%d", &n);
    printf("number of resources:\t"); // 3
    scanf("%d", &m);
    ptr = (node *)malloc(n * sizeof(node));
    init(ptr, system, n, m);
  }
  print(str, ptr->A, n, m);
  print(str1, ptr->P, n, m);
  print(str2, ptr->N, n, m);
  b = banker(ptr, n, m);
  if (b != 0) {
      printf("\n1. Request\n2. Exit\nEnter: ");
      scanf("%d", &ch);
      if (ch == 1) {
        printf("\nEnter process number: ");
        scanf("%d", &pid);
        request(ptr, pid - 1, n, m);
        b = banker(ptr, n, m);
        if (b == 0) {
          collection();
          exit(0);
        }
      }
  }
  collection();
  return 0;
}