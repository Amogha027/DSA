#include "sll.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node* init_node(int X) {
	struct Node* T;
	T = (struct Node*)malloc(sizeof(struct Node));
	assert(T != NULL);

	T->num = X;
	T->next = NULL;
	return T;
}

struct Node* init_list() {
	struct Node* T = init_node(-1);
	return T;
}

void Insert_start(struct Node* L, int X) {
	struct Node* T = init_node(X);
	assert(T != NULL);
	T->next = L->next;
	L->next = T;
}

void Insert_end(struct Node* L, int X) {
	struct Node* T = init_node(X);
	assert(T != NULL);
	while (L->next != NULL) L = L->next;
	L->next = T;
}

int Insert_pos(struct Node* L, int X, int pos) {
	struct Node* A = init_node(X);
	assert(A != NULL);
	for (int i = 1; i < pos; i++) {
		L = L->next;
		if (L == NULL) return 0;
	}
	A->next = L->next;
	L->next = A;
	return 1;
}

void Delete_start(struct Node* L) {
	struct Node* T = L->next;
	if (T != NULL) {
		L->next = T->next;
		free(T);
	}
	return L;
}

void Delete_end(struct Node* L) {
	struct Node* prev = L;
	struct Node* curr = L->next;
	if (curr != NULL) {
		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = NULL;
		free(curr);
	}
	return L;
}

int Delete_pos(struct Node* L, int pos) {
	struct Node* prev = L;
	struct Node* curr = L->next;
	for (int i = 1; i < pos; i++) {
		prev = curr;
		curr = curr->next;
		if (curr == NULL) return 0;
	}
	prev->next = curr->next;
	free(curr);
	return 1;
}

void Print(const struct Node* L) {
	struct Node* T = L->next;
	while(T != NULL) {
		printf("%d\n", T->num);
		T = T->next;
	}
}