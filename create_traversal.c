/* 二叉树的遍历
 * 测试数据：ABD##FE###CG#H##I##
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree();
void PreorderTraversal( BinTree BT );
void InorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
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

void PreorderTraversal( BinTree BT ){
    if(BT){
        printf(" %c", BT->Data);
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
        printf(" %c", BT->Data);
        InorderTraversal(BT->Right);
    }
    else {
        return;
    }
}

void PostorderTraversal( BinTree BT ){
    if(BT){
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %c", BT->Data);
    }
    else {
        return;
    }
}

void LevelorderTraversal(BinTree BT)
{
    if (BT == NULL)
        return;
    BinTree binTree[100];   //数组迭代存储层序遍历的节点
    int head = 0, last = 0; //
    binTree[last++] = BT;

    while (head < last)     //通过迭代存储和遍历节点
    {
        BinTree temp = binTree[head++];
        printf(" %c", temp->Data);

        if (temp->Left)     //左子树存在
            binTree[last++] = temp->Left;
        if (temp->Right)    //右子树存在
            binTree[last++] = temp->Right;
    }
}