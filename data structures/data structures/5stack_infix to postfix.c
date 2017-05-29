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
			//while ( !empty �׸��� ch��(������) ��������� stack�� �ִ� �������� ������� ���� �۰ų� ������)
			// * empty �׸��� ch��(������) ��������� stack�� �ִ� �������� ������� ���� ũ�ٸ� �ݺ����� stop
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);     //���� �ݺ����� ������� ���� ���� �ִ�. �׷� ��� �׳� push
			break;
		case '(':
			push(&s, ch);    //���ʰ�ȣ�� �׳� ������ push!
			break;
		case ')':
			top_op = pop(&s);
			while (top_op != '('){
				printf("%c", top_op);
				top_op = pop(&s);            //pop�Ѱ��� top_op���� �����Ѵ� (��� delete �Ǳ� ������ top_op�� ���� ��� ���Ѵ�)
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