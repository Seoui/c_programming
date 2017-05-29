#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct listnode {
	element ndata;
	struct listnode *link;
}listnode;



void insertnode_last(listnode **phead, listnode *new, int nodecount)
{
	listnode *p = *phead;

	if (*phead == NULL) {
		*phead = new;
		new->link = NULL;
	}
	else {
		for (int i = 0; i < nodecount-1; i++)
		{
			p = p->link;
		}
		p->link = new;
	}
}

int nodecount(listnode *head)
{
	int count = 0;
	listnode *p = head;
	while (p!= NULL)
	{
		count = count +1;
		p = p->link;
	}

	return count;
}

listnode *createnode(element item, listnode *link)
{
	listnode *new_node;
	new_node = (listnode *)malloc(sizeof(listnode));
	new_node->ndata = item;
	new_node->link = link;
	
	return (new_node);
}

void insertnode(listnode **phead, listnode *p, listnode *new)
{
	if (*phead == NULL) {
		new->link = NULL;
		*phead = new;
	}
	else if (p == NULL) {
		new->link = *phead;
		*phead = new;
	}
	else {
		new->link = p->link;
		p->link = new;
	}
}

void display(listnode *head)
{
	listnode *p = head;
	while(p!=NULL)
	{
		printf("%d->", p->ndata);
		p = p->link;
	}
	printf("\n\n");
}

void allfree(listnode *head, int countnode)
{
	listnode *p = head;
	listnode *q = NULL;
	for (int i = 0; i < countnode; i++)
	{
		q = p;
		p = p->link;
		free(q);
	}
}

void split(listnode *a1, listnode *b1, listnode *c1, int nodecount)
{
	listnode *c = c1;
	listnode *a = a1;
	listnode *b = b1;
	int flag = 1;
	for (int i=0; i<nodecount ;i++)
	{
		if (flag == 1) {
			insertnode(&a,NULL,createnode(c->ndata, NULL));  //nodecount 는 a리스트와 b리스트의 노드의 갯수 만큼 줘야 할듯
			c = c->link;                                                    
		}
		else {
			insertnode(&b, NULL, createnode(c->ndata, NULL));
			c = c->link;
		}
		flag = -flag;
	}
}
//참고로 insernode 함수는 올바르게 작동한다 , 하지만 반환값을 void로 하여 메인함수에 즉시 출력하니 에러가 뜸...
//반환값을 *a 로 주어서 메인함수에서 출력하면 올바르게 뜬다.
//생각해서 다시 작성해볼 것 거즌 다옴
//그리고 insernode_last 함수 다시한번 확인 해보는 것도 좋겠다.
int main(int argc, char* argv[])
{
	listnode *a1=NULL, *b1=NULL, *c1=NULL;

	insertnode(&c1, NULL, createnode(1, NULL));
	insertnode(&c1, NULL, createnode(2, NULL));
	insertnode(&c1, NULL, createnode(3, NULL));
	insertnode(&c1, NULL, createnode(4, NULL));
	insertnode_last(&c1, createnode(5, NULL),nodecount(c1));
	display(c1);
	
	split(a1, b1, c1, nodecount(c1));
	display(a1);
	display(b1);
	display(c1);

	allfree(c1, nodecount(c1));
	allfree(a1, nodecount(a1));
	allfree(b1, nodecount(b1));
	
	return 0;
}
