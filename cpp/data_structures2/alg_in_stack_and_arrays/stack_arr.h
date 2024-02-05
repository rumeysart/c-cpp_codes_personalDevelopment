#ifndef STACK_ARR_H
# define STACK_ARR_H

typedef struct s
{
	int size;
	int max;
	int *arr;
} stack;

stack *init();
int pop(stack *s);
void push(int a, stack *s);
void show(stack *s);

#endif
