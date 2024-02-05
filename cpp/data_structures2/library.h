#ifndef LIBRARY_H
# define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
	int x;
	struct n *next;
	struct n *prev;
}  node;

void show(node *r);
void add(node *r, int x);
node *add_sort(node *r, int x);
node *del(node *r, int x);

#endif
