#include <stdio.h>
#include <stdlib.h>
/**
 * Singly Linked List:
 *  - integers: data
 *  - memory address: next
 */
struct node {
  int data;
  struct node *next;
}*nodeptr=NULL;
typedef struct node node;
/**
 * Garbage collection
 */
void collection(){
  if (nodeptr != NULL)
    free((void *)nodeptr);
}
/**
 * Print function
 */
void print(int n) {
  int i=1;
  struct node *nodetmp;
  nodetmp = nodeptr;
  while(nodetmp!=NULL) {
    printf("node%d:[%d][%p]--> ", i, nodetmp->data, nodetmp->next);
    nodetmp = nodetmp->next;
    i++;
  }
  printf("\n");
}
/**
 * Create singly linked list and insert integers
 */
void create(int n){
  int m,i;
  struct node *nodetmp,*nodelst;
  nodeptr = (node *)malloc(n * sizeof(node));
  printf("node1: ");
  scanf("%d", &m);
  nodeptr->data = m;
  nodeptr->next = NULL;
  nodetmp = nodeptr;
  for(i=2;i<=n;i++){
    nodelst = (struct node *)malloc(sizeof(struct node));
    printf("node%d: ",i);
    scanf("%d", &m);
    nodelst->data=m;
    nodelst->next=NULL;
    nodetmp->next=nodelst;
    nodetmp=nodetmp->next;
  }
}
int main(void) {
  int n;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  create(n);
  print(n);
  collection();
  return 0;
}