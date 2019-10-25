/* 先序输出叶子节点
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
void PreorderPrintLeaves( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */

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

void PreorderPrintLeaves( BinTree BT ){
    if (BT == NULL)
        return;

    if((!BT->Left)&&(!BT->Right)){
        printf(" %c", BT->Data);
        return;
    }
    PreorderPrintLeaves(BT->Left);
    PreorderPrintLeaves(BT->Right);
}