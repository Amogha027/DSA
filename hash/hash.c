#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash.h"

struct HashTable* create_table(int x) {
    struct HashTable* T = (struct HashTable*)malloc(sizeof(struct HashTable));
    assert(T != NULL);
    T->length = x;

    T->arr = (struct Node *)malloc(x * sizeof(struct Node));
    assert(T->arr != NULL);
    for (int i = 0; i < T->length; i++) {
        T->arr[i] = (struct Node *)malloc(sizeof(struct Node));
        (T->arr[i])->next = NULL;
        (T->arr[i])->num = -1234;
    }
    return T;
}

void Insert(struct HashTable* T, int x) {
    struct Node* P = Find(T, x);
    if (P == NULL) {
        int key = getHash(T, x);
        P = (struct Node *)malloc(sizeof(struct Node));
        assert(P != NULL);
        P->num = x;
        P->next = (T->arr[key])->next;
        (T->arr[key])->next = P;
    }
}

void Delete(struct HashTable* T, int x) {
    int key = getHash(T, x);
    struct Node *curr, *del;
    curr = T->arr[key];
    while (curr != NULL) {
        if ((curr->next != NULL) && (curr->next->num == x)) {
            del = curr->next;
            curr->next = del->next;
            free(del);
            return;
        }
        curr = curr->next;
    }
}

void Empty_table(struct HashTable* T) {
    for (int i = 0; i < T->length; i++) {
        struct Node* curr = T->Arr[i];
        while (curr->next != NULL) {
            struct Node* del = curr->next;
            curr->next = del->next;
            free(del);
        }
    }
}

void Delete_table(struct HashTable* T) {
    Empty_table(T);
    for (int i = 0; i < T->length; i++)
        free(T->arr[i]);
    free(T);
}

struct Node* Find(struct HashTable* T, int x) {
    int key = getHash(T, x);
    struct Node *P = T->arr[key]->next;
    while (P != NULL) {
        if (P->num == n)
            return P;
        P = P->next;
    }
    return NULL;
}

int getHash(struct HashTable* T, int x) {
    int a = 5, b = 3, p = 13;
    int key = (a*x + b) % p;
    return key;
}