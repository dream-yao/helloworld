/*堆栈的顺序存储结构实现
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ElementType int
#define ERROR 10086

typedef struct SNode *Stack;
struct SNode{
    ElementType Data[MAXSIZE];
    int top;
};

Stack CreatStack(); //生成空栈
int IsFull(Stack S); //判断堆栈S是否已满
void Push(Stack S, ElementType x); //入栈
int IsEmpty(Stack S); //判断堆栈是否为空
ElementType Pop(Stack S); //删除并返回栈顶元素

int main(){
    Stack S;
    S = CreatStack();
    Push(S, 1);
    Push(S, 2);
    printf("%d", Pop(S));
    printf("%d", Pop(S));
    printf("%d", Pop(S));
    printf("%d", Pop(S));
}

Stack CreatStack(){
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->top = -1;
    return S;
}

int IsFull(Stack S){
    if(S->top == MAXSIZE -1) return 1;//如果满了返回1
    return 0;
}

void Push(Stack S, ElementType x){
    if(IsFull(S)){
        printf("堆栈已满～");
        return;
    }
    S->Data[++S->top] = x;
}

int IsEmpty(Stack S){
    if(S->top == -1) return 1;//如果是空的返回1
    return 0;
}

ElementType Pop(Stack S){
    if(IsEmpty(S)){
        printf("堆栈是空的哦～");
        return ERROR;
    }
    ElementType x = S->Data[S->top--];
    return x;
}


