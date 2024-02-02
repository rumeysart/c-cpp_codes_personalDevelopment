#include <stdio.h>
#include <stdlib.h>
//LESSON_2
//access with function and loop
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

int main()
{
	node *root;
	root = (node *)malloc(sizeof(node));
	root ->next = NULL;
	root -> x = 500;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		add(root, i * 10);
	}
	show(root);
}


