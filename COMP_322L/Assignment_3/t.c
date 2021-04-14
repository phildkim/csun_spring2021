#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int r;
  int row, col, count = 0;
  int numberOfProcess;
  printf("\n Enter Number Of Process: ");
  scanf("%d", &numberOfProcess);
  int numberOfResources;
  printf("\n Enter Number Of Resource: ");
  scanf("%d", &numberOfResources);

  // to store available resources
  int *availableResource = (int *)malloc(sizeof(int) * numberOfResources);
  // to store maximum resources of each type
  int **maximumResource = (int **)malloc(sizeof(int) * numberOfProcess);
  for (r = 0; r < numberOfProcess; r++)
    maximumResource[r] = (int *)malloc(sizeof(int) * numberOfResources);
  // to store allocated resources of each type
  int **allocationResource = (int **)malloc(sizeof(int) * numberOfProcess);
  for (r = 0; r < numberOfProcess; r++)
    allocationResource[r] = (int *)malloc(sizeof(int) * numberOfResources);
  // to store calculated need resources of each type
  int **needResource = (int **)malloc(sizeof(int) * numberOfProcess);
  for (r = 0; r < numberOfProcess; r++)
    needResource[r] = (int *)malloc(sizeof(int) * numberOfResources);
  // To store safe process sequence
  int processSequence[numberOfProcess];
  for (row = 0; row < numberOfResources; row++){
    printf("\n Number Of Available Resource %d: ", (row + 1));
    scanf("%d", &availableResource[row]);
  }
  for (row = 0; row < numberOfProcess; row++){
    for (col = 0; col < numberOfResources; col++){
      printf("\n Allocation P %d for R %d: ", (row + 1), (col + 1));
      scanf("%d", &allocationResource[row][col]);
    }
  }
  for (row = 0; row < numberOfProcess; row++){
    for (col = 0; col < numberOfResources; col++){
      printf("\n MAX P %d for R %d: ", (row + 1), (col + 1));
      scanf("%d", &maximumResource[row][col]);
      needResource[row][col] = maximumResource[row][col] - allocationResource[row][col];
    }
  }
  printf("\n Available Resources: ");
  for (row = 0; row < numberOfResources; row++)
    printf("%4d", availableResource[row]);
  printf("\n Allocation \t MAX \t\t\t Need\n");
  for (row = 0; row < numberOfProcess; row++){
    printf("P%d", (row + 1));
    for (col = 0; col < numberOfResources; col++)
      printf("%4d", allocationResource[row][col]);
    printf("\t\t");
    for (col = 0; col < numberOfResources; col++)
      printf("%4d", maximumResource[row][col]);
    printf("\t\t");
    for (col = 0; col < numberOfResources; col++)
      printf("%4d", needResource[row][col]);
    printf("\n");
  }

  // Creates an array of size availableResource
  int *work = (int *)malloc(sizeof(int) * numberOfResources);
  for (row = 0; row < numberOfResources; row++)
    work[row] = availableResource[row];

  // Creates an array of size numberOfProcess to store process finish status
  int *finish = (int *)malloc(sizeof(int) * numberOfProcess);
  for (row = 0; row < numberOfProcess; row++)
    finish[row] = 0;

  // checking is status is true
  int checking = 1;
  // Loops till checking is true for working & sets checking status to false for not finished
  while (checking){
    checking = 0;
    // Loops till # of processes & if the current row index of the finish array is not false
    for (row = 0; row < numberOfProcess; row++){
      if (!finish[row]){
        int col;
        // Loops till # of resources & if current row and col index of needResource > work
        for (col = 0; col < numberOfResources; col++)
          if (needResource[row][col] > work[col])
            break;
        // Checks if col index value is equals to number of resources
        if (col == numberOfResources){
          for (col = 0; col < numberOfResources; col++)
            work[col] = work[col] + allocationResource[row][col];
          // Sets finish array to true for finish process
          finish[row] = 1;
          // Sets the checking status to true
          checking = 1;
          // Adds the row number as process number to finish process sequence
          processSequence[count++] = row;
        }
      }
    }
  }
  int counter;
  // if counter index of the finish array is not finish (false) then come out of the loop
  for (counter = 0; counter < numberOfProcess; counter++)
    if (!finish[counter])
      break;
  printf("\n SAFE And Sequence is \n");
  // Checks if counter value is equals to number of process than display safe sequence
  if (counter == numberOfProcess)
    for (r = 0; r < count; r++)
      printf(" Process: %d\n", processSequence[r]);
  else
    printf("\n DEAD LOCK");
}