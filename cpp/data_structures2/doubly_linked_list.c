#include <stdio.h>
#include <stdlib.h>
//LESSON_6
//doubly linked list; add, delete, sort
typedef struct n
{
	int x;
	struct n *next;
	struct n *prev;
}  node;

void show(node *r)
{
	node *iter = r;
	printf("%d ", iter ->x);
	iter = iter->next;
	while (iter != r)
	{
		printf("%d ", iter -> x);
		iter = iter ->next;
	}
	printf("\n");
}

node *add_sort(node *r, int x)
{
	if (r == NULL) //linked_list'imiz boşsa
	{
		r = (node *)malloc(sizeof(node));
		r ->next = NULL;
		r ->prev = NULL;
		r -> x = x;
		return (r);
	}
	if (r -> x > x) //ilk elemandan küçük durumu
	{				//root değişiyor
		node *temp = (node *)malloc(sizeof(node));
		temp -> x = x;
		temp -> next = r;
		r ->prev = temp;
		return (temp);
	}
	node *iter = r;
	while ( iter-> next != NULL && iter -> next -> x < x)
		iter = iter ->next;
	node *temp = (node *)malloc(sizeof(node));
	temp ->next = iter ->next;
	iter ->next = temp;
	temp ->prev = iter;
	if (temp ->next != NULL)
		temp ->next->prev = temp;
	temp ->x = x;
	return (r);
}

node *del(node *r, int x) //amacımız x değerini linked_list'ten silmek
{
	node *temp;
	node *iter = r;
	if (r -> x == x)
	{
		temp = r;
		r = r->next;
		free(temp);
		return (r);
	}
	while (iter ->next != NULL && iter ->next ->x != x)
		iter = iter ->next;
	if (iter ->next == NULL)
	{
		printf("can't find number\n");
		return (r);
	}
	temp = iter ->next;
	iter ->next = iter ->next ->next;
	free(temp);
	if (iter ->next != NULL)
		iter ->next ->prev = iter;
	return (r);
}

int main()
{
	node *root;
	root = NULL;
	root = add_sort(root, 400);
	root = add_sort(root, 40);
	root = add_sort(root, 4);
	root = add_sort(root, 450);
	root = add_sort(root, 50);
	show(root);
	root = del(root, 50);
	root = del(root, 999);
	root = del(root, 4);
	root = del(root, 450);
	show(root);
	add(root, 197);
	show(root);
}
