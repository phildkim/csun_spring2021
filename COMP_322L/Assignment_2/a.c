#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random_num(int n) {
  int i, num, lower=1, upper=n/2;
  for (i = 0; i < 1; i++)
    num = 2*(rand() % (upper - lower + 1));
  return num;
}
int main(void) {
  srand(time(0));
  int n = random_num(100);
  printf("RANDOM #: %d\n", n);
}