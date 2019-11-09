/*
 * 列出连通集
 * 考察建图,DFS,BFS
 */

#include <stdio.h>
#include <stdlib.h>

#define WeightType int
#define MaxVertexNum 10

typedef int Vertex;

int Visited[100];

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv; //定点数
    int Ne; //边数
    WeightType G[MaxVertexNum][MaxVertexNum];
//    DataType Data[MaxVertexNum]; //存顶点的数据
};
typedef PtrToGNode MGraph;

typedef struct ENode* PtrToENode;
struct ENode{
    Vertex V,W;
//    WeightType Weight;
};
typedef PtrToENode Edge;

MGraph CreateGraph(int VertexNum);//初始化图
void InsertEdge(MGraph Graph, Edge E);//插入边
MGraph BuildGraph();//读入顶点和边,创建图
void DFS(MGraph Graph, Vertex V);
void BFS(MGraph Graph, Vertex V);

int main(){
    MGraph Graph = BuildGraph();
    for(int i=0;i<Graph->Nv;i++){
        Visited[i] = 0;
    }
    for(Vertex V=0;V<Graph->Nv;V++){
        if (!Visited[V]) {
            printf("{ ");
            DFS(Graph, V);
            printf("}\n");
        }
    }

    for(int i=0;i<Graph->Nv;i++){
        Visited[i] = 0;
    }
    for(Vertex V=0;V<Graph->Nv;V++){
        if (!Visited[V]) {
            printf("{ ");
            BFS(Graph, V);
            printf("}\n");
        }
    }
}

MGraph CreateGraph(int VertexNum){
    Vertex V,W;
    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for(V=0;V<Graph->Nv;V++){
        for(W=0;W<Graph->Nv;W++){
            Graph->G[V][W] = 0;
        }
    }

    return Graph;
}

void InsertEdge(MGraph Graph, Edge E){
//    Graph[E->V][E->W] = E->Weight;
//    //若是无向图
//    Graph[E->W][E->V] = E->Weight;
    Graph->G[E->V][E->W] = 1;
    //若是无向图
    Graph->G[E->W][E->V] = 1;
}

MGraph BuildGraph(){
    MGraph Graph;
    int Nv;
    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);
    scanf(" %d", &Graph->Ne);
    if(Graph->Ne!=0){
        for(int i=0;i<Graph->Ne;i++) {
            Edge E = (Edge) malloc(sizeof(struct ENode));
            scanf("%d %d", &E->V, &E->W);
            InsertEdge(Graph, E);
        }
    }

    return Graph;
}

void DFS(MGraph Graph, Vertex V){
    if(!Visited[V]){
        printf("%d ", V);
    }
    Visited[V] = 1;
    for(Vertex W=0;W<Graph->Nv;W++){
        if(Graph->G[V][W] && !Visited[W]){
            DFS(Graph, W);
        }
    }
}

void BFS(MGraph Graph, Vertex V){
    const int MAX_SIZE  = 100;
    int Queue[MAX_SIZE];
    int rear=-1,front=-1;

    if(!Visited[V]){
        printf("%d ", V);
    }
    Visited[V] = 1;
    Queue[++rear] = V;
    while (rear!=front){//只要不空
        V = Queue[++front];
        for(Vertex W=0;W<Graph->Nv;W++){
            if(Graph->G[V][W] && !Visited[W]){
                Visited[W] = 1;
                printf("%d ", W);
                Queue[++rear] = W;
            }
        }
    }
}


