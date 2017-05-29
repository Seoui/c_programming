#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct stacklist {
	element item;
	struct stacklist* link;
}stacklist;

typedef struct top {
	stacklist* link;
}top;

void init(top *top)
{
	top->link = NULL;
}

int size(top *toplink)
{
	int count = 1;
	stacklist *top = toplink->link;
	while (top->link != NULL) {
		++count;
		top = top->link;
	}
	
	return count;
}

void push(element item, top* top)
{
	stacklist *temp = (stacklist *)malloc(sizeof(stacklist));
	temp->item = item;
	temp->link = top->link;
	top->link = temp;
}

void allfree(top* top)
{
	stacklist *p = top->link;
	stacklist *q = NULL;

	do{
		q = p;
		p = p->link;
		free(q);
	} while (q = NULL);
}

int main(int argc, char* argv[])
{
	top a;
	init(&a);
	push(1, &a);
	push(2, &a);
	push(3, &a);

	printf("%d\n\n",size(&a));

	allfree(&a);

	return 0;
}