#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"
//last in first out

int *arr = NULL;
int size = 2;
int max = 0;

stack *init()
{
	stack *s = (stack *)malloc(sizeof(stack));
	s -> arr = NULL;
	s->size = 2;
	s -> max = 0;
	return (s);
}

int pop(stack *s)
{
	if (s-> max <= 0 || s->arr == NULL)
	{
		printf("array is null");
		return (-1);
	}
	if (s->max <= s->size/4 && s->size > 2)
	{
		int *arr2 = (int *)malloc(sizeof(int) * s->size/2);
		for(int i = 0; i < s->size; i++)
			arr2[i] = s->arr[i];
		free(s->arr);
		s->arr = arr2;
		s->size /= 2;	
	}
	return (s->arr[--s->max]);
}

void push(int a, stack *s)
{
	if (s->arr == NULL)
		s->arr = (int *)malloc(sizeof(int) * 2);
	if (s->max >= s->size - 1)
	{
		int *arr2 = (int *)malloc(sizeof(int)*s->size*2);
		for(int i = 0; i < s->size; i++)
			arr2[i] = s->arr[i];
		int *temp = s ->arr;
		s->arr = arr2;
		free(temp);
		s->size *= 2;
	}
	s->arr[s->max++] = a;
}

void show(stack *s)
{
	printf("size: %d\n", s->size);
	for(int i = 0; i < s->max; i++)
		printf("%d ", s->arr[i]);
}
