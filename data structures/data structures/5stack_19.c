#include <stdio.h>

#define MAX 100

typedef int element;

//전역변수로 설정
element stack[MAX];
int top = -1;

void push(element item)
{
	stack[++top] = item;
}

int size() 
{
	return top + 1;
}

int main(int argc, char* argv[]) 
{
	push(1);
	push(2); 
	push(3);
	printf("%d\n\n", size());

	return 0;
}
