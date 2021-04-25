#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node {
	int *b, *p;
	int *bf, *pf;
} *ptr = NULL;
typedef struct node node;
int n, m;
void init(char **argv) {
	int i;
	FILE *sys = fopen(argv[1], "r");
	fscanf(sys, "%d", &m);//block
	fscanf(sys, "%d", &n);//process
	ptr = (struct node *)malloc(n * sizeof(struct node));
	ptr->b = (int *)malloc(m * sizeof(*ptr->b));
	ptr->bf = (int *)malloc(m * sizeof(*ptr->bf));
	for (i=0;i<m;i++) {
		fscanf(sys, "%d", &ptr->b[i]);
		ptr->bf[i] = 0;
	}
	ptr->p = (int *)malloc(n * sizeof(*ptr->p));
	ptr->pf = (int *)malloc(m * sizeof(*ptr->pf));
	for (i = 0; i < n; i++) {
		fscanf(sys, "%d", &ptr->p[i]);
		ptr->pf[i] = 0;
	}
}
void reset() {
	int i;
	for (i = 0; i < n; i++)
		ptr->pf[i] = 0;
	for (i = 0; i < m; i++)
		ptr->bf[i] = 0;
}
void print() {

}
void collection() {
	if (ptr != NULL)
		free((void*)ptr);
}

int main(int argc, char **argv) {
	int i, j, id, loc,
	min_frag, max_frag,
	in_frag = 0, ex_frag = 0;

	// initialize
	init(argv);

	// first fit
	printf("\nFIRST-FIT");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (ptr->p[i] <= ptr->b[j] && ptr->bf[j] == 0 && ptr->pf[i] == 0) {
				ptr->bf[j] = ptr->pf[i] = 1;
				in_frag += ptr->b[j] - ptr->p[i];
				printf("\nP[%d]:\tB[%d]", i, j);
				break;
			}
		}
		if (ptr->pf[i] == 0)
			printf("\nP[%d]:\tNot Allocated", i);
	}
	printf("\nINTERNAL FRAG: %d", in_frag);
	for(j=0;j<m;j++){
		if(ptr->bf[j] == 0)
			ex_frag+=ptr->b[j];
	}
	printf("\nEXTERNAL FRAG: %d\n", ex_frag);

	// best fit
	reset();
	printf("\n\nBEST-FIT");
	for (i = 0; i < n; i++) {
		min_frag = INT_MAX;
		id = INT_MAX;
		for (j = 0; j < m; j++) {
			if (ptr->p[i] <= ptr->b[j] && ptr->bf[j] == 0 && min_frag > (ptr->b[j] - ptr->p[i])) {
				min_frag = ptr->b[j] - ptr->p[i];
				id = j;
			}
		}
		if (min_frag != INT_MAX) {
			ptr->bf[id] = ptr->pf[i] = 1;
			in_frag += ptr->b[id] - ptr->p[i];
			printf("\nP[%d]:\tB[%d]", i, id);
		}
		if (ptr->pf[i] == 0)
			printf("\nP[%d]:-\tNot Allocated", i);
	}
	printf("\nINTERNAL FRAG: %d", in_frag);
	for(j=0;j<m;j++){
		if(ptr->bf[j] == 0)
			ex_frag+=ptr->b[j];
	}
	printf("\nEXTERNAL FRAG: %d\n", ex_frag);

	// worst fit
	reset();
	printf("\n\nWORST-FIT");
	for(i=0;i<n;i++) {
		max_frag = -1;
		id=INT_MAX;
		for (j = 0; j < m; j++) {
			if (ptr->p[i] <= ptr->b[j] && ptr->bf[j] == 0 && max_frag < (ptr->b[j] - ptr->p[i])) {
				max_frag = ptr->b[j] - ptr->p[i];
				id = j;
			}
		}
		if(max_frag != -1){
				ptr->bf[id] = ptr->pf[i] = 1;
				in_frag += ptr->b[id] - ptr->p[i];
				printf("\nP[%d]:\tB[%d]",i,id);
		}
		if (ptr->pf[i] == 0)
			printf("\nP[%d]:\tNot Allocated", i);
	}
	printf("\nINTERNAL FRAG: %d", in_frag);
	for(j=0;j<m;j++){
		if(ptr->bf[j] == 0)
			ex_frag+=ptr->b[j];
	}
	printf("\nEXTERNAL FRAG: %d\n", ex_frag);

	// next fit
	reset();
	printf("\nEnter block no. to begin allocation: ");
	scanf("%d", &loc);
	printf("NEXT-FIT");
	for (i = 0; i < n; i++) {
		for (j = loc; j < m; j++) {
			if (ptr->p[i] <= ptr->b[j] && ptr->bf[j] == 0 && ptr->pf[i] == 0) {
				ptr->bf[j] = ptr->pf[i] = 1;
				in_frag += ptr->b[j] - ptr->p[i];
				printf("\nP[%d]:\tB[%d]", i, j);
				loc = ((j + 1) == m) ? 0 : j+1;
				break;
			}
		}
		if (ptr->pf[i] == 0)
			printf("\nP[%d]:\tNot Allocated", i);
	}
	printf("\nINTERNAL FRAG: %d",in_frag);
	for(j=0;j<m;j++){
		if(ptr->bf[j] == 0)
			ex_frag+=ptr->b[j];
	}
	printf("\nEXTERNAL FRAG: %d\n", ex_frag);
}