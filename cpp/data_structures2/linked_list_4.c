#include <stdio.h>
#include <stdlib.h>
//LESSON_4
//Deleting an Element from a Linked List
typedef struct n{
	int x;
	struct n *next;
}  node;

void show(node *r)
{
	while (r != NULL)
	{
		printf("%d ", r -> x);
		r = r ->next;
	}
	printf("\n");
}

void add(node *r, int x)
{
	while (r -> next)
	{
		r = r ->next;
	}
	r ->next = (node *)malloc(sizeof(node));
	r -> next ->x = x;
	r ->next ->next = NULL;
}

node *add_sort(node *r, int x)
{
	if (r == NULL) //linked_list'imiz boşsa
	{
		r = (node *)malloc(sizeof(node));
		r ->next = NULL;
		r -> x = x;
		return (r);
	}
	if (r -> x > x) //ilk elemandan küçük durumu
	{				//root değişiyor
		node *temp = (node *)malloc(sizeof(node));
		temp -> x = x;
		temp -> next = r;
		return (temp);
	}
	node *iter = r;
	while ( iter-> next != NULL && iter -> next -> x < x)
	{
		iter = iter ->next;
	}
	node *temp = (node *)malloc(sizeof(node));
	temp ->next = iter ->next;
	iter ->next = temp;
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
		printf("can't find number");
		return (r);
	}
	temp = iter ->next;
	iter ->next = iter ->next ->next;
	free(temp);
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
	show(root);
	root = del(root, 999);
	root = del(root, 4);
	root = del(root, 400);
	show(root);
}
