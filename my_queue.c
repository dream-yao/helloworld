/*
 * 队列的顺序存储实现(循环队列)
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ElementType int
#define ERROR 10086

typedef struct QNode *Queue;
struct QNode{
    ElementType Data[MAXSIZE];
    int front;
    int rear;
};

Queue CreatQueue(); //创建一个队列
int IsFullQ(Queue Q); //判断队列是否已满
void AddQ(Queue Q, ElementType x); //向队列中插入元素
int IsEmpty(Queue Q); //判断队列是否为空
ElementType DeleteQ(Queue Q); //将队头数据从队列中删除并返回

int main(){
    Queue Q;
    Q = CreatQueue();
    printf("main函数里边的地址: %p", Q);
    AddQ(Q, 1);
    AddQ(Q, 2);
    printf("%d\n", DeleteQ(Q));
    printf("%d\n", DeleteQ(Q));
    DeleteQ(Q);
}

Queue CreatQueue(){
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNode));
    printf("函数里边Q的地址: %p", Q);
    Q->front = -1;
    Q->rear = -1;
    return Q;
    //之前忘了返回Q了，但是没有任何报错，问了大神
    //gcc不会检查返回值，所以不报错，返回的内容可能跟寄存器和栈的状态有关系，我觉得是可能你刚创建的对象正好在那个位置，就碰巧返回Q了
    //直接在函数里把Q的地址输出出来，然后把函数返回值地址输出出来，看看是不是一个返回值
}

int IsFullQ(Queue Q){
    if((Q->rear+1)%MAXSIZE == Q->front) return 1;//队列满了返回1
    return 0;
}

void AddQ(Queue Q, ElementType x){
    if(IsFullQ(Q)){
        printf("队列满了哦～");
        return;
    }
    Q->rear = (Q->rear+1)%MAXSIZE;
    Q->Data[Q->rear] = x;
}

int IsEmpty(Queue Q){
    if(Q->front == Q->rear) return 1;//如果为空就返回1;
    return 0;
}

ElementType DeleteQ(Queue Q){
    if(IsEmpty(Q)){
        printf("队列是空的哦～");
        return ERROR;
    }
    Q->front = (Q->front+1)%MAXSIZE;
    return Q->Data[Q->front];
}