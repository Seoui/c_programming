#include <stdio.h>

int binomial_coefficient(int, int);

int main(int argc, char* argv[])
{
	int a = binomial_coefficient(6, 3);            //Input
	printf("%d\n", a);

	return 0;
}

int binomial_coefficient(int n, int k) 
{
	if (k == 0 || k == n) return 1;
	else return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
}