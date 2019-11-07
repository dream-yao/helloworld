/*
 * 堆中的路径，堆用完全二叉树来实现，所以用数组会方便
 * 测试数据
5 3
46 23 26 24 10
5 4 3
 */

#include <stdlib.h>
#include <stdio.h>
#define MaxSize 1001
#define MinSize -10086

int H[MaxSize], size;
void Create();
void Insert(int X);
void PrintPath(int X);

int main(){
    int N,M,K;
    scanf("%d %d", &N, &M);
    Create();
    while(N--){
        scanf("%d", &K);
        Insert(K);
    }
    int n;
    while(M--){
        scanf("%d", &n);
        PrintPath(n);
    }
    return 0;
}

void Create(){
    size = 0;
    H[0] = MinSize;
}

void Insert(int X){
    int i;
    for(i=++size;H[i/2]>X;i/=2){
        H[i] = H[i/2];
    }
    H[i] = X;
}

void PrintPath(int X){
    printf("%d", H[X]);
    while(X>1){
        X/=2;
        printf(" %d", H[X]);
    }
    printf("\n");
//    for(int i=X;i>0;i/=2){
//        printf("%d ", H[i]);
//    }
//    printf("%c",8);
}