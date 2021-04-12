#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *  i: process number
 *  j: resource number
 *  k: number of units
 */
struct node {
  int n,m;
}*ptr = NULL;
typedef struct node node;

/**
 *  Number of units of each resource:
 *    - R[m], where m is the number of resources
 *
 *  Number of units of resource Rⱼ:
 *    - R[j], each entry records units of resources Rⱼ
 *
 *  Mximum claims:
 *    - P[n][m],
 *    - P[i][j], records the max number of units of Rⱼ that Pᵢ requests
 *
 *  Reads the description of a system:
 *    - number of processes (i)
 *    - number of resources (j)
 *    - numbers of units within each resource (k)
 *    - maximum claims of each process
 *
 *  Create the current representation of the system (the set of arrays),
 *  then enters an interactive session during which the user inputs:
 *    - request(i, j, k)
 *    - release(i, j, k)
 *
 *  Program responds whether the request:
 *    - granted
 *    - denied
 */

int main(int argc, char *argv[]) {
  int n, m, i, j;
  printf("Number of resources:\t");
  scanf("%d", &m);
  printf("Number of processes:\t");
  scanf("%d", &n);
  ptr = (node *)malloc(m * sizeof(node));
  for (i = 0; i < m; i++) {
    printf("Unit of Resource[%d]:\t",i);
    scanf("%d", &ptr[i].m);
  }
  int P[n][m];
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("Maximum claims of Process[%d][%d]", i, j);
      scanf("%d", &P[i][j]);
    }
  }
  int *process = &P[0][0];
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", *(process + i * n + j));
    }
    printf("\n");
  }

  return 0;
}