#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listnode {
	element ndata;
	struct listnode *link;
}listnode;

int countdata(listnode *head, element data)
{
	listnode *p = head;
	int count = 0;
	
	while (p != NULL)
	{
		if (data == p->ndata)
			count++;
		p = p->link;
	}

	return count;
}

int main(int argc, char* argv[])
{
	listnode list1, list2, list3;
	listnode *head;

	list1.ndata = 10;
	list2.ndata = 30;
	list3.ndata = 10;

	head = &list1;
	list1.link = &list2;
	list2.link = &list3;
	list3.link = NULL;

	printf("%d\n", countdata(head, 10));

	return 0;
}