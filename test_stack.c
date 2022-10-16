#include "stack.h"
#include <stdio.h>

int main()
{
	Stack s1, s2;
	init(&s1);
	init(&s2);

	push(&s1, 1);
	push(&s1, 2);
	push(&s1, 3);
	push(&s1, 4);

	push(&s2, 4);
	push(&s2, 5);
	push(&s2, 6);
	push(&s2, 7);

	printf("stack 1\n");
	printf("%d\n", pop(&s1));
	printf("%d\n", pop(&s1));
	printf("%d\n", pop(&s1));

	printf("\nstack 2\n");
	printf("%d\n", pop(&s2));
	printf("%d\n", pop(&s2));
	printf("%d\n", pop(&s2));

	destroy(&s1);
	destroy(&s2);

	return 0;
}
