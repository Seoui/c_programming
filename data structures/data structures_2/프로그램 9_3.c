#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

int n;
int list[MAX_SIZE];
int count;

void insertion_sort(int list[], int n) {

	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];;
		list[j + 1] = key;
	}
}
int main() {

	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)
		list[i] = rand() % n;

	insertion_sort(list, n);
	for (i = 0; i < n; i++)
		printf("%d\n", list[i]);
	printf("~~~~~~~~%d\n", count);
}