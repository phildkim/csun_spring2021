#include <stdio.h>
#include <stdlib.h>
struct node {
  int n, m;
}*ptr = NULL;
typedef struct node node;
int *R;
int **P;


void description() {
  int i, j, p, r;
  printf("\nDynamic Deadlock Avoidance using Banker’s Algorithm");
  printf("\nThe number of processes:\t");
  scanf("%d", &p);
  printf("The number of resources:\t");
  scanf("%d", &r);
  R = (int *)malloc(r *sizeof(*R));
  for (i = 0; i < r; i++) {
    printf("The number of units for R[%d]:\t", i + 1);
    scanf("%d", &R[i]);
  }
  P = (int **)malloc(p * sizeof(*P));
  for (i = 0; i < p; i++)
    P[i] = (int*)malloc(p *sizeof(**P));
  for (i = 0; i < p; i++) {
    for (j = 0; j < r; j++) {
      printf("The maximum claims of P[%d][%d]:\t", i + 1, j + 1);
      scanf("%d", &P[i][j]);
    }
  }
  for (i = 0; i < p; i++) {
    for (j = 0; j < r; j++)
      printf("%d ", P[i][j]);
    printf("\n");
  }
}
// R[m] = number of units of each resource, m is number of resources
// R[j] = number of units Rⱼ
// P[n][m] = max claims
// P[i][j] = max Rⱼ that Pᵢ requests
int main() {
  description();
  return 0;
}
/* 1) Develop an interactive program that first reads the description of a system from the command line or from a file. The description consists of the number of processes, the number of resources, the numbers of units within each resource, and the maximum claims of each process. Using the given information, the program creates the current representation of the system (the set of arrays). */

/* 2) The program then enters an interactive session during which the user inputs commands of the form: request(i, j, k) or release(i, j, k), where i is a process number, j is a resource number, and k is the number of units of Rⱼ the process pᵢ is requesting or releasing. For each request operation, the program responds whether the request has been granted or denied. */

/* The number of units of each resource is represented as a one-dimensional array R[m], where m is the number of resources and each entry R[j] records the number of units of resource Rⱼ. */

/* The maximum claims are represented as a two-dimensional array P[n][m] where each entry P[i][j] contains an integer that records the maximum number of units of resource Rⱼ that process Pᵢ will ever request. */