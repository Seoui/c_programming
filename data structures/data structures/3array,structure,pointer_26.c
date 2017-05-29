#include <stdio.h>

int main(int argc, char* argv[])
{
	int x[6] = { 1,2,3,4,5,6 };
	int *p;
	p = &x[2];
	printf("%d, %d, %d\n", *(p + 3), *(p - 2), (*(p + 3))*(*(p - 2)));

	return 0;
}