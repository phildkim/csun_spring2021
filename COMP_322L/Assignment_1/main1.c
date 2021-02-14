/**
 * Problem 1.1
 * - Implement a queue, with two function enqueue and dequeue.
 * - First fill the queue with ten numbers, then empty it.
 * - Print the queue in the output each time you insert and delete from the queue.
 */
#include <stdio.h>
#define N 10//max integers
int array[N],head=-1,tail=-1;
// enqueue takes an integer and stores
void enqueue(int num) {
  if (tail == N-1) return;
  else
  {
    if (head == -1)
      head = 0;
    tail++;
    array[tail] = num;
    printf("\nadd %d", num);
  }
  int i;
  printf("\nqueue: ");
  for (i = head; i <= tail; i++)
    printf("%d,", array[i]);
  printf("\n");
}
void dequeue() {
  if (head == -1) return;
  else
  {
    printf("\ndelete %d", array[head]);
    head++;
    if (head > tail)
      head = tail = -1;
  }
  int i;
  printf("\nqueue: ");
  for (i = head; i <= tail; i++)
    printf("%d,", array[i]);
  printf("\n");
}
int main(void) {
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);
  enqueue(6);
  enqueue(7);
  enqueue(8);
  enqueue(9);
  enqueue(10);
  for (int i = 0; i < N; i++) {
    dequeue();
  }
  return 0;
}
