#include <stdio.h>
#include <stdlib.h>

#define ll long long
typedef struct {
    ll val;
    int r; // row index
    int c; // column index
} Tuple;

typedef struct {
    Tuple* array;
    int size;
    int capacity;
} MinHeap;

MinHeap* makeHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->array = (Tuple*)malloc(sizeof(Tuple) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(Tuple* a, Tuple* b) {
    Tuple tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify_up(MinHeap* heap, int el) {
    if (el == 0) return;
    int parent = (el - 1) / 2;
    if (heap->array[parent].val > heap->array[el].val) {
        swap(&heap->array[el], &heap->array[parent]);
        heapify_up(heap, parent);
    }
}

void heapify_down(MinHeap* heap, int el) {
    int left = 2 * el + 1;
    int right = 2 * el + 2;
    int smallest = el;

    if (left < heap->size && heap->array[left].val < heap->array[smallest].val) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right].val < heap->array[smallest].val) {
        smallest = right;
    }
    if (smallest != el) {
        swap(&heap->array[smallest], &heap->array[el]);
        heapify_down(heap, smallest);
    }
}

void insertElement(MinHeap* heap, ll val, int r, int c) {
    if (heap->size == heap->capacity) return;
    int sz = heap->size;
    heap->array[sz].val = val;
    heap->array[sz].r = r;
    heap->array[sz].c = c;
    heap->size++;
    heapify_up(heap, sz);
}

Tuple extractMin(MinHeap* heap) {
    Tuple res = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    heapify_down(heap, 0);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    ll matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }

    int k;
    scanf("%d", &k);

    MinHeap* min_heap = makeHeap(n);

    // Step 1: Initialize the frontier with the first element of each row
    for (int i = 0; i < n; i++) {
        insertElement(min_heap, matrix[i][0], i, 0);
    }

    // Step 2: Extract K-1 times to discard the smaller elements
    for (int i = 0; i < k - 1; i++) {
        Tuple current = extractMin(min_heap);
        
        // Push the next element in the same row, if it exists
        if (current.c + 1 < n) {
            insertElement(min_heap, matrix[current.r][current.c + 1], current.r, current.c + 1);
        }
    }

    // Step 3: The Kth smallest element is now at the top of the heap
    Tuple kth_smallest = extractMin(min_heap);
    printf("%lld\n", kth_smallest.val);

    return 0;
}