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

	if (polylist->length == 0) {  //�� tail == NULL �� ������ �־�� �ϴ°�??
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

	while (A != NULL || B != NULL) {   //�� head�� NULL �� �Ǿ�� ������ ����....���ݲ� head->link�� NULL�Ǵ� ������ �־��µ� �ƴϿ���.

		if (A->expon > B->expon)
		{
			insert_node(Cx, A->coef, A->expon);
			A = A->link;
		}
		else if (A->expon == B->expon)
		{
			sum = A->coef + B->coef;
			if(sum!=0) insert_node(Cx, sum , A->expon);   //�߿��Ѱ� ������ ����, ����� 0�̸� ���� �������� �ʴ´�.
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
	//���׽� A(x) ����(�ʱ�ȭ �� �Ŀ� ����)
	listheader Ax;
	init(&Ax);
	insert_node(&Ax, 3, 6);
	insert_node(&Ax, 7, 3);
	insert_node(&Ax, -2, 2);
	insert_node(&Ax, -9, 0);

	//���׽� B(x) ����(�ʱ�ȭ �� �Ŀ� ����)
	listheader Bx;
	init(&Bx);
	insert_node(&Bx, -2, 6);
	insert_node(&Bx, -4, 4);
	insert_node(&Bx, 6, 2);
	insert_node(&Bx, 6, 1);
	insert_node(&Bx, 1, 0);

	//���׽� C(x) ����(�ʱ�ȭ �� �Ŀ� ����)
	listheader Cx;
	init(&Cx);

	//���׽� ���
	display(&Ax);
	display(&Bx);

	add_polynomial(&Ax, &Bx, &Cx);
	display(&Cx);
	
	//�޸� ��ȯ
	allfree(&Ax);
	allfree(&Bx);
	allfree(&Cx);

	return 0;
}