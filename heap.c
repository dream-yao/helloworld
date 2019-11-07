/*
 * 小顶堆的各种操作
 * 测试数据
 * 58 25 44 18 10
 */

#include <stdio.h>
#include <stdlib.h>

#define MinData -10086

typedef struct HeapStruct *MinHeap;
struct HeapStruct{
    int *Data;
    int Size;
    int Capacity; //堆的最大容量
};

MinHeap Create(int MaxSize);
void Insert(MinHeap H, int item);
int Delete(MinHeap H);

int main(){
    int N, MaxSize = 100;
    MinHeap H = Create(MaxSize);
    for(int i=0;i<5;i++){
        scanf("%d", &N);
        Insert(H, N);
    }
    printf("%d ", Delete(H));
    printf("%d ", Delete(H));
    printf("%d", Delete(H));
}

MinHeap Create(int MaxSize){
    MinHeap H = malloc(sizeof(struct HeapStruct));
    H->Data = malloc((MaxSize+1)*sizeof(int));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Data[0] = MinData; //创建哨兵
    return H;
}

void Insert(MinHeap H, int item){
    if(H->Size==H->Capacity){
        printf("堆已满");
        return;
    }
    int i;
    for(i=++H->Size;H->Data[i/2]>item;i/=2){
        H->Data[i] = H->Data[i/2];
    }
    H->Data[i] = item;
}

int Delete(MinHeap H){
    if(H->Size==0){
        printf("堆是空的");
        return 0;
    }
    int MinItem = H->Data[1];
    int temp = H->Data[H->Size--];
    int parent, child;
    for(parent=1;parent*2<=H->Size;parent=child){
        child = parent*2;
        if(H->Data[child]>H->Data[child+1]) child++;
        if(temp<=H->Data[child]) break;
        else H->Data[parent] = H->Data[child];
    }
    H->Data[parent] = temp;
    return MinItem;
}


