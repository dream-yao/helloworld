/*
 * 哈弗曼编码
 * 解题关键
 * 1. 判断学生给出的编码是否是最小WPL
 * 2. 判断学生给出的编码是否存在前缀码
 *
 * 提交还有些错误,暂时不改
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MinData -10086
#define MaxN 64

typedef struct TreeNode *HuffmanTree;
struct TreeNode{
    char Data;
    int Weight;
    HuffmanTree Left, Right;
};

typedef struct HeapStruct *MinHeap;
struct HeapStruct{
    HuffmanTree *Data;//要加*
    int Size;
    int Capacity; //堆的最大容量
};

int w[MaxN]; //权重数组

MinHeap Create(int MaxSize);
MinHeap ReadData(MinHeap H, int N);
void Insert(MinHeap H, HuffmanTree T);
HuffmanTree Delete(MinHeap H);
HuffmanTree CreateTree();
HuffmanTree Huffman(MinHeap H);
int WPL(HuffmanTree T, int Depth);
int Judge(int N, int Codelen);

int main(){
    //创建哈弗曼树,求最小WPL
    //求出学生的WPL,与上述作比较
    //判断学生的编码是否存在前缀
    int N,M;
    scanf("%d", &N);
    MinHeap H = Create(N*2);
    H = ReadData(H, N);
    HuffmanTree T = Huffman(H);
    int Codelen = WPL(T, 0);

    scanf("%d", &M);
    while (M--){
        if(Judge(N, Codelen)) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}

MinHeap Create(int MaxSize){
    MinHeap H = malloc(sizeof(struct HeapStruct));
    H->Data = malloc((MaxSize+1)*sizeof(HuffmanTree));
    H->Size = 0;
    H->Capacity = MaxSize;
    HuffmanTree T = CreateTree();
    T->Weight = MinData;
    H->Data[0] = T;
//    H->Data[0]->Weight = MinData; //创建哨兵//这句出现错误,因为还有有建立哈弗曼树节点就赋值了
    return H;
}

MinHeap ReadData(MinHeap H, int N){
    char ch;
    int weight;
    int i=0;
    while (N--){
        scanf(" %c %d", &ch, &weight);
        HuffmanTree T = CreateTree();
        T->Data = ch;
        T->Weight = weight;
        w[i++] = weight; //将读入的权重放入数组
        Insert(H, T);
    }
    return H;
}

void Insert(MinHeap H, HuffmanTree T){
    if(H->Size==H->Capacity){
        printf("堆已满");
        return;
    }
    int i;
    for(i=++H->Size;H->Data[i/2]->Weight>T->Weight;i/=2){
        H->Data[i] = H->Data[i/2];
    }
    H->Data[i] = T;
}

HuffmanTree CreateTree(){
    HuffmanTree T = (HuffmanTree)malloc(sizeof(struct TreeNode));
    T->Data = '\0';  //空字符
    T->Weight = 0;
    T->Right = NULL;
    T->Left = NULL;
    return T;
}

HuffmanTree Delete(MinHeap H){
    if(H->Size==0){
        printf("堆是空的");
        return 0;
    }
    HuffmanTree MinItem = H->Data[1];
    HuffmanTree temp = H->Data[H->Size--];
    int parent, child;
    for(parent=1;parent*2<=H->Size;parent=child){
        child = parent*2;
        if(H->Data[child]->Weight>H->Data[child+1]->Weight) child++;
        if(temp->Weight<=H->Data[child]->Weight) break;
        else H->Data[parent] = H->Data[child];
    }
    H->Data[parent] = temp;
    return MinItem;
}

HuffmanTree Huffman(MinHeap H){
    int i;
    HuffmanTree T;
    int t = H->Size;
    for(int i=1;i<t;i++){
        T = (HuffmanTree)malloc(sizeof(struct TreeNode));
        T->Left = Delete(H);
        T->Right =Delete(H);
        T->Weight = T->Left->Weight+T->Right->Weight;
        Insert(H,T);
    }
    T = Delete(H);
    return T;
}

int WPL(HuffmanTree T, int Depth){
    if(!T) return 0;
    if(!T->Left && !T->Right){
        return Depth*T->Weight;
    } else{
        int l = WPL(T->Left, Depth+1);
        int r = WPL(T->Right, Depth+1);
        return l+r;
//        return (WPL(T->Left, Depth+1)+WPL(T->Right, Depth+1));
    }
}

int Judge(int N, int Codelen){
    char ch;
    char code[MaxN];
    HuffmanTree T = CreateTree();//创建根节点,后续根据学生的编码建树
    int j=0; //计数当前是哪个字符的权重
    int t = N;
    while (N--){
        int i=0;
        HuffmanTree PT = T;
        scanf(" %c %s", &ch, &code);
        if(strlen(code) > t-1)  return 0;
        while (code[i]!='\0'){
            if(code[i]=='0'){
                if(PT->Left){
                    if(PT->Left->Weight > 0) return 0;
                    PT = PT->Left;
                    i++;
                    continue;
                }
                PT->Left = CreateTree();
                PT = PT->Left;
            } else{
                if(PT->Right){
                    if(PT->Right->Weight > 0) return 0;
                    PT = PT->Right;
                    i++;
                    continue;
                }
                PT->Right = CreateTree();
                PT = PT->Right;
            }
            i++;
        }
        if(!PT->Left && !PT->Right){
            PT->Weight = w[j];//若是叶子节点,赋予权重
        } else return 0;
        j++;
    } //建树完成
    if(WPL(T,0) != Codelen) return 0;
    return 1;
}
