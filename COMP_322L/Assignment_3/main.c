#include <stdio.h>
#include <stdlib.h>
struct node {
  int *R;
  int **P;
} *ptr = NULL;
typedef struct node node;
/**
 *  Let (n) be the number of processes in the system and (m) be the number of resource types.
 *
 *  - Available:
 *      A vector of length m indicates the number of available resources of each type.
 *      If Available[j] = k, there are k instances of resource type Rⱼ available.
 *
 *  - Maximum:
 *      An (n × m) matrix defines the maximum demand of each process.
 *      If Max[i,j] = k, then Pᵢ may request at most k instances of resource type Rⱼ.
 *
 *  - Allocation:
 *      An (n × m) matrix defines the number of resources of each type currently allocated to each process.
 *      If Allocation[i,j] = k, then process Pᵢ is currently allocated k instances of resource type Rⱼ.
 *
 *  - Required: (Required[i,j] = Maximum[i,j] - Allocation[i,j])
 *      An (n × m) matrix indicates the remaining resource need of each process.
 *      If Need[i,j] = k, then Pᵢ may need k more instances of resource type Rⱼ to complete the task.
 *
 *  @ Safe and Unsafe States:
 *      Any state where no such set exists is an unsafe state.
 *      If requests by the processes allow each to acquire its maximum resources, then terminate.
 *
 *  @ Requests: (Banker's algorithm to determine if it is safe to grant the request)
 *      1. Can the request be granted?
 *          If not, the request is impossible and must either be denied or put on a waiting list
 *      2. Assume that the request is granted
 *      3. Is the new state safe?
 *          If so grant the request
 *          If not, either deny the request or put it on a waiting list
 *
 *      Final example: from the state we started at, assume that process 2 requests 1 unit of resource B.
 *          1. There are enough resources
 *          2. Assuming the request is granted, the new state would be:
 *               Available system resources:
 *               A B C D
 *          Free 3 0 1 2
 *
 *              Processes (currently allocated resources):
 *              A B C D
 *         P1   1 2 5 1
 *         P2   1 1 3 3
 *         P3   1 2 1 0
 *
 *              Processes (maximum resources):
 *              A B C D
 *         P1   3 3 2 2
 *         P2   1 2 3 4
 *         P3   1 3 5 0
 */
int main(int argc, char **argv) {

  printf("Total system resources are:\t");
  printf("Available system resources are:\t");
  printf("Processes (currently allocated resources):\t");
  printf("Processes (maximum resources):\t");
  printf("Required = maximum resources - currently allocated resources
        \nProcesses (possibly needed resources):\t");
  return 0;
}
