#include <stdio.h>
#include <stdlib.h>
struct node {
	int *allocated;
	int *block;
	int *process;
} *ptr = NULL;
typedef struct node node;

void init_fit() {
	int i, n, m;
	printf("\nBlock size: ");
	scanf("%d", &n);
	printf("Process size: ");
	scanf("%d", &m);
	ptr = (struct node *)malloc(n * sizeof(struct node));
	ptr->block = (int *)malloc(n * sizeof(*ptr->block));
	ptr->process = (int *)malloc(m * sizeof(*ptr->process));



}

void print() {
	int i;

}

void first_fit() {
	printf("first-fit:\n");

}

void next_fit() {
	printf("next-fit:\n");

}

void best_fit() {
	printf("best-fit:\n");

}

void worst_fit() {
	printf("worst-fit:\n");

}

void collection() {
	if (ptr != NULL)
		free((void*)ptr);
}

int main(void) {
	int n;
	while (n != 6) {
		printf("\n1. Initialize\n2. First-fit\n3. Next-fit\n4. Best-fit \n5. Worst-fit\n7. Quit\nEnter #: ");
		scanf("%d", &n);
		switch (n) {
			case 1:
				init_fit();
				break;
			case 2:
				first_fit();
				break;
			case 3:
				next_fit();
				break;
			case 4:
				best_fit();
				break;
			case 5:
				worst_fit();
				break;
			default:
				break;
		}
	}
	collection();
	return 0;
}