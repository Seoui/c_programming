#include <stdio.h>

double binomial_coefficient(int, int);

int main(int argc, char* argv[])
{
	double a = binomial_coefficient(7, 3);             //Input
	printf("%f\n", a);

	return 0;
}

double binomial_coefficient(int n, int k)
{
	double result = 1;
	double j = k;

	for (int i = 0; i < j; i++)
	{
		result = result * n / k;
		n--;
		k--;
	}
	
	return result;
}