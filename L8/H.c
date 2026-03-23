#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define ll long long
#define FL(i,a,b) for(int i = a ; i < b ; i++)

typedef struct{
    int i;
    int j;
    int height;
} Cell;

typedef struct{
    Cell* arr;
    int size;
    int capacity;
} Heap;

Heap* makeHeap(int capacity){
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap -> arr = (Cell*) malloc(sizeof(Cell)*capacity);
    heap -> capacity = capacity;
    heap -> size = 0;
    return heap;
}

void swap(Cell* a,Cell* b){
    Cell tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify_up(Heap* heap,int el){
    if(el == 0){
        return;
    }
    int parent = (el - 1) / 2;
    if(heap -> arr[parent].height > heap -> arr[el].height){
        swap(&heap -> arr[parent],&heap -> arr[el]);
        heapify_up(heap,parent);
    }
}

void heapify_down(Heap* heap,int el){
    int left = 2*el + 1;
    int right = 2*el + 2;
    int sz = heap -> size;
    int smallest = el;
    if(left < sz){
        if(heap -> arr[left].height < heap -> arr[smallest].height){
            smallest = left;
        }
    }
    if(right < sz){
        if(heap -> arr[right].height < heap -> arr[smallest].height){
            smallest = right;
        }
    }
    if(smallest != el){
        swap(&heap -> arr[el],&heap -> arr[smallest]);
        heapify_down(heap,smallest);
    }
}

void insertCell(Heap* heap,Cell t){
    if(heap -> size == heap -> capacity){
        printf("Heap is full \n");
        return;
    }
    int index = heap -> size;
    heap -> arr[heap -> size++] = t;
    heapify_up(heap,index);
}

Cell getTop(Heap* heap){
    Cell res = heap -> arr[0];
    heap -> arr[0] = heap->arr[--heap->size];
    heapify_down(heap,0);
    return res;
}

int iib(int i,int j,int r,int c){
    if((i < r && i >= 0) && (j < c && j >= 0)){
        return 1;
    }
    return 0;
}
int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    int grid[r][c];
    int visited[r][c];
    FL(i,0,r){
        FL(j,0,c){
            visited[i][j] = 0;
            scanf("%d",&grid[i][j]);
        }
    }
    Heap* heap = makeHeap(r*c + 1);
    FL(i,0,r){
        FL(j,0,c){
            if(i == 0 || i == (r-1) || j == 0 || j == (c-1)){
                Cell temp = {i,j,grid[i][j]};
                insertCell(heap,temp);
                visited[i][j] = 1;
            }
        }
    }

    int dz[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int vol = 0;
    while(heap -> size > 0){
        Cell cur = getTop(heap);
        
        FL(i,0,4){
            int fx = cur.i + dz[i][0];
            int fy = cur.j + dz[i][1];
            if(iib(fx,fy,r,c) && !visited[fx][fy]){
                Cell tmp = {fx,fy,grid[fx][fy]};
                if(grid[fx][fy] >= cur.height){
                    insertCell(heap,tmp);
                    visited[fx][fy] = 1;
                }
                else{
                    vol += cur.height - grid[fx][fy];
                    grid[fx][fy] = cur.height;
                    tmp.height = grid[fx][fy];
                    visited[fx][fy] = 1;
                    insertCell(heap,tmp);
                }
            }
        }
    }
    printf("%d\n",vol);

}