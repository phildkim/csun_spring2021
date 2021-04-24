#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
	int *allocated;
	int *block;
	int *process;
} *ptr = NULL;
typedef struct node node;
int n, m;
void init_fit() {
	int i;
	printf("\nBlock size: ");//5
	scanf("%d", &n);
	printf("Process size: ");//4
	scanf("%d", &m);
	ptr = (struct node *)malloc(n * sizeof(struct node));
	ptr->block = (int *)malloc(n * sizeof(*ptr->block));
	ptr->process = (int *)malloc(m * sizeof(*ptr->process));
	ptr->allocated = (int *)malloc(m * sizeof(*ptr->allocated));
	for (i = 0; i < n; i++) {
		ptr->block[i] = 0;
	}
	for (i = 0; i < m; i++) {
		ptr->process[i] = 0;
		ptr->allocated[i] = -1;
	}
	// memset(ptr->allocated, -1, sizeof(*ptr->allocated));
	printf("\nEnter block size: ");
	for (i = 0; i < n; i++)
		scanf("%d", &ptr->block[i]);
	printf("\nEnter process size: ");
	for (i = 0; i < m; i++)
		scanf("%d", &ptr->process[i]);

}

void print() {
	int i;
	printf("P[ID]\t SIZE\t BLOCK");
	for (i = 0; i < m; i++) {
		printf("\nP[%d]:\t%*d", i + 1, 4, ptr->process[i]);
		(ptr->allocated[i] != -1) ? printf("\t\b%*d", 5, ptr->block[i] + 1) : printf("\t NOT ALLOCATED");
	}
	printf("\n");
}

void first_fit() {
	int i, j;
	printf("first-fit:\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (ptr->block[j] >= ptr->process[i]) {
				ptr->allocated[i] = j;
				ptr->block[j] -= ptr->process[i];
				break;
			}
		}
	}
	print();
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
	int n = 0;
	while (n < 7) {
		printf("\n1. Initialize\n2. First-fit\n3. Next-fit\n4. Best-fit \n5. Worst-fit\n6. Quit\nEnter #: ");
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
			case 6:
				collection();
				exit(-1);
			default:
				printf("\nINVALID");
				n = 0;
		}
	}
	collection();
	return 0;
}