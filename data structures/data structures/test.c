#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct intarr {
	int x;
	char str[MAX_SIZE];
}intarr;



int main(int argc, char* argv[])
{
	char arr[20] = "just string";

	for (int i = 0; i < 20; i++)
	{
		printf("%c", arr[i]);
	}
	printf("\n");

	return 0;
}