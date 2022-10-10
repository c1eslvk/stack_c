#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACKSTEP 2

typedef struct {
	int* items;
	int top;
} Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int element);
int pop(Stack* s);
bool is_empty(Stack* s);
int main();

void init(Stack* s)
{
	s->items = malloc(sizeof(int) * STACKSTEP);
	s->top = -1;
}

bool is_empty(Stack* s)
{
	if (s->top <= 0) {
		return true;
	}
	else {
		return false;
	}
}

void push(Stack* s, int element)
{
	static int counter = 1;
	s->top++;
	if (s->top == STACKSTEP * counter) {
		counter++;
		s->items = realloc(s->items, sizeof(int) * STACKSTEP * counter);
	}
	s->items[s->top] = element;
}

int pop(Stack* s)
{
	int popped_element;
	if (is_empty(s) == true) {
		printf("Stack is empty");
		abort();
	}
	else {
		popped_element = s->items[s->top];
		s->top--;
		return popped_element;
	}
}

void destroy(Stack* s)
{
	s->top = -1;
	free(s->items);
}

int main()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	init(s);

	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	push(s, 5);

	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));

	destroy(s);
	free(s);

	return 0;
}
