#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

int main()
{
	stack *s1 = init();
	stack *s2 = init();
	for (int i = 0; i < 10; i++)
		push(i * 10, s1);
	show(s1);
	for(int i = 0; i < 10; i++)
		push(pop(s1), s2);
	show(s1);
	printf("\n");
	show(s2);
}
