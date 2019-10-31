/*
 * 找到平衡二叉树的根
 * 测试实例
 * 前一版本我直接给height+1,出现深度LL旋转错误，但我不明白为什么
Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
struct TNode{
    int Data;
    BinTree Left;
    BinTree Right;
    int Height;
};

BinTree insert(BinTree T, int X);
BinTree SingleRightRotation(BinTree T);
BinTree RightLeftRotation(BinTree T);
BinTree SingleLeftRotation(BinTree T);
BinTree LeftRightRotation(BinTree T);
int GetHight(BinTree T);

int main(){
    int N,X;
    BinTree T=NULL;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &X);
        T = insert(T, X);
    }
    printf("%d", T->Data);
}

int GetHight(BinTree T){
    if(T){
        return T->Height;
    }
    else {
        return 0;
    }
}

BinTree SingleRightRotation(BinTree T){
    BinTree Tmp = T->Right;
    T->Right = Tmp->Left;
    Tmp->Left = T;
    T->Height = ((GetHight(T->Left)>GetHight(T->Right))?GetHight(T->Left):GetHight(T->Right))+1;
    Tmp->Height = ((GetHight(Tmp->Left)>GetHight(Tmp->Right))?GetHight(Tmp->Left):GetHight(Tmp->Right))+1;
    return Tmp;
}

BinTree RightLeftRotation(BinTree T){
    T->Right = SingleLeftRotation(T->Right);
    T = SingleRightRotation(T);
    return T;
}

BinTree SingleLeftRotation(BinTree T){
    BinTree Tmp = T->Left;
    T->Left = Tmp->Right;
    Tmp->Right = T;
    T->Height = ((GetHight(T->Left)>GetHight(T->Right))?GetHight(T->Left):GetHight(T->Right))+1;
    Tmp->Height = ((GetHight(Tmp->Left)>GetHight(Tmp->Right))?GetHight(Tmp->Left):GetHight(Tmp->Right))+1;
    return Tmp;
}

BinTree LeftRightRotation(BinTree T){
    T->Left = SingleRightRotation(T->Left);
    T = SingleLeftRotation(T);
    return T;
}

BinTree insert(BinTree T, int X){
    if(!T){
        T = (BinTree)malloc(sizeof(struct TNode));
        T->Data = X;
        T->Left = NULL;
        T->Right = NULL;
        T->Height = 0;
    }
    else{
        if(X>T->Data){
            T->Right = insert(T->Right, X);
            if(GetHight(T->Right) - GetHight(T->Left) == 2){
                if(X<T->Right->Data){
                    T = RightLeftRotation(T); //RL
                }
                else{
                    T = SingleRightRotation(T); //RR
                }
            }
        }
        else if(X<T->Data){
            T->Left = insert(T->Left, X);
            if(GetHight(T->Left) - GetHight(T->Right) == 2){
                if(X>T->Left->Data){
                    T = LeftRightRotation(T); //LR
                }
                else{
                    T = SingleLeftRotation(T); //LL
                }
            }
        }
    }
    T->Height = ((GetHight(T->Left)>GetHight(T->Right))?GetHight(T->Left):GetHight(T->Right))+1;
    return T;
}
