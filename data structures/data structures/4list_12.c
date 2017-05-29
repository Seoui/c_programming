#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int element;
typedef struct arrlist {
	element list[MAX_SIZE];
	int length;
}arrlist;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(arrlist *L)
{
	L->length = 0;
}

int is_empty(arrlist *L)
{
	return L->length == 0;
}

int is_full(arrlist *L)
{
	return L->length == MAX_SIZE;
}

void add(arrlist *L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->length))
	{
		for (int i = (L->length - 1); i >= pos; i--)
			L->list[i + 1] = L->list[i];
		L->list[pos] = item;
		L->length++;
	}
}

element st_delete(arrlist *L, int pos)
{
	int i;
	element item;

	if (pos < 0 || pos >= L->length)
		error("위치 오류");
	item = L->list[pos];
	for (i = pos; i < (L->length - 1); i++)
		L->list[i] = L->list[i + 1];
	L->length-- ;

	return item;
}

void clear(arrlist *L)
{
	L->list[MAX_SIZE] = 0;
	L->length = 0;
}

element replace(arrlist *L, int pos, element item)
{
	element temp;
	temp = L->list[pos];
	L->list[pos] = item;

	return temp;
}

int is_in_list(arrlist *L, element item)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (L->list[i] == item)
			return 1;
	}
	return 0;
}

element get_entry(arrlist *L, int pos)
{
	return L->list[pos];
}

int get_length(arrlist *L)
{
	return L->length;
}

void display(arrlist *L)
{
	for (int i = 0; i < L->length; i++)
		printf("%d\n", L->list[i]);
}

int main(int argc, char* argv[])
{
	arrlist list1;

	init(&list1);
	add(&list1, 0, 10);
	add(&list1, 0, 20);
	printf("%d\n",get_length(&list1));
	printf("%d\n", is_in_list(&list1, 10));
	replace(&list1, 1, 50);
	display(&list1);

	return 0;
}