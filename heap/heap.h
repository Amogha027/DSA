#ifndef __HEAP_H_
#define __HEAP_H_

// #----------------------------MIN HEAP--------------------------#
struct Heap{
    int size;
    int capacity;
    int *nums;
};

struct Heap *create_heap(int x);
struct Heap *build_heap(int *arr, int n);  // O(n)

void insert(struct Heap *H, int x);        // O(logN)
void delete(struct Heap *H, int idx);      // O(logN)

int extract_min(struct Heap *H);           // O(logN)
int Is_heap_full(struct Heap *H);
int Is_heap_empty(struct Heap *H);

void percolate_down_heap(struct Heap *H, int i);
void percolate_up_heap(struct Heap *H, int i);

void increase_key(struct Heap *H, int idx, int x);
void decrease_heap(struct Heap *H, int idx, int x);

#endif