#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ll long long
#define FL(i,a,b) for(int i = a ; i < b ; i++)

typedef struct {
    int val;
    int i;
    int j;
} Node;


typedef struct {
    Node* arr;
    int size;
    int capacity;
} Heap;

void swap(Node* a, Node* b) {
    Node tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify_up(Heap* heap, int el) {
    if (el == 0) return;
    int parent = (el - 1) / 2;
    if (heap->arr[parent].val > heap->arr[el].val) {
        swap(&heap->arr[parent], &heap->arr[el]);
        heapify_up(heap, parent);
    }
}

void heapify_down(Heap* heap, int el) {
    int left = 2 * el + 1;
    int right = 2 * el + 2;
    int smallest = el;

    if (left < heap->size && heap->arr[left].val < heap->arr[smallest].val) {
        smallest = left;
    }
    if (right < heap->size && heap->arr[right].val < heap->arr[smallest].val) {
        smallest = right;
    }
    if (smallest != el) {
        swap(&heap->arr[smallest], &heap->arr[el]);
        heapify_down(heap, smallest);
    }
}

Node getTop(Heap* heap) {
    Node res = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapify_down(heap, 0);
    return res;
}

void insertElement(Heap* heap, Node el) {
    int index = heap->size;
    heap->arr[heap->size++] = el;
    heapify_up(heap, index);
}

int main() {
    int k;
    if (scanf("%d", &k) != 1) return 0;


    // Assumes no list is larger than 10,000 elements and max K is reasonable
    int sizes[k];
    int a[k][10000]; 
    
    // Fixed memory for the Heap
    Node heap_arr[10000]; 
    Heap heap_obj = {heap_arr, 0, 10000};
    Heap* heap = &heap_obj; 

    int current_max = -1000000;

    // Push the first element of each list into the heap
    FL(i, 0, k) {
        scanf("%d", &sizes[i]);
        FL(j, 0, sizes[i]) {
            scanf("%d", &a[i][j]);
        }

        Node el = {a[i][0], i, 0};
        insertElement(heap, el);

        if (a[i][0] > current_max) {
            current_max = a[i][0];
        }
    }

    int best_start = -1000000;
    int best_end = 1000000;

    // Squeeze the range using the Min-Heap
    while (heap->size == k) {
        Node min_el = getTop(heap);

        ll current_range = (ll)current_max - min_el.val;
        ll best_range = (ll)best_end - best_start;

        // Check if we found a strictly smaller range, or a tied range that starts earlier
        if (current_range < best_range || (current_range == best_range && min_el.val < best_start)) {
            best_start = min_el.val;
            best_end = current_max;
        }

        // Get the NEXT element from the same list the minimum just came from
        int next_idx = min_el.j + 1;
        int list_id = min_el.i;

        if (next_idx < sizes[list_id]) {
            int next_val = a[list_id][next_idx];
            Node next_el = {next_val, list_id, next_idx};
            insertElement(heap, next_el);

            if (next_val > current_max) {
                current_max = next_val;
            }
        } else {
            break; 
        }
    }

    printf("%d %d\n", best_start, best_end);

    return 0;
}