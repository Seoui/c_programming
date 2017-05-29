#include <stdio.h>
#include <string.h>

#define Max 100

typedef char element;

typedef struct {
	element stack[Max];
	int top;
}stacktype;

void init(stacktype *s)
{
	s->top = -1;
}

int is_empty(stacktype *s)
{
	return (s->top == -1);
}

int is_full(stacktype *s)
{
	return (s->top == (Max-1));
}

void push(stacktype *s, element item)
{
	s->stack[++(s->top)] = item;
}

element pop(stacktype *s)
{
	return s->stack[(s->top)--];
}

element peek(stacktype *s)
{
	return s->stack[s->top];
}

int prec(char op)
{
	switch (op) {
		case '(': case ')': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
	}
	return -1;
}

void infix_to_postfix(char exp[])
{
	int length = strlen(exp);
	char ch, top_op;
	stacktype s;

	init(&s);

	for (int i = 0; i < length; i++)
	{
		ch = exp[i];


		switch (ch) {
			
		case '+': case '-': case '*': case '/':
			//while ( !empty 그리고 ch의(연산자) 연산순위가 stack에 있는 연산자의 연산순위 보다 작거나 같으면)
			// * empty 그리고 ch의(연산자) 연산순위가 stack에 있는 연산자의 연산순위 보다 크다면 반복문을 stop
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);     //위에 반복문이 실행되지 않을 수도 있다. 그런 경우 그냥 push
			break;
		case '(':
			push(&s, ch);    //왼쪽괄호는 그냥 무조건 push!
			break;
		case ')':
			top_op = pop(&s);
			while (top_op != '('){
				printf("%c", top_op);
				top_op = pop(&s);            //pop한것을 top_op에게 대입한다 (계속 delete 되기 때문에 top_op는 값이 계속 변한다)
			}
			break;
		default:
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

int main(int argc, char* argv[])
{
	infix_to_postfix("5*(4+2)/3");

	printf("\n");

	return 0;
}