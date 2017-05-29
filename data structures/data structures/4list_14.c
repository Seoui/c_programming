#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listnode {
	element ndata;
	struct listnode *link;
}listnode;

element sum(listnode *head)
{
	listnode *p = head;
	element sum1 =0;
	while (p != NULL)
	{
		sum1 = sum1 + (p->ndata);
		p = p->link;
	}

	return sum1;
}

int main(int argc, char* argv[])
{
	listnode list1, list2, list3;
	listnode *head;

	list1.ndata = 5;
	list2.ndata = 10;
	list3.ndata = 15;

	head = &list1;
	list1.link = &list2;
	list2.link = &list3;
	list3.link = NULL;


	printf("%d\n", sum(head));
	
	return 0;
}