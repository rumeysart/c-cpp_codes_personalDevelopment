#include "stack_ll.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
	node *s = NULL;
	s = push(s, 10);
	s = push(s, 20);
	printf("%d -> ", pop(s));
	s = push(s, 30);
/*show(s);
	fflush(stdout);  //o anda hafızada bekleyen şeyler, 
	 //hatadan dolayı bastırılamıyor ise bastırmasını sağlıyor
*/
	printf("%d -> ", pop(s));
	printf("%d -> ", pop(s));
}
