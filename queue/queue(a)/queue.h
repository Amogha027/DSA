#ifndef __QUEUE_H_
#define __QUEUE_H_

// array implementation of the queue
struct Queue {
	size_t capacity; // total size of the queue
	int front; // front element of the queue (oldest)
	int rear; // back element of the queue (latest)
	int num; // number of elements in the queue
	int *arr; // elts of the queue stored in array
};

struct Queue* create_queue(size_t n);
void enque(struct Queue* Q, int x);
int deque(struct Queue* Q);

int Is_empty(struct Queue* S);
int Is_full(struct Queue* S);
void print_que(struct Queue* Q);
int first_term(struct Queue* Q);

void clear_queue(struct Queue* Q);
void delete_queue(struct Queue* P);


#endif