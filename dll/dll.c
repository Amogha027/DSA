#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct dll* create_dll() {
    struct dll* d = (struct dll*)malloc(sizeof(struct dll));
    assert(d != NULL);

    d->head = NULL;
    d->tail = NULL;
    return d;
}

struct Node* create_node(int x) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    assert(p != NULL);
    p->val = x;
    p->prev = p->next = NULL;
    return p;
}

void Insert_end(struct dll* d, int x) {
    struct Node* p = create_node(x);
    // when the linked list is empty
    if (d->head == NULL)
        d->head = d->tail = p;
    else {
        struct Node* temp = d->tail;
        p->prev = temp;
        temp->next = p;
        d->tail = p;
    }
}

void Insert_front(struct dll* d, int x) {
    struct Node* p = create_node(x);
    // when the linked list is empty
    if (d->head == NULL)
        d->head = d->tail = p;
    else {
        struct Node* temp = d->head;
        temp->prev = p;
        p->next = temp;
        d->head = p;
    }
}

void Delete(struct dll* d, int i) {
    int k = size(d);
    if (i >= k) // out of range
        printf("Invalid Index\n");
    else {
        struct Node* p = d->head;
        // when the position is 0
        if (i == 0) {
            // only 1 element in linked list
            if (p->next == NULL) 
                d->head = d->tail = NULL;
            else {
                struct Node* temp = p->next;
                temp->prev = NULL;
                d->head = temp;
            }
            free(p);
        } else {
            int n = 1;
            while (n < i) {
                p = p->next;
                n++;
            }

            struct Node* del = p->next;
            // if last element is deleted
            if (del->next == NULL) {
                p->next = NULL;
                d->tail = p;
            } else {
                struct Node* temp = del->next;
                p->next = temp;
                temp->prev = p;
            }
            free(del);
        }
    }
}

int Find(struct dll* d, int x)
{
    int i = 0;
    struct Node* p = d->head;
    while (p != NULL) {
        if (p->val == x) return i;
        p = p->next;
        i++;
    }
    return -1;
}

int Size(struct dll* d) {
    int n = 0;
    struct Node* p = d->head;
    while (p != NULL) {
        n++;
        p = p->next;
    }
    return n;
}

void Print(struct dll* d) {
    struct Node* p = d->head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

void Print_reverse(struct dll* d) {
    struct Node* p = d->tail;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->prev;
    }
    printf("\n");
}