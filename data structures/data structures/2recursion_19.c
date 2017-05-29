#include <stdio.h>

int Ackermann(int, int);

int main(int argc, char* argv[])
{
	int a = Ackermann(2, 3);                   //Input
	printf("%d\n", a);

	return 0;
}

int Ackermann(int m, int n)
{
	if (m == 0) return n + 1;
	else if (n == 0) return Ackermann(m - 1, 1);
	else return Ackermann(m - 1, Ackermann(m, n - 1));
}