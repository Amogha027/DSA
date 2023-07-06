#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

struct Stack* create_stack() {
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    assert(s != NULL);
    s->num = 0;
    s->top = NULL;
    return s;
}

struct Node* create_node(int x, int y) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    assert(p != NULL);
    p->val = x;
    p->idx = y;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

int size(struct Stack* s) {
    return s->num;
}

int Is_empty(struct Stack *s) {
    return (s->num == 0);
}

int top(struct Stack* s) {
    return s->top->val;
}

int pop(struct Stack* s) {
    if (s->num > 0) {
        struct Node* p = s->top;
        int n = p->val;
        if (p->next == NULL)
            s->top = NULL;
        else {
            struct Node* temp = p->next;
            temp->prev = NULL;
            s->top = temp;
        }
        (s->num)--;
        return n;
    }
    return -10;
}

void push(struct Stack* s, int x, int y) {
    struct Node* p = create_node(x, y);
    if (s->top != NULL) {
        struct Node* temp = s->top;
        temp->prev = p;
        p->next = temp;
    }
    s->top = p;
    (s->num)++;
}

int idx_top(struct Stack* s) {
    return s->top->idx;
}

void print(struct Stack* s) {
    printf("%d\n", size(s));
    struct Stack* curr = create_stack();
    int k = size(s);
    for (int i = 0; i < k; i++) {
        int t = pop(s);
        push(curr, t, i);
    }

    struct Node* p = curr->top;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    free(curr);
}