/*
 * 是否同一棵二叉树
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
struct TNode{
    int Data;
    BinTree Left;
    BinTree Right;
};

BinTree Insert(BinTree BST, int X);
int IssameTree(BinTree T, BinTree T1);

int main(){
    int N,L,X;
    scanf("%d", &N);
    if(N){
        scanf(" %d", &L);
    }
    while(N){
        BinTree BST = NULL;
        for (int i=0; i<N; i++ ) {
            scanf("%d", &X);
            BST = Insert(BST, X);
        }
        while(L--){
            BinTree BST_T = NULL;
            for (int i=0; i<N; i++ ) {
                scanf("%d", &X);
                BST_T = Insert(BST_T, X);
            }
            if(IssameTree(BST, BST_T)) printf("Yes\n");
            else printf("No\n");
        }
        scanf("%d", &N);
        if(N){
            scanf(" %d", &L);
        }
    }
    return 0;
}

BinTree Insert( BinTree BST, int X ){
    if(!BST){
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    if(X>BST->Data){
        BST->Right = Insert(BST->Right, X);
    }
    else if(X==BST->Data){
    }
    else {
        BST->Left = Insert(BST->Left, X);
    }
    return BST;

}

int IssameTree(BinTree BST, BinTree BST_T){
    if(!BST && !BST_T) return 1; //空树，正确
    if((BST && !BST_T) || (!BST && BST_T)) return 0; //节点个数不同，错误
    if(BST->Data!=BST_T->Data) return 0; //节点数据不一样，错误
    return (IssameTree(BST->Left, BST_T->Left) && IssameTree(BST->Right, BST_T->Right));
}