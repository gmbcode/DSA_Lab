#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define ll long long
#define FL(i,a,b) for(int i = a ; i < b ; i++)

typedef struct{
    int a;
    int b;
} Tuple;

typedef struct{
    Tuple* arr;
    int size;
    int capacity;
} Heap;


Heap* makeHeap(int capacity){
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap -> arr = (Tuple*) malloc(capacity*sizeof(Tuple));
    heap -> size = 0;
    heap -> capacity = capacity;
    return heap;
}

void swap(Tuple* a,Tuple* b){
    Tuple tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify_up(Heap* heap,int el){
    if(el == 0){
        return;
    }
    int parent = (el - 1) / 2;
    int s_par = heap -> arr[parent].a + heap -> arr[parent].b;
    int s_el = heap -> arr[el].a + heap -> arr[el].b;
    if(s_par > s_el){
        swap(&heap->arr[parent],&heap->arr[el]);
        heapify_up(heap,parent);
    }
}

void heapify_down(Heap* heap, int el) {
    int left = 2 * el + 1;
    int right = 2 * el + 2;
    int smallest = el;
    int sz = heap->size;

    if (left < sz) {
        int s_left = heap->arr[left].a + heap->arr[left].b;
        int s_curr = heap->arr[smallest].a + heap->arr[smallest].b;
        if (s_left < s_curr) {
            smallest = left;
        }
    }

    if (right < sz) {
        int s_right = heap->arr[right].a + heap->arr[right].b;
        int s_curr = heap->arr[smallest].a + heap->arr[smallest].b;
        if (s_right < s_curr) {
            smallest = right;
        }
    }

    if (smallest != el) {
        swap(&heap->arr[smallest], &heap->arr[el]);
        heapify_down(heap, smallest);
    }
}

Tuple getTop(Heap* heap){
    Tuple res = heap -> arr[0];
    heap -> arr[0] = heap -> arr[--heap -> size];
    heapify_down(heap,0);
    return res;
}

void insertPair(Heap* heap,Tuple t){
    if(heap -> size == heap -> capacity){
        printf("Heap is already full\n");
        return;
    }
    int index = heap -> size;
    heap -> arr[heap -> size++] = t;
    heapify_up(heap,index);
}


int main(){
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    
    Heap* heap = makeHeap(n1 * n2);
    int a[n1];
    int b[n2];
    FL(i,0,n1){
        scanf("%d",&a[i]);
    }
    FL(i,0,n2){
        scanf("%d",&b[i]);
    }
    int k;
    scanf("%d",&k);
    FL(i,0,n1){
        FL(j,0,n2){
            Tuple tmp = {a[i],b[j]};
            insertPair(heap,tmp);
        }
    }

    FL(i,0,k){
        Tuple tmp = getTop(heap);
        printf("%d %d\n",tmp.a,tmp.b);
    }
}