#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct listnode {
	element ndata;
	struct listnode *link;
}listnode;

void display(listnode *r)
{
	listnode *p = r;
	while (p != NULL)
	{
		printf("%d->", p->ndata);
		p = p->link;
	}
	printf("\n");
}

listnode *alternate(listnode *phead, listnode *qhead, listnode *rhead)
{
	listnode *p = phead;
	listnode *q = qhead;
	listnode *r = rhead;
	while (p != NULL || q != NULL)
	{
		r->ndata = p->ndata;
		r = r->link;
		p = p->link;
		r->ndata = q->ndata;
		r = r->link;
		q = q->link;
	}
	for (; p != NULL; p = p->link) {
		r->ndata = p->ndata;
		r = r->link;
	}
	for (; q != NULL; q = q->link) {
		r->ndata = p->ndata;
		r = r->link;
	}

	return rhead;
}

int main(int argc, char* argv[])
{
	listnode p1, p2, p3, p4;
	listnode q1, q2, q3, q4;
	listnode r1, r2, r3, r4, r5, r6, r7, r8;
	listnode *phead =&p1, *qhead=&q1, *rhead=&r1;

	p1.ndata = 1;
	p1.link = &p2;
	p2.ndata = 3;
	p2.link = &p3;
	p3.ndata = 5;
	p3.link = &p4;
	p4.ndata = 7;
	p4.link = NULL;

	q1.ndata = 2;
	q1.link = &q2;
	q2.ndata = 4;
	q2.link = &q3;
	q3.ndata = 6;
	q3.link = &q4;
	q4.ndata = 8;
	q4.link = NULL;

	r1.link = &r2;
	r2.link = &r3;
	r3.link = &r4;
	r4.link = &r5;
	r5.link = &r6;
	r6.link = &r7;
	r7.link = &r8;
	r8.link = NULL;
	
	display(alternate(phead, qhead, rhead));
	
	return 0;
}