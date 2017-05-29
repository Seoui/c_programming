#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listnode {
	element ndata;
	struct listnode *link;
}listnode;

element delete(listnode *head, listnode *f, element data)
{
	listnode *p = head;
	element temp;

	while (p != NULL)
	{
		if (data == (p->ndata))
		{
			temp = (p->ndata);
			if (f == NULL)
				head = head->link;
			else
				f->link = p->link;
		}
		p = p->link;
	}

	return temp;
}

int main(int argc, char* argv[])
{
	listnode list1, list2, list3;
	listnode *head, *plist2;

	list1.ndata = 10;
	list2.ndata = 20;
	list3.ndata = 30;

	plist2 = &list2;
	head = &list1;
	list1.link = &list2;
	list2.link = &list3;
	list3.link = NULL;

	printf("%d, %d, %d\n", delete(head, plist2, 30), list1.ndata, list2.ndata);

	return 0;
}