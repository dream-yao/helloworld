/*
 * 通过先序和中序还原二叉树
 * 测试数据：
 * 9
   ABDFGHIEC
   FDHGIBEAC
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
struct TNode{
    char Data;
    BinTree Left;
    BinTree Right;
};
BinTree CreateTree(char preorder[], char inorder[], int preL, int preR, int inL, int inR);
int GetHeight( BinTree BT );

int main(){
    int n;
    scanf("%d ", &n);
    char preorder[n+1];
    char inorder[n+1];
//    for(int i=0;i<n;i++){
//        scanf("%c", &preorder[i]);
//    }
//    for(int i=0;i<n;i++){
//        scanf("%c", &inorder[i]);
//    }
    scanf("%s", preorder);
    scanf("%s", inorder);
    BinTree BT= CreateTree(preorder,inorder,0,n-1,0,n-1); //建树，返回树的高度
    int H = GetHeight(BT);
    printf("%d", H);
}

BinTree CreateTree(char preorder[], char inorder[], int preL, int preR, int inL, int inR){
    if(preL > preR)
    {
        return NULL; //先序序列长度小于等于0时，直接返回
    }
    BinTree root = (BinTree)malloc(sizeof(struct TNode));
    root->Data = preorder[preL];
    int i;
    for(i=inL;i<inR;i++){
        if(inorder[i]==preorder[preL]) break;
    }
    int numLeft = i-inL;
    root->Left = CreateTree(preorder, inorder, preL+1, preL+numLeft, inL, i-1);
    root->Right = CreateTree(preorder, inorder, preL+numLeft+1, preR, i+1, inR);
    return root; //返回根结点地址
}

int GetHeight( BinTree BT ){
    if(BT){
        int LeftHight = GetHeight(BT->Left);
        int RightHight = GetHeight(BT->Right);
        return ((LeftHight>RightHight)?LeftHight:RightHight)+1;
    }
    else{
        return 0;
    }
}