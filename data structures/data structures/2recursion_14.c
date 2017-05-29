#include <stdio.h>

int sum(int);

int main(int argc, char* argv[])
{
	int a;
	a = sum(5);                  //Input
	printf("%d\n", a);

	return 0;
}

int sum(int x) {
	if (x == 1) return 1;
	else return x + sum(x - 1);
}