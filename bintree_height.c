/* 二叉树的高度
 * 测试数据：ABD##FE###CG#H##I##
 */
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

BinTree CreatBinTree(){
    char s;
    scanf("%c", &s);
    if(s=='#') return NULL;
    BinTree t = (BinTree)malloc(sizeof(struct TNode));
    t->Data = s;
    t->Left = CreatBinTree();
    t->Right = CreatBinTree();
    return t;
}
/* 你的代码将被嵌在这里 */

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