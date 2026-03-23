#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FL(i,a,b) for(int i = a ; i < b ; i++)
#define ll long long
typedef struct Heap{
    ll* array;
    int size;
    int capacity;
} Heap;

void heapify(Heap* heap,ll i);
Heap* makeHeap(int capacity);
void swap(ll* a, ll* b);
ll getTop(Heap* heap);


Heap* makeHeap(int capacity){
    Heap* heap = (Heap *)malloc(sizeof(Heap));
    heap -> size = 0;
    heap -> capacity = capacity;
    heap -> array = (ll *)malloc(sizeof(ll)*capacity);
    return heap;
}

void heapify(Heap* heap,ll i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < heap -> size && heap -> array[left] < heap -> array[smallest]){
        smallest = left;
    }
    if(right < heap -> size && heap -> array[right] < heap -> array[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(&heap->array[i],&heap->array[smallest]);
        heapify(heap,smallest);
    }
}

void insertElement(Heap* heap,ll val){
    if(heap -> size == heap -> capacity){
        printf("Heap is full\n");
        return;
    }
    heap -> array[heap -> size] = val;
    int i = heap -> size;
    heap -> size++;
    while (i != 0 && heap -> array[(i-1) / 2] > heap -> array[i])
    {
        swap(&heap->array[i],&heap->array[(i-1)/2]);
        i = (i-1)/2;
    }
}

ll getTop(Heap* heap){
    if(heap -> size <= 0){
        printf("Heap is empty\n");
        return -1;
    }
    if(heap -> size == 1){
        heap->size--;
        return heap->array[0];
    }
    ll el = heap -> array[0];
    heap -> array[0] = heap -> array[heap -> size - 1];
    heap -> size--;
    heapify(heap,0);
    return el; 
}

void swap(ll* a,ll* b){
    ll tmp = *a;
    *a = *b;
    *b = tmp;
}
void printHeap(Heap* heap){
    FL(i,0,heap->size){
        printf("%lld ", heap->array[i]);
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d",&n);
    Heap* heap = makeHeap(n+1);
    ll tmp;
    FL(i,0,n){
        scanf("%lld",&tmp);
        insertElement(heap,tmp);// Make min heap
    }
    ll tot_cost = 0;
    while(heap -> size > 1){
        ll e1 = getTop(heap);
        ll e2 = getTop(heap);
        tot_cost += (e1 + e2);
        insertElement(heap,e1+e2);
    }
    printf("%lld\n",tot_cost);
    free(heap->array);
    free(heap);
}
