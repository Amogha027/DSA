#ifndef __QUEUE_H_
#define __QUEUE_H_

struct Queue {
    int num;
    struct Node* head;
    struct Node* rear;
};

struct Node {
    int val;
    int idx;
    struct Node* next;
    struct Node* prev;
};

struct Queue* create_queue();
struct Node* create_node(int val, int idx);

int size(struct Queue* Q);
int front(struct Queue* Q);
int Is_empty(struct Queue* Q);

void enque(struct Queue* Q, int val, int idx);
int deque(struct Queue* Q);
void print(struct Queue* Q);

#endif