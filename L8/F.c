#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ll long long

typedef struct{
    ll* arr;
    int size;
    int capacity;
} Heap;

Heap* makeHeap(int capacity){
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap -> arr = (ll*)malloc(sizeof(ll)*capacity);
    heap -> size = 0;
    heap -> capacity = capacity;
    return heap;
}
void swap(ll* a,ll* b){
    ll tmp = *a;
    *a = *b;
    *b = tmp;
}
void heapify_up(Heap* heap,int el){
    if(el == 0){
        return;
    }
    int parent = (el - 1) / 2;
    if(heap -> arr[parent] > heap -> arr[el]){
        swap(&heap->arr[parent],&heap->arr[el]);
        heapify_up(heap,parent);
    }
}

void heapify_down(Heap* heap,int el){
    int left = 2*el + 1;
    int right = 2*el + 2;
    int smallest = el;
    if(left < heap->size && heap -> arr[left] < heap -> arr[smallest]){
        smallest = left;
    }
    if(right < heap->size && heap->arr[right] < heap -> arr[smallest]){
        smallest = right;
    }
    if(smallest != el){
        swap(&heap->arr[el],&heap->arr[smallest]);
        heapify_down(heap,smallest);
    }
}

void insertElement(Heap* heap,ll el){
    if(heap -> size == heap -> capacity){
        printf("Heap is already full cannot insert\n");
        return;
    }
    int index = heap -> size;
    heap ->arr[index] = el;
    heap -> size++;
    heapify_up(heap,index);
}

ll getTop(Heap* heap){
    if(heap -> size == 0){
        printf("Heap is already empty cannot pop\n");
        return LLONG_MIN;
    }
    ll res = heap -> arr[0];
    heap -> arr[0] = heap -> arr[--heap -> size];
    heapify_down(heap,0);
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    Heap* heap = makeHeap(n*3+10);
    insertElement(heap,2);
    insertElement(heap,5);
    insertElement(heap,7);
    // we want 2^i*5^j*7^k form of numbers
    ll curr = 0;
    ll last_popped = 0;
    int count = 0;

    while (count < n) {
        curr = getTop(heap);

        if (curr == last_popped){//Skip duplicates
            continue; 
        }

        last_popped = curr;
        count++;

        if(count == n){
            break;
        }
        insertElement(heap, curr * 2);
        insertElement(heap, curr * 5);
        insertElement(heap, curr * 7);
    }

    printf("%lld\n", curr);

}