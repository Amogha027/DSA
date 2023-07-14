#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "heap.h"

// #----------------------------MIN HEAP--------------------------#

struct Heap *create_heap(int x) {
    struct Heap *H = (struct Heap *)malloc(sizeof(struct Heap));
    assert(H != NULL);

    H->nums = (int *)malloc(sizeof(int)*(1+x));
    assert(H->nums != NULL);

    H->capacity = 1+x;
    H->size = 0;
    H->nums[0] = -1234;
    return H;
}

int Is_heap_full(struct Heap *H) {
    return H->size == H->capacity-1;
}

int Is_heap_empty(struct Heap *H) {
    return H->size == 0;
}

void insert(struct Heap *H, int x) {
    if (!Is_heap_full(H)) return;
    int i = H->size+1;
    while (H->nums[i/2] > x) {
        H->nums[i] = H->nums[i/2];
        i /= 2;
    }
    H->nums[i] = x;
}

int extract_min(struct Heap *H) {
    if (Is_heap_empty(H)) return -1234;
    int child, min = H->nums[1];
    int i, last = H->nums[H->size--];
    for (i = 1; 2*i <= H->size; i = child) {
        child = 2*i;
        if ((child != H->size) && (H->nums[child+1] < H->nums[child]))
            child++;

        if (last > H->nums[child]) H->nums[i] = H->nums[child];
        else break;
    }
    H->nums[i] = last;
    return min;
}

void percolate_down_heap(struct Heap *H, int i) {
    if (H->size > 2*i) {
        int child = 2*i;
        if (H->nums[child] > H->nums[child+1])
            child++;

        if (H->nums[child] < H->nums[i]) {
            int temp = H->nums[child];
            H->nums[child] = H->nums[i];
            H->nums[i] = temp;
        }
        percolate_down_heap(H, child);
    }
    else if (H->size == 2*i) {
        if (H->nums[2*i] < H->nums[i]) {
            int temp = H->nums[i];
            H->nums[i] = H->nums[2*i];
            H->nums[2*i] = temp;
        }
    }
}

void percolate_up_heap(struct Heap *H, int i) {
    if (i == 1)
        return;
    int child = i/2;
    if (H->nums[child] > H->nums[i]) {
        int temp = H->nums[child];
        H->nums[child] = H->nums[i];
        H->nums[i] = temp;
        percolate_up_heap(H, child);
    }
}

struct Heap *build_heap(int *arr, int n) {
    int i;
    struct Heap *H = create_heap(n);
    // memcpy(H->nums, arr, n * sizeof(int));
    for (int i = 0; i < n; i++)
        H->nums[i+1] = arr[i];
    H->size = n;

    for (i = n/2; i > 0; i--)
        percolate_down_heap(H, i);
    return H;
}

void increase_key(struct Heap *H, int idx, int x) {
    if (idx == 0 || idx > H->size)
        return;

    H->nums[idx] += x;
    percolate_down_heap(H, idx);
}

void decrease_heap(struct Heap *H, int idx, int x) {
    if (idx == 0 || idx > H->size)
        return;

    H->nums[idx] -= x;
    percolate_up_heap(H, idx);
}

void delete(struct Heap *H, int idx) {
    if (idx == 0 || idx > H->size)
        return;

    int i, child, last = H->nums[H->size--];
    for (i = idx; 2*i < H->size; i = child) {
        child = 2*i;
        if ((child != H->size) && (H->nums[child+1] < H->nums[child]))
            child++;

        if (last > H->nums[child])
            H->nums[i] = H->nums[child];
        else
            break;
    }
    H->nums[i] = last;
}