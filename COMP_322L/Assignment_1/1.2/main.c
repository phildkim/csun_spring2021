/**
 * Problem 1.2
 * - Implement a stack, with two function Push and Pop
 * - First fill the stack with ten numbers, then empty it.
 * - Print the stack in the output each time you push and pop from the stack.
 */
#include <stdio.h>
#include <stdlib.h>
// points the next integer
struct node {
  int data;
  struct node *next;
};
// store top integer as node and save stack size
struct stack {
  struct node *head;
  int size;
};
// create new stack to store integer, set node's next value to the current top of the stack and set the current top of the stack equal to the node being pushed. Increase size after completed.
void push(int num, struct stack *stack) {
  struct node *node = malloc(sizeof(struct node));
  node->data = num;
  node->next = stack->head;
  stack->head = node;
  stack->size++;
  printf("Push %d\n", num);
}
// make sure stack has at least one integer else exit the function. Save the top integer and then return the top integer if it exists. Decrease the size after completed.
int pop(struct stack *stack) {
  int data = 0;
  if (stack->size != 0) {
    data = stack->head->data;
    stack->head = stack->head->next;
    stack->size--;
  } else {
    exit(0);
  }
  return data;
}
void print(struct stack *stack) {
  struct node *tmp;
  tmp = stack->head;
  printf("Stack: ");
  while (tmp != NULL) {
    printf(",%d", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}
int main(void) {
  int n;
  struct stack *s = malloc(sizeof(*s));
  push(1,s);
  print(s);
  push(2, s);
  print(s);
  push(3, s);
  print(s);
  push(4, s);
  print(s);
  push(5, s);
  print(s);
  push(6, s);
  print(s);
  push(7, s);
  print(s);
  push(8, s);
  print(s);
  push(9, s);
  print(s);
  push(10, s);
  print(s);
  while (n > -1) {
    n = pop(s);
    printf("Pop %d\n", n);
    print(s);
  }
}