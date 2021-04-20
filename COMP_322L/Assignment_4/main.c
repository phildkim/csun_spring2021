#include <stdio.h>
#include <stdlib.h>
struct node {
	int *data;
} *ptr = NULL;
typedef struct node node;
int size;
/**
 * @brief init_fit
 * @note initialize
 * @retval None
 */
void init_fit() {
	int i;
	printf("\nEnter size:\t");
	scanf("%d", &size);
	ptr = (struct node *)malloc(size * sizeof(struct node));
	ptr->data = (int *)malloc(size * sizeof(*ptr->data));
	printf("\nEnter data:\t");
	for (i = 0; i < size; i++)
		scanf("%d", &ptr->data[i]);
}
/**
 * @brief first-fit
 * @note
 * @retval None
 */
void first_fit() {
	printf("first-fit\n");
}
/**
 * @brief next-fit
 * @note
 * @retval None
 */
void next_fit() {
	printf("next-fit\n");
}
/**
 * @brief best-fit
 * @note
 * @retval None
 */
void best_fit() {
	printf("best-fit\n");
}
/**
 * @brief worst-fit
 * @note
 * @retval None
 */
void worst_fit() {
	printf("worst-fit\n");
}
/**
 * @brief print
 * @note
 * @retval None
 */
void print(int size) {
	int i;
	printf("Data:\n");
	for (i = 0; i < size; i++)
		printf("%*d", 3, ptr->data[i]);
	printf("\n");
}
/**
 * @brief garbage collection
 * @note deallocate dynamic memory
 * @retval None
 */
void collection() {
	if (ptr != NULL)
		free((void*)ptr);
}
int main(void) {
	int n;
	while (n != 6) {
		printf("\n1. initialize\n2. first-fit\n3. next-fit\n4. best-fit \n5. worst-fit\n6. print\n7. quit\nEnter #:\t");
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
				print(size);
				break;
		}
	}
	collection();
	return 0;
}