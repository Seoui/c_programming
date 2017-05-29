#include <stdio.h>

void inc(int list[], int first, int last, int gap) {

	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

int main() { 

	int list[11] = { 10, 8, 6, 20, 4, 3, 22, 1, 0, 15, 16 };
	int i, j, gap = 5;
	char a;
	for (gap = 5; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)
			inc(list, i, 10, gap);
	}

	for (j = 0; j < 11; j++)
		printf("%d, ", list[j]);
	
	scanf_s("%hhd", &a);

	return 0;

}