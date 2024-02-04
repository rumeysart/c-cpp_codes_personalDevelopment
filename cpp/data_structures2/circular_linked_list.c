#include <stdio.h>
#include <stdlib.h>
//LESSON_5
//circular linked list; add, delete, sort
typedef struct n{
	int x;
	struct n *next;
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

void add(node *r, int x) //sona eleman ekleme fonksiyonu
{
	node *iter = r;
	while (iter -> next != r)
	{
		iter = iter ->next;
	}
	iter ->next = (node *)malloc(sizeof(node));
	iter -> next ->x = x;
	iter ->next ->next = r;
}

node *add_sort(node *r, int x)
{
	if (r == NULL) //linked_list'imiz boşsa
	{
		r = (node *)malloc(sizeof(node));
		r ->next = r;
		r -> x = x;
		return (r);
	}
	if (r -> x > x) //ilk elemandan küçük durumu
	{				//root değişiyor
		node *temp = (node *)malloc(sizeof(node));
		temp -> x = x;
		temp -> next = r;
		node *iter =  r;
		while (iter ->next != r)
			iter = iter ->next;
		iter ->next = temp;
		return (temp);
	}
	node *iter = r;
	while ( iter-> next != r && iter -> next -> x < x)
		iter = iter ->next;
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
		while (iter ->next != r)
			iter = iter -> next;
		iter ->next = r->next;
		free(r);
		return (iter ->next);
	}
	while (iter ->next != r && iter ->next ->x != x)
		iter = iter ->next;
	if (iter ->next == r)
	{
		printf("can't find number\n");
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
	root = del(root, 999);
	root = del(root, 4);
	root = del(root, 450);
	show(root);
	add(root, 197);
	show(root);
}
