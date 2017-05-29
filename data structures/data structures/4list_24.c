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

void init(listheader *p)
{
	p->head = NULL;
	p->tail = NULL;
	p->length = 0;
}

void insert_node(listheader *polylist, int coef, int expon)
{
	polynode *temp = (polynode *)malloc(sizeof(polynode));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	if (polylist->length == 0){
		polylist->head = temp;
		polylist->tail = temp;
	}
	else {
		polylist->tail->link = temp;
		polylist->tail = temp;
	}
	polylist->length++;
}

double poly_eval(listheader *polylist, double x)
{
	polynode *p = polylist->head;
	double sum =0;
	double sum1 = 0;
	double exp = x;

	while (p) {
		if (p->expon >1 ) {
			for (int i = 1; i < p->expon; i++)
				x = x * exp;
			sum1 = x * (p->coef);
			sum = sum + sum1;
			p = p->link;
		}
		else if (p->expon == 1) {
			sum = sum + exp * (p->coef);
			p = p->link;
		}
		else {
			sum = sum + (p->coef);
			p = p->link;
		}
	}
	return sum;
}

void allfree(listheader *polylist)
{
	polynode *p = polylist->head;
	polynode *q = NULL;

	for (int i = 0; i < polylist->length; i++) {
		q = p;
		p = p->link;
		free(q);
	}
}

int main(int argc, char* argv[])
{
	//다항식 생성 및 초기화
	listheader Ax;
	init(&Ax);

	insert_node(&Ax, 1, 3);
	insert_node(&Ax, 2, 1);
	insert_node(&Ax, 6, 0);

	//계산 결과
	printf("%f",poly_eval(&Ax, 3));

	//반환
	allfree(&Ax);

	return 0;
}
