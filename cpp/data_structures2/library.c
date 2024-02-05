#include <stdio.h>
#include <stdlib.h>
//LESSON_7
//my library header (.h) files in C_1
#include "library.h"

void show(node *r)
{
	while (r != NULL)
	{
		printf("%d ", r -> x);
		r = r ->next;
	}
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
}
