#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define ll long long
#define FL(i,a,b) for(int i = a ; i < b ; i++)

typedef struct {
    int* arr;
    int size;
    int capacity;
} Heap;

Heap* makeHeap(int capacity){
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap -> arr = (int*)malloc(sizeof(int)*capacity);
    heap -> size = 0;
    heap -> capacity = capacity;
    return heap;
}

void swap(int* a,int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void heapify_up(Heap* heap,int el){
    if(el == 0){
        return;
    }
    int parent = (el-1) / 2;
    if(heap->arr[parent] > heap -> arr[el]){
        swap(&heap->arr[parent],&heap->arr[el]);
        heapify_up(heap,parent);
    }
}

void heapify_down(Heap* heap,int el){
    int left = 2*el + 1;
    int right = 2*el + 2;
    int smallest = el;
    if(left < heap -> size && heap -> arr[left] < heap -> arr[smallest]){
        smallest = left;
    }
    if(right < heap -> size && heap -> arr[right] < heap -> arr[smallest]){
        smallest = right;
    }
    if(smallest != el){
        swap(&heap->arr[smallest],&heap->arr[el]);
        heapify_down(heap,smallest);
    }
}

int getTop(Heap* heap){
    int res = heap -> arr[0];
    heap -> arr[0] = heap -> arr[--heap -> size];
    heapify_down(heap,0);
    return res;
}

void insertElement(Heap* heap,int el){
    if(heap -> size == heap -> capacity){
        printf("Heap is already full \n");
        return;
    }
    int index = heap -> size;
    heap -> arr[heap -> size++] = el;
    heapify_up(heap,index);
}

int main(){
    int n,k;
    scanf("%d %d",&k,&n);
    int out[n];
    Heap* heap = makeHeap(n+1);
    int tmp;
    FL(i,0,n){
        scanf("%d",&tmp);
        if((i+1) < k){
            insertElement(heap,tmp);
            out[i] = -1;
        }
        if((i+1) == k){
            insertElement(heap,tmp);
            out[i] = heap -> arr[0];
        }
        if((i+1) > k){
            if(tmp <= heap -> arr[0]){//Element is smaller than or equal current kth largest therefore discard
                out[i] = heap -> arr[0];
            }
            else{
                insertElement(heap,tmp);
                getTop(heap);
                out[i] = heap -> arr[0];
            }
        }
    }
    FL(i,0,n){
        printf("%d ",out[i]);
    }
    printf("\n");

}