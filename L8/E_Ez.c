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
    if(heap->arr[parent] < heap -> arr[el]){
        swap(&heap->arr[parent],&heap->arr[el]);
        heapify_up(heap,parent);
    }
}

void heapify_down(Heap* heap,int el){
    int left = 2*el + 1;
    int right = 2*el + 2;
    int largest = el;
    if(left < heap -> size && heap -> arr[left] > heap -> arr[largest]){
        largest = left;
    }
    if(right < heap -> size && heap -> arr[right] > heap -> arr[largest]){
        largest = right;
    }
    if(largest != el){
        swap(&heap->arr[largest],&heap->arr[el]);
        heapify_down(heap,largest);
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
    int n;
    scanf("%d",&n);
    int mat[n][n];
    FL(i,0,n){
        FL(j,0,n){
            scanf("%d",&mat[i][j]);
        }
    }
    int k;
    scanf("%d",&k);
    Heap* heap = makeHeap(k+1);

    FL(i,0,n){
        FL(j,0,n){
            if(heap -> size < k){
                insertElement(heap,mat[i][j]);
            }
            else{
                if(mat[i][j] < heap -> arr[0]){
                    insertElement(heap,mat[i][j]);
                    getTop(heap);
                }
            }
        }
    }
    printf("%d\n",heap -> arr[0]);

}