#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct intarr{
	int x;
	char str[MAX_SIZE];
}intarr;

int main(int argc, char* argv[])
{
	intarr *p;

	p = (intarr*)malloc(sizeof(intarr));
	
	p->x = 100;
	strcpy(p->str, "just string");

	printf("x is %d\n", p->x);
	puts(p->str);

	free(p);

	return 0;
}