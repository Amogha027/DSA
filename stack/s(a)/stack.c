#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct stack init_stack(unsigned int x) {
	struct stack S = (struct stack)malloc(sizeof(struct stack));
	assert(S != NULL);
	S->items = (int*)malloc(sizeof(int)*x);
	S->n = x;
	S->top = -1;
}

int Is_full(struct stack S) {
	return (S->top == (S->n)-1)
}

int Is_empty(struct stack S) {
	return (S->top == -1)
}

void push(struct stack S, int e) {
	if(!Is_full) S->items[++S->top] = e;
}

void pop(struct stack S) {
	if(!Is_empty) --S->top;
}

int top(struct stack S) {
	if(!Is_empty) return S->items[S->top];
}