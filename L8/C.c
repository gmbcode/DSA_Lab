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

Heap* makeHeap(int capacity){
    Heap* heap = (Heap *) malloc(sizeof(Heap));
    heap -> array = (ll *) malloc(sizeof(ll)*capacity);
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
    if(heap -> array[parent] < heap -> array[el]){
        swap(&heap -> array[el],&heap->array[parent]);
        heapify_up(heap,parent);
    }
}
void heapify_up_mn(Heap* heap,int el){
    if(el == 0){
        return;
    }
    int parent = (el - 1) / 2;
    if(heap -> array[parent] > heap -> array[el]){
        swap(&heap -> array[el],&heap->array[parent]);
        heapify_up_mn(heap,parent);
    }
}
void heapify_down_mn(Heap* heap,int el){
    int left = 2*el + 1;
    int right = 2*el + 2;
    int smallest = el;
    if(left < heap -> size && heap -> array[left] < heap -> array[smallest]){
        smallest = left;
    }
    if(right < heap->size && heap -> array[right] < heap -> array[smallest]){
        smallest = right;
    }
    if(smallest != el){
        swap(&heap->array[smallest],&heap->array[el]);
        heapify_down_mn(heap,smallest);
    }
}
void heapify_down(Heap* heap,int el){
    int left = 2*el + 1;
    int right = 2*el + 2;
    int largest = el;
    if(left < heap -> size && heap -> array[left] > heap -> array[largest]){
        largest = left;
    }
    if(right < heap->size && heap -> array[right] > heap -> array[largest]){
        largest = right;
    }
    if(largest != el){
        swap(&heap->array[largest],&heap->array[el]);
        heapify_down(heap,largest);
    }
}
void insertElement(Heap* heap,ll val,int type){
    if(heap -> size == heap -> capacity){
        printf("Heap is full cannot insert\n");
        return;
    }
    else{
        int sz = heap -> size;
        heap ->array[sz] = val;
        heap -> size++;
        if(type){
            heapify_up_mn(heap,sz);
        }
        else{
            heapify_up(heap,sz);
        }
    }
}

ll getTop(Heap* heap,int type){
    if(heap -> size <= 0){
        printf("Heap is empty\n");
        return -1;
    }
    ll res = heap->array[0];
    heap -> array[0] = heap -> array[--heap -> size];
    if(type){//Type 1 for min heap
         heapify_down_mn(heap,0);
    }
    else{
        heapify_down(heap,0);
    }
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    double out[n];
    ll input[n];
    Heap* min = makeHeap(n+1);
    Heap* max = makeHeap(n+1);
    ll cur;
    FL(i,0,n){
        scanf("%lld",&cur);
        insertElement(max,cur,0); // Insert element into max heap
        ll mx_top = getTop(max,0);
        insertElement(min,mx_top,1); // Insert top of max heap into min heap
        if(min -> size > max -> size){
            ll mn_top = getTop(min,1);
            insertElement(max,mn_top,0);
        }
        if(min -> size == max -> size){
            out[i] = ((double) min -> array[0] + (double) max -> array[0]) / 2;
        }
        else{
            out[i] = (double) max -> array[0];
        }

    }   

    // Insert into mx heap
    // Top of mx heap goes into min heap (to maintain largest upper half in min heap)
    // Now if min heap is bigger than max then insert top of min into max
    // When both heap sizes equal median is avg of top
    // When both heap sizes not equal median is top of max heap (since max will be min + 1) and contain lower half
    
    FL(i,0,n){
        printf("%.1f ",out[i]);
    }
    printf("\n");
}
