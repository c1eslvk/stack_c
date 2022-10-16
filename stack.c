#include "stack.h"
#include <stdio.h>

void init(Stack* s)
{
	s->items = malloc(sizeof(int) * STACK_STEP);
	if(s->items == NULL) abort();
	s->top = -1;
	s->size = 1;
}

bool is_empty(Stack* s)
{
	if (s->top <= -1) {
		return true;
	}
	else {
		return false;
	}
}

void push(Stack* s, int element)
{
	s->top++;
	if (s->top == STACK_STEP * s->size) {
		s->size++;
		s->items = realloc(s->items, sizeof(int) * STACK_STEP * s->size);
		if(s->items == NULL) abort();
	}
	s->items[s->top] = element;
}

int pop(Stack* s)
{
	if (is_empty(s) == true) {
		printf("Stack is empty");
		abort();
	}
	else {
		int popped_element = s->items[s->top];
		s->top--;
		return popped_element;
	}
}

void destroy(Stack* s)
{
	free(s->items);
}
