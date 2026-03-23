#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define ll long long
#define FL(i,a,b) for(int i = a; i < b ; i++)
typedef struct{
    int id;
    int count;
    int wait;
} Tuple;

typedef struct{
    Tuple* arr;
    int size;
    int capacity;
} Heap;

Heap* makeHeap(int capacity){
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap -> arr = (Tuple*) malloc(sizeof(Tuple)*capacity);
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
    if(heap -> arr[parent].count < heap -> arr[el].count){
        swap(&heap->arr[parent],&heap->arr[el]);
        heapify_up(heap,parent);
    }
}

void heapify_down(Heap* heap,int el){
    int left = 2*el + 1;
    int right = 2*el + 2;
    int largest = el;
    if(left < heap->size && heap -> arr[left].count > heap -> arr[largest].count){
        largest = left;
    }
    if(right < heap->size && heap -> arr[right].count > heap -> arr[largest].count){
        largest = right;
    }
    if(largest != el){
        swap(&heap->arr[largest],&heap->arr[el]);
        heapify_down(heap,largest);
    }
}

Tuple getTop(Heap* heap){
    if(heap -> size == 0){
        printf("Heap is empty\n");
        Tuple dummy;
        dummy.count = 0;
        dummy.id = 0;
        dummy.wait = 0;
        return dummy;
    }
    Tuple out = heap->arr[0];
    heap -> arr[0] = heap -> arr[--heap->size];
    heapify_down(heap,0);
    return out;
}

void insertTuple(Heap* heap,Tuple el){
    if(heap -> size == heap -> capacity){
        printf("Heap is already full cannot insert\n");
        return;
    }
    int index = heap -> size;
    heap -> arr[index] = el;
    heap -> size++;
    heapify_up(heap,index);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[26] = {0};
    char tmp;
    Tuple tup;
    Heap* heap = makeHeap(n);
    FL(i,0,n){
        scanf(" %c",&tmp);
        tmp = tmp - 'A'; // Generate id b/w 0 and 25
        arr[tmp]++;
    }

    FL(i,0,26){
        tup.id = i;
        tup.count = arr[i];
        tup.wait = 0;
        if(arr[i] > 0){
            insertTuple(heap,tup);
        }
    }
    int tot_cost = 0;
    int tm = 0;
    Tuple cooldown_queue[n];
    int head = 0, tail = 0;
    while (heap -> size || head < tail)
    {
        while (head < tail && cooldown_queue[head].wait <= tm) {
            insertTuple(heap, cooldown_queue[head]);
            head++;
        }
        if (heap->size > 0) {
            Tuple top = getTop(heap);
            top.count--;
            if (top.count > 0) {
                top.wait = tm + k + 1; // It becomes available K intervals AFTER this current interval
                cooldown_queue[tail] = top;
                tail++;
            }
        }
        tm++;
    }
    printf("%d\n",tm);

}