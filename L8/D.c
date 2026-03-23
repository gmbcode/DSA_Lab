#include <stdio.h>
#include <stdlib.h>

#define ll long long

typedef struct {
    ll sum;
    int i; 
    int j; 
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
    // Min-Heap property: Parent must be smaller than the child
    if (heap->array[parent].sum > heap->array[el].sum) {
        swap(&heap->array[el], &heap->array[parent]);
        heapify_up(heap, parent);
    }
}

void heapify_down(MinHeap* heap, int el) {
    int left = 2 * el + 1;
    int right = 2 * el + 2;
    int smallest = el;

    if (left < heap->size && heap->array[left].sum < heap->array[smallest].sum) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right].sum < heap->array[smallest].sum) {
        smallest = right;
    }
    if (smallest != el) {
        swap(&heap->array[smallest], &heap->array[el]);
        heapify_down(heap, smallest);
    }
}

void insertElement(MinHeap* heap, ll sum, int i, int j) {
    if (heap->size == heap->capacity) return;
    
    int sz = heap->size;
    heap->array[sz].sum = sum;
    heap->array[sz].i = i;
    heap->array[sz].j = j;
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
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    ll* A = (ll*)malloc(sizeof(ll) * n1); //Arr A
    for (int i = 0; i < n1; i++) {
        scanf("%lld", &A[i]);
    }

    ll* B = (ll*)malloc(sizeof(ll) * n2); //Arr B
    for (int j = 0; j < n2; j++) {
        scanf("%lld", &B[j]);
    }

    int k;
    scanf("%d", &k);

    // The heap size never needs to be larger than K
    MinHeap* min_heap = makeHeap(k);

    // Pair the first element of B with the first K elements of A.
    for (int i = 0; i < n1 && i < k; i++) {
        insertElement(min_heap, A[i] + B[0], i, 0);
    }

    // Step 2: Extract the minimum sum K times
    int count = 0;
    while (min_heap->size > 0 && count < k) {
        // Pop the smallest pair currently available
        Tuple current = extractMin(min_heap);
        
        // Output the values that make up the pair
        printf("%lld %lld\n", A[current.i], B[current.j]);
        count++;

        // Push the next possible neighbor from Array B into the heap
        if (current.j + 1 < n2) {
            ll new_sum = A[current.i] + B[current.j + 1];
            insertElement(min_heap, new_sum, current.i, current.j + 1);
        }
    }


    return 0;
}