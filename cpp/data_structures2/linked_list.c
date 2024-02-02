#include <stdio.h>
#include <stdlib.h>
//LESSON_1
typedef struct n{
	int x;
	struct n *next;
}  node;

int main()
{
	node *root;
	root = (node *)malloc(sizeof(node));
	root -> x = 10;
	root -> next = (node *)malloc(sizeof(node));
	root -> next -> x = 20;
	root -> next -> next = (node *) malloc (sizeof(node));
	root -> next -> next -> x = 30;
	node * iter;
	iter = root;
	printf("%d\n", iter -> x);
	iter = iter -> next;
	printf("%d", iter->x);
}


