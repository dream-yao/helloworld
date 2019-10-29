/*
 * 二叉搜索树的5种常用操作
 * 输入样例
10
5 8 6 2 4 1 0 10 9 7
5
6 3 10 0 5
5
5 7 0 10 3
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:");
    PreorderTraversal(BST);
    printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}

void PreorderTraversal( BinTree BT ){
    if(BT){
        printf(" %d", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
    else {
        return;
    }
}

void InorderTraversal( BinTree BT ){
    if(BT){
        InorderTraversal(BT->Left);
        printf(" %d", BT->Data);
        InorderTraversal(BT->Right);
    }
    else {
        return;
    }
}
/* 你的代码将被嵌在这里 */
BinTree Insert( BinTree BST, ElementType X ){
    if(!BST){
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
        return BST;
    }
    if(X>BST->Data){
        BST->Right = Insert(BST->Right, X);
        return BST;
    }
    else if(X==BST->Data){
        return BST;
    }
    else {
        BST->Left = Insert(BST->Left, X);
        return BST;
    }
}
BinTree Delete( BinTree BST, ElementType X ){
    if(!BST) {
        printf("Not Found\n");
        return NULL;
    }
    if(BST->Data == X){
        BinTree Tmp;
        //删除的三种情况
        //1. 叶节点
        if(BST->Left==NULL && BST->Right==NULL){
            Tmp = BST;
            BST = NULL;
            free(Tmp);
        }
        //2. 一个孩子节点
        else if(BST->Left==NULL || BST->Right==NULL){
            if(BST->Left==NULL) {
                Tmp = BST;
                BST = BST->Right;
                free(Tmp);
            }
            else if(BST->Right==NULL) {
                Tmp = BST;
                BST = BST->Left;
                free(Tmp);
            }
        }
        //3. 两个孩子节点,选取此节点右子树最小
        else if(BST->Left && BST->Right) {
            Position T = FindMin(BST->Right);
            BST->Data = T->Data;
            BST->Right = Delete(BST->Right, BST->Data);
        }
    }
    else if(X>BST->Data) BST->Right = Delete(BST->Right, X);
    else BST->Left = Delete(BST->Left, X);

    return BST;
}
Position Find( BinTree BST, ElementType X ){
    if(!BST) return NULL;
    if(X>BST->Data){
        return Find(BST->Right, X);
    } else if(X<BST->Data){
        return Find(BST->Left, X);
    } else {
        return BST;
    }
}
Position FindMin( BinTree BST ){
    if(!BST) return NULL;
    else if(!BST->Left) return BST;
    else return FindMin(BST->Left);
}
Position FindMax( BinTree BST ){
    if(!BST) return NULL;
    else if(!BST->Right) return BST;
    else return FindMax(BST->Right);
}
