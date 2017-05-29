#include <stdio.h>
#include <malloc.h>


typedef struct polynode {
	int coef;
	int expon;
	struct polynode *link;
}polynode;

typedef struct listheader {
	polynode *head;
	polynode *tail;
	int length;
}listheader;

void init(listheader *polylist)
{
	polylist->head = NULL;
	polylist->tail = NULL;
	polylist->length = 0;
}
void insert_node(listheader *polylist, int coef, int expon)
{
	polynode *temp = (polynode *)malloc(sizeof(polynode));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	if (polylist->length == 0) {  //꼭 tail == NULL 인 조건을 주어야 하는가??
 		polylist->head = temp;
		polylist->tail = temp;
	}
	else {
		polylist->tail->link = temp;
		polylist->tail = temp;
	}
	polylist->length++;
}

void add_polynomial(listheader *Ax, listheader *Bx, listheader *Cx)
{
	polynode *A = Ax->head;
	polynode *B = Bx->head;
	int sum;

	while (A != NULL || B != NULL) {   //후 head가 NULL 이 되어야 끝까지 간다....지금껏 head->link가 NULL되는 조건을 주었는데 아니였다.

		if (A->expon > B->expon)
		{
			insert_node(Cx, A->coef, A->expon);
			A = A->link;
		}
		else if (A->expon == B->expon)
		{
			sum = A->coef + B->coef;
			if(sum!=0) insert_node(Cx, sum , A->expon);   //중요한걸 빼먹지 말자, 계수가 0이면 항은 존재하지 않는다.
			A = A->link;
			B = B->link;
		}
		else
		{
			insert_node(Cx, B->coef, B->expon);
			B = B->link;
		}
	}

	for (; A != NULL; A = A->link)
		insert_node(Cx, A->coef, A->expon);

	for (; B != NULL; B = B->link)
		insert_node(Cx, B->coef, B->expon);
}

void display(listheader *polylist)
{
	polynode *p= polylist->head;
	for(;p;p=p->link){
		printf("%dx%d ", p->coef, p->expon);
	}
	printf("\n");
}

void allfree(listheader *polylist) 
{
	polynode *p = polylist->head;
	polynode *q = NULL;

	for (int i=0;i<polylist->length;i++)
	{
		q = p;
		p = p->link;
		free(q);
	}
}

int main(int argc, char* argv[])
{
	//다항식 A(x) 생성(초기화 한 후에 실행)
	listheader Ax;
	init(&Ax);
	insert_node(&Ax, 3, 6);
	insert_node(&Ax, 7, 3);
	insert_node(&Ax, -2, 2);
	insert_node(&Ax, -9, 0);

	//다항식 B(x) 생성(초기화 한 후에 실행)
	listheader Bx;
	init(&Bx);
	insert_node(&Bx, -2, 6);
	insert_node(&Bx, -4, 4);
	insert_node(&Bx, 6, 2);
	insert_node(&Bx, 6, 1);
	insert_node(&Bx, 1, 0);

	//다항식 C(x) 생성(초기화 한 후에 실행)
	listheader Cx;
	init(&Cx);

	//다항식 출력
	display(&Ax);
	display(&Bx);

	add_polynomial(&Ax, &Bx, &Cx);
	display(&Cx);
	
	//메모리 반환
	allfree(&Ax);
	allfree(&Bx);
	allfree(&Cx);

	return 0;
}