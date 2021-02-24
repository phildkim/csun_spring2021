#include <stdio.h>

void fifo() {

}
void sjf() {

}
void srt() {

}
int main(void) {
  int n;
  printf("# of process: ");
  scanf("%d",&n);
  printf("\n| Process |");
  for (int i = 0; i < n; i++) {
    printf(" %c |",'A'+i);
  }
  printf("\n");
  return 0;
}