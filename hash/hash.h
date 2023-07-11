#ifndef __HASH_H_
#define __HASH_H_

// separate chaining implementation (using linked list)
struct HashTable {
    int length;
    struct Node** arr;
};

struct Node {
    int num;
    struct Node* next;
};

struct HashTable* create_table(int x);
void Delete_table(struct HashTable* T);
void Empty_table(struct HashTable* T);

void Insert(struct HashTable* T, int x);
void Delete(struct HashTable* T, int x);

struct Node* Find(struct HashTable* T, int x);
int getHash(struct HashTable* T, int x);

#endif