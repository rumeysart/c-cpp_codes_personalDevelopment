#ifndef stack_ll
# define stack_ll

typedef struct n
{
	struct n *next;
	int data;
} node;

int pop(node *);
void show (node *root);
node *push(node *, int);

#endif
