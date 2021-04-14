#include <stdio.h>
#include <stdlib.h>
struct node {
  int **A;// allocated resource
  int **M;// maximum resource
  int **N;// needed resource
  int **W;// avaibable resource
} *ptr = NULL;
typedef struct node node;

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

void res_request(int **A, int **N, int **AV, int pid, int m) {
  int reqmat[1][10];
  int i;
  printf("\n Enter additional request :- \n");
  for (i = 0; i < m; i++) {
    printf(" Request for resource %d : ", i + 1);
    scanf("%d", &reqmat[0][i]);
  }
  for (i = 0; i < m; i++) {
    printf("%d ", N[pid][i]);
    if (reqmat[0][i] > N[pid][i]) {
      printf("\n Error encountered.\n");
      exit(0);
    }
  }
  for (i = 0; i < m; i++) {
    printf("%d ", AV[0][i]);
    if (reqmat[0][i] > AV[0][i]) {
      printf("\n Resources unavailable.\n");
      exit(0);
    }
  }
  for (i = 0; i < m; i++) {
    AV[0][i] -= reqmat[0][i];
    A[pid][i] += reqmat[0][i];
    N[pid][i] -= reqmat[0][i];
  }
}

int safety(int **A, int **N, int **AV, int n, int m, int a[]) {
  int i, j, k, x = 0;
  int F[10], W[1][10];
  int pflag = 0, flag = 0;
  for (i = 0; i < n; i++)
    F[i] = 0;
  for (i = 0; i < m; i++)
    W[0][i] = AV[0][i];
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      if (F[i] == 0) {
        flag = 0;
        for (j = 0; j < m; j++) {
          if (N[i][j] > W[0][j])
            flag = 1;
        }
        if (flag == 0 && F[i] == 0) {
          for (j = 0; j < m; j++)
            W[0][j] += A[i][j];
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

int banker(int **A, int **N, int **W, int n, int m) {
  int j, i, a[10];
  j = safety(A, N, W, n, m, a);
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

void collection() {
  if (ptr != NULL)
    free((void*)ptr);
}

int main(int argc, char **argv) {
  int i, j, n, m, t, r, pid, ch;
  const char *str1 = "|----------------------|\n| Resource Allocations |\n|----------------------|";
  const char *str2 = "|-----------------------|\n| Resource Maximum Unit |\n|-----------------------|";
  const char *str3 = "|-----------------------|\n| Resource Require Unit |\n|-----------------------|";
  FILE *system = fopen(argv[1], "r");
  if (system == NULL) {
    printf("System Description:\n");
    printf("number of process:\t"); //5
    scanf("%d", &n);
    printf("number of resources:\t"); //3
    scanf("%d", &m);
  } else {
    fscanf(system, "%d", &n);
    fscanf(system, "%d", &m);
    ptr = (node *)malloc(n * sizeof(node));
    ptr->A = (int **)malloc(n * sizeof(*ptr->A));
    for (i = 0; i < n; i++)
      ptr->A[i] = (int *)malloc(n * sizeof(**ptr->A));
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        fscanf(system, "%d", &ptr->A[i][j]);

    fscanf(system, "%d", &n);
    fscanf(system, "%d", &m);
    ptr->M = (int **)malloc(n * sizeof(*ptr->M));
    for (i = 0; i < n; i++)
      ptr->M[i] = (int *)malloc(n * sizeof(**ptr->M));
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        fscanf(system, "%d", &ptr->M[i][j]);

    fscanf(system, "%d", &t);
    fscanf(system, "%d", &m);
    ptr->W = (int **)malloc(t * sizeof(*ptr->W));
    for (i = 0; i < m; i++)
      ptr->W[i] = (int *)malloc(m * sizeof(**ptr->W));
    for (i = 0; i < m; i++)
      fscanf(system, "%d", &ptr->W[0][i]);

    ptr->N = (int **)malloc(n * sizeof(*ptr->N));
    for (i = 0; i < n; i++)
      ptr->N[i] = (int *)malloc(n * sizeof(**ptr->N));
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        ptr->N[i][j] = ptr->M[i][j] - ptr->A[i][j];

    fclose(system);

    print(str1, ptr->A, n, m);
    print(str2, ptr->M, n, m);
    print(str3, ptr->N, n, m);

    r = banker(ptr->A, ptr->N, ptr->W, n, m);
    if (r != 0) {
      printf("\n Do you want make an additional request ? (1=Yes|0=No)");
      scanf("%d", &ch);
      if (ch == 1) {
        printf("\n Enter process no. : ");
        scanf("%d", &pid);
        res_request(ptr->A, ptr->N, ptr->W, pid - 1, m);
        r = banker(ptr->A, ptr->N, ptr->W, n, m);
        if (r == 0)
          exit(0);
      }
    } else
        exit(0);
  }
    return 0;
}
