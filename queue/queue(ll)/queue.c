#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

struct Queue* create_queue() {
    struct Queue* Q = (struct Queue*)malloc(sizeof(struct Queue));
    assert(Q != NULL);
    Q->num = 0;
    Q->head = NULL;
    Q->rear = NULL;
    return Q;
}

struct Node* create_node(int val, int idx) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    assert(p != NULL);
    p->val = val;
    p->idx = idx;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

int size(struct Queue* Q) {
    return Q->num;
}

int Is_empty(struct Queue* Q) {
    return (Q->num == 0);
}

int front(struct Queue* Q) {
    return Q->head->val;
}

int deque(struct Queue* Q) {
    struct Node* p = Q->head;
    int n = p->val;
    if (Q->num > 1) {
        struct Node* temp = p->next;
        temp->prev = NULL;
        Q->head = temp;
    } else Q->head = NULL;
    free(p);
    (Q->num)--;
    return n;
}

void enque(struct Queue* Q, int val, int idx) {
    struct Node* p = create_node(val, idx);
    if (Q->rear == NULL) Q->head = p;
    else {
        struct Node* temp = Q->rear;
        temp->next = p;
        p->prev = temp;
    }
    Q->rear = p;
    (Q->num)++;
}

void print(struct Queue* Q) {
    struct Node* p = Q->head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}