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

typedef struct {
    int deadline;
    int reward;
} Mission;

void bsort(Mission* arr,int n){
    Mission tmp;
    FL(i,0,n){
        FL(j,1,n){
            if(arr[j].deadline < arr[j-1].deadline){
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
}


int main(){
    int n;
    scanf("%d",&n);
    Mission arr[n];
    FL(i,0,n){
        int d,r;
        scanf("%d %d",&d,&r);
        arr[i].deadline = d;
        arr[i].reward = r;
    }
    bsort(arr,n); // Sort deadlines in asc order
    Heap* heap = makeHeap(n);
    FL(i,0,n){
        insertElement(heap,arr[i].reward);
        if(heap -> size > arr[i].deadline){
            getTop(heap);
        }
    }

    ll tot_reward = 0;
    FL(i,0,heap -> size){
        tot_reward += heap -> arr[i];
    }
    printf("%lld\n",tot_reward);
}