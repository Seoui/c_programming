#include <stdio.h>

double fraction_sum(double);

int main(int argc, char* argv[])
{
	double a;
	a = fraction_sum(5);                  //Input
	printf("%f\n", a);

	return 0;
}

double fraction_sum(double x) {
	
	double a = 1 / x;
	if (a == 1) return 1;
	else return a + fraction_sum(x - 1);
}