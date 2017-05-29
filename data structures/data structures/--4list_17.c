#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listnode {
	element ndata;
	struct listnode *link;
}listnode;


void error(char *message)
{
	fprintf(stderr,"%s\n", message);
	exit(1);
}

void insert_node(listnode **phead, listnode *p, listnode *new_node)
{
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node(listnode **phead, listnode *p, listnode *removed)
{
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}

void display(listnode *head)
{
	listnode *p = head;
	while (p != NULL)
	{
		printf("%d->", p->ndata);
		p = p->link;
	}
	printf("\n");
}

listnode *search(listnode *head, int x)
{
	listnode *p;
	p = head;
	while (p != NULL) {
		if (p->ndata == x) return p;
		p = p->link;
	}
	return p;
}

listnode *concat(listnode *head1, listnode *head2)
{
	listnode *p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

listnode *reverse(listnode *head)
{
	listnode *p, *q, *r;
	p = head;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	return q;
}

listnode *delete(listnode *head)
{
	listnode *p = head;
	p = head->link;
	head = head->link;
	while (p != NULL) {

		p->link = p->link->link;
		p = p->link;
	}

	return head;
}

int main(int argc, char* argv[])
{
	listnode list1, list2, list3,list4;
	listnode *head = &list1;

	list1.ndata = 10;
	list2.ndata = 20;
	list3.ndata = 30;
	list4.ndata = 40;

	list1.link = &list2;
	list2.link = &list3;
	list3.link = &list4;
	list4.link = NULL;

	
	display(delete(head));

	return 0;
}