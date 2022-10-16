#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_STEP 2

typedef struct {
	int* items;
	int top;
	int size;
} Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int element);
int pop(Stack* s);
bool is_empty(Stack* s);
