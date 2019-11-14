/*
 * 詹姆斯邦德简易版
 * 复制粘贴的,还没有搞懂
 */

#include<stdio.h>
#include <stdlib.h>
#include<math.h>

#define YES 1
#define NO 0

struct coordinate{  //鳄鱼坐标 
    int x;
    int y;
}crocodile[105];

int N,D;
int visited[105] = {0};  //标志某一个鳄鱼坐标是否被访问过，=0未被访问过 

void Save007();

int main()
{
    int i;

    scanf("%d %d",&N,&D);  //输入鳄鱼数量及007可以跳跃的最大距离
    for(i=0; i<N; i++){
        scanf("%d %d",&crocodile[i].x,&crocodile[i].y);
    }
    Save007();

    return 0;
}

int IsSafe(int v)
{
    int X_distant,Y_distant;

    X_distant = abs(crocodile[v].x)-50;
    Y_distant = abs(crocodile[v].y)-50;

    return (abs(X_distant) <= D || abs(Y_distant) <= D);
}

int Jump(int v,int w)
{
    return (sqrt(pow(crocodile[v].x-crocodile[w].x,2)+pow(crocodile[v].y-crocodile[w].y,2)) <= D);  //两个鳄鱼坐标之间的距离
}

int DFS(int v)
{
    int w;
    int answer = NO;

    visited[v] = 1;  //表明w被访问过
    if ( IsSafe(v) )  answer = YES;
    else{
        for(w=0; w<N; w++){
            if( !visited[w] && Jump(v,w)){
                answer = DFS(w);
                if(answer == YES)  break;
            }
        }
    }

    return answer;
}

int FirstJump(int v)
{
    return (sqrt(pow(crocodile[v].x,2)+pow(crocodile[v].y,2)) <= (D+15));
}

void Save007()
{
    int v;
    int answer = NO;

    for(v=0; v<N; v++){
        if( !visited[v] && FirstJump(v) ){
            answer = DFS(v);
            if(answer == YES)  break;
        }
    }
    if(answer == YES)  printf("Yes\n");
    else  printf("No\n");
}
