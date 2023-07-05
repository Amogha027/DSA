#ifndef __DLL_H_
#define __DLL_H_

struct Node {
    int val; // an integer
    struct Node* prev; // pointer to the previous node
    struct Node* next; // pointer to the next node
};

struct dll {
    struct Node* head; // pointer to the first node
    struct Node* tail; // pointer to the last node
};

struct dll* create_dll();                // create a new double linked list
struct Node* create_node(int x);         // create a new node

void Insert_end(struct dll* d, int x);   // insert x at the end
void Insert_front(struct dll* d, int x); // insert x at position i
void Delete(struct dll* d, int i);       // delete at position i
int Find(struct dll* d, int x);          // return the position of first occurence of x, else return -1

void Print(struct dll* d);               // print the linked list from index 0
void Print_reverse(struct dll* d);       // print the linked list in reverse order
int Size(struct dll* d);                 // return the no of elements in the linked list

#endif