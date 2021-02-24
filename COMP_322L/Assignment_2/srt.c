#include <stdio.h>
#include <stdlib.h>
typedef unsigned int time;
typedef struct job job;
typedef struct job {
  int id;
  time arrival;
  time process;
  job *next;
} job;
job *prompt(const char *p, int id) {
  time arrival, process;
  job *result;
  for (; printf("%s for J%d: ", p, id); printf("Re-try.\n")) {
    int c;
    char ln[200];
    if (fgets(ln, sizeof(ln), stdin) == 0)
      return 0;
    if (sscanf(ln, " %n", &c) == 0 && c >= 0 && ln[c] == '\0')
      return 0;
    if (sscanf(ln, "%u %u %n", &arrival, &process, &c) == 2 && c > 0 && ln[c] == '\0')
      break;
  }
  result = (job *)malloc(sizeof(job));
  if (result != 0) {
    result->arrival = arrival;
    result->process = process;
    result->id = id;
    result->next = 0;
  }
  return result;
}
job *sort(job *h, time clk) {
  time c;
  job *p, *q, **r, **s;
  for (c = 0, p = h, r = &h; p != NULL;) {
    for (s = &h; (q = *s) != p; s = &q->next)
      if (p->arrival <= clk) {
        if (p->process > q->process)
          break;
      }
      else if (p->arrival < q->arrival ||
               (p->arrival == q->arrival && p->process > q->process))
        break;
    if (q != p)
      *s = p, *r = p->next, p->next = q, p = *r;
    else
      r = &p->next, p = p->next;
  }
  return h;
}
void print(const job *h) {
  if (h != 0) {
    printf("J%d: Arrival = %u, Process = %u\n", h->id, h->arrival, h->process);
    print(h->next);
  }
}
job *destroy(job *h) {
  if (h != 0) {
    destroy(h->next);
    free(h);
  }
  return 0;
}
int main(void) {
  int i;
  time c;
  job *list = 0, *j, **x;
  for (i = 1; (j = prompt("Enter arrival and process times", i)) != 0; ++i)
    j->next = list, list = j;
  for (c = 0, x = &list; *x != 0; x = &(*x)->next)
    c += (*x = sort(*x, c))->process;
  print(list);
  list = destroy(list);
  return 0;
}