#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

struct Queue* create_queue(size_t n) {
	struct Queue* Q;
	Q = (struct Queue*)malloc(sizeof(struct Queue));
	assert(Q != NULL);
	Q->capacity = n;
	Q->arr = (int *)malloc(sizeof(int)*n);
	assert(Q->arr != NULL);
	Q->front = 0;
	Q->rear = -1;
	Q->num = 0;
	return Q;
}

int Is_empty(struct Queue* S) {
	return (S->num == 0);
}

int Is_full(struct Queue* S) {
	return (s->num == s->capacity);
}

void enque(struct Queue* Q, int x) {
	if (!Is_full(Q)) {
		(Q->rear) = (Q->rear+1) % (Q->capacity);
		Q->arr[Q->rear] = x;
		(Q->num)++;
	}
}

int deque(struct Queue* Q) {
	if (!Is_empty(Q)) {
		int x = Q->arr[Q->front];
		Q->front = (Q->front+1) % (Q->capacity);
		(Q->num)--;
		return x;
	}
	return -1;
}

int first_term(struct Queue* Q) {
	return Q->arr[Q->front];
}

void clear_queue(struct Queue* Q) {
	Q->num = 0;
	Q->front = 0;
	Q->rear = -1;
}

void delete_queue(struct Queue* P) {
	struct Queue* Q = *p;
	free(Q->arr);
	free(Q);
	*P = NULL;
}

void print_que(struct Queue* Q) {
	if (Q->num == 0) return;
	int i = Q->front, n = Q->num;
	while (n--) {
		printf("%d ", Q->arr[i]);
		i++;
		i %= (Q->capacity);
	}
	printf("\n");
}
