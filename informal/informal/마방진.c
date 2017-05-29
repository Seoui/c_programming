#include <stdio.h>

int main(int argc, char* argv[])
{
	int a[5][5] = { 0 };
	int i = 0, j = 0;
	int x = 0, y = 2;
	int count = 1;

	a[0][2] = count;

	//단순함의 절정

	for (i = 0; i < 5; i++) {

		for (j = 0; j < 5; j++) {
			a[x][y] = count;
			count++;
			x--;
			y++;
			if (x < 0 && j < 4)	x = 4;
			if (y > 4 && j < 4)	y = 0;
		}
		x = x + 2;
		y = y - 1;
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}