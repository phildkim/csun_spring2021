#include <stdio.h>
#include <stdlib.h>
struct node {
  int *pages, *memory;
}*ptr=NULL;
typedef struct node node;
int n, m;

void init(char **argv) {
  int i;
  FILE *system = fopen(argv[1], "r");
  fscanf(system, "%d", &n);
  fscanf(system, "%d", &m);
  ptr = (struct node *)malloc(n * sizeof(struct node));
  ptr->pages = (int *)malloc(n * sizeof(*ptr->pages));
  ptr->memory = (int *)malloc(m * sizeof(*ptr->memory));
  for (i=0; i<n; i++)
    fscanf(system, "%d", &ptr->pages[i]);
  for (i = 0; i < m; i++)
    ptr->memory[i] = -1;
  printf("The following reference string is processed:\n");
  for (i=0; i<n; i++)
    printf("%*d", 2, ptr->pages[i]);
  printf("\n");
}

void fifo() {
  int i, f=0, r=0, s=0, count=0, flag=0, num;
  printf("\nFIFO page replacement algorithm:");
  while (s < n) {
    flag=0;
    num=ptr->pages[s];
    // check wether the page is already exist
    for (i=0; i<m; i++) {
      if (num == ptr->memory[i]) {
        s++;
        flag=1;
        break;
      }
    }
    // if page is not already exist
    if (flag == 0) {
      if (r < m) {
        ptr->memory[r] = ptr->pages[s];
        r++;
        s++;
        count++;
      } else {
        if (f < m) {
          ptr->memory[f] = ptr->pages[s];
          s++;
          f++;
          count++;
        } else
          f = 0;
      }
    }
    // print the page frame
    printf("\n");
    for (i=0; i<m; i++)
      (ptr->memory[i] == -1) ? printf("%*s", 3, "_") : printf("%*d", 3, ptr->memory[i]);
  }
  printf("\nFIFO Page Faults = %d\nFIFO Faults Ratio = %.2f\n", count, (float)count/n);
}

void lru() {
  int count[m], i, j, k=0, fault=0, flag, temp, current, c, dist=0, least, t, cnt, p, x;
  printf("\nLRU page replacement algorithm:");
  for (i = 0; i < m; i++) {
    ptr->memory[i] = -1;
    count[i] = 0; // helps to know recently used page
  }
  for (i = 0; i < n; i++){
    flag = 0;
    temp = ptr->pages[i];
    // check wether the page is already exist or not
    for (j = 0; j < m; j++){
      if (temp == ptr->memory[j]){
        flag = 1;
        count[j] = i;
        break;
      }
    }
    //if the page is not already exist and frame has empty slot
    if (flag == 0 && k < m) {
      fault++;
      ptr->memory[k] = temp;
      count[k] = i;
      k++;
    } else if (flag == 0 && k == m) {
      // if the page is not already exist and frame is full
      fault++;
      //find the least recenlty used page
      least = count[0];
      for (t = 0; t < m; t++){
        if (count[t] < least){
          least = count[t];
          p = t;
        }
      }
      ptr->memory[p] = temp;
      count[p] = i;
      p = 0;
    }
    //print the page frame
    printf("\n");
    for (x = 0; x < m; x++)
      (ptr->memory[x] == -1) ? printf("%*s", 3, "_") : printf("%*d", 3, ptr->memory[x]);
  }
  printf("\nLRU Page Faults = %d\nLRU Faults Ratio = %.2f\n", fault, (float)fault / n);
}

void optimal() {
  int count[m], i, j, k=0, l, t, p, r, fault=0, flag, temp, max, tempflag = 0;
  for (i = 0; i < m; i++){
    count[i] = 0;
    ptr->memory[i] = -1;
  }
  for (i = 0; i < n; i++){
    flag = 0;
    temp = ptr->pages[i];
    // check wether the page is already exist
    for (j = 0; j < m; j++){
      if (temp == ptr->memory[j]){
        flag = 1;
        break;
      }
    }
    // if the page is not already exist and frame has empty slot
    if (flag == 0 && k < m){
      fault++;
      ptr->memory[k] = temp;
      k++;
    } else if (flag == 0 && k == m){
      // if the page is not already exist and frame is full
      fault++;
      for (l = 0; l < m; l++)
        count[l] = 0;
      //apply optimal replacemnt strategy
      for (t = 0; t < m; t++){
        tempflag = 0;
        for (r = i + 1; r < n; r++) {
          if (ptr->memory[t] == ptr->pages[r]){
            if (count[t] == 0)
              count[t] = r;
            tempflag = 1;
          }
        }
        if (tempflag != 1)
          count[t] = n + 1;
      }
      //find optimal page to replace
      p = 0;
      max = count[0];
      for (l = 0; l < m; l++){
        if (count[l] > max){
          max = count[l];
          p = l;
        }
      }
      ptr->memory[p] = temp;
    }
    //print the page frame
    printf("\n");
    for (l = 0; l < m; l++)
      (ptr->memory[l] == -1) ? printf("%*s", 3, "_") : printf("%*d", 3, ptr->memory[l]);
  }
  printf("\nOPTIMAL Page Faults = %d\nOPTIMAL Faults Ratio = %.2f\n", fault, (float)fault / n);
}

void collection() {
  if (ptr!=NULL)
    free((void*)ptr);
}

int main(int argc, char **argv) {
  // read text file and initialize dynamic memory
  init(argv);
  fifo();
  lru();
  optimal();
  // garbage collection
  collection();
  return 0;
}