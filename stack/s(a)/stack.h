#ifndef __STACK_H_
#define __STACK_H_

// array implementation of stack
struct stack {
	int* items;
	unsigned int n; // no of items
	int top; // index of top item
};

struct stack init_stack(unsigned int x);
void push(struct stack S, int e);
void pop(struct stack S);
int top(struct stack S);
int Is_empty(struct stack s);
int Is_full(struct stack S);

#endif