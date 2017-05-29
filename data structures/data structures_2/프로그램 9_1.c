#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
#define SWAP(x, y ,t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;
int count = 0;

void selection_sort(int list[], int n) {

	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) { //998 999
			if (list[j] < list[least]) least = j;
			count++;
		}
		SWAP(list[i], list[least], temp);
	}
}

int main() {

	int i;
	n = MAX_SIZE;
	for (i = 0; i < n; i++)
		list[i] = rand() % n;

	selection_sort(list, n);
	for (i = 0; i < n; i++)
		printf("%d\n", list[i]);
	printf("~~~~~~~~%d\n", count);
}