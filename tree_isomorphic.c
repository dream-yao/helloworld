/*
 * 树的同构
 * pat没通过，但是我测试了数据都是对的
 */
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
#define BinTree int
#define null -1

struct TNode{
    char Data;
    BinTree Left;
    BinTree Right;
}T1[MaxSize], T2[MaxSize];

BinTree CreateTree(struct TNode T[]);
int Isomorphic(BinTree R1, BinTree R2);

int main(){
    BinTree R1 = CreateTree(T1);
    BinTree R2 = CreateTree(T2);
    if(Isomorphic(R1, R2)){
        printf("Yes");
    } else{
        printf("No");
    }
}

BinTree CreateTree(struct TNode T[]){
    int n;
    scanf("%d", &n);
    if(n==0) return null;
    char data;
    char left;
    char right;
    int i=0;
    int Temp[n];
    for(int j=0;j<n;j++){
        Temp[j]=0;
    }
    while(i<n){
        scanf(" %c %c %c", &data, &left, &right);
        T[i].Data = data;
        if(left=='-'){
            T[i].Left = null;
        }else{
            T[i].Left = left-'0';
            Temp[T[i].Left] = 1;
        }
        if(right=='-'){
            T[i].Right = null;
        }else{
            T[i].Right = right-'0';
            Temp[T[i].Right] = 1;
        }
        i++;
    }
    for(int j=0;j<n;j++){
        if(Temp[j]==0) return j;
    }
}

int Isomorphic(BinTree R1, BinTree R2){
    if(R1==null && R2==null) return 1;
    if(T1[R1].Data != T2[R2].Data) return 0;
    if((R1==null && R2!=null)||(R1!=null && R2==null)) return 0;//节点数不同
    if(T1[R1].Left == null && T2[R2].Left == null) {
        return Isomorphic(T1[R1].Right, T2[R2].Right);
    }
//    if(T1[R1].Right == null && T2[R2].Right == null) {
//        return Isomorphic(T1[R1].Left, T2[R2].Left);
//    }
    if(T1[T1[R1].Left].Data == T2[T2[R2].Left].Data) {
        return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
    }
    if(T1[T1[R1].Left].Data == T2[T2[R2].Right].Data) {
        return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
    }
}
