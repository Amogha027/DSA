#ifndef __STACK_H_
#define __STACK_H_

// linked list implementation of stack
struct Stack {
    unsigned int num;
    struct Node* top;
};

struct Node{
    int val;
    int idx;
    struct Node* next;
    struct Node* prev;
};

struct Stack* create_stack();
struct Node* create_node(int x, int y);

int size(struct Stack* s);
int Is_empty(struct Stack* s);
int top(struct Stack* s);

int pop(struct Stack* s);
void push(struct Stack* s, int x, int y);

void print(struct Stack* s);
int idx_top(struct Stack* s);

#endif