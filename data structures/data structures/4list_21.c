#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listnode {
	element ndata;
	struct listnode *link;
}listnode;

void display(listnode *head)
{
	listnode *p = head;
	for(int i=0; i <3;i++)
	{
		printf("%d->", p->ndata);
		p = p->link;
	}
	printf("\n");
}


listnode *remove_node2(listnode *x)
{
	listnode *y = x->link;
	x->ndata = y->ndata;
	x->link = y->link;

	return x;
}

int main(int argc, char* argv[])
{
	listnode p1, p2, p3;
	listnode *x = &p1;

	p1.ndata = 1;
	p2.ndata = 2;
	p3.ndata = 3;

	p1.link = &p2;
	p2.link = &p3;
	p3.link = &p1;

	display(remove_node2(x));
}