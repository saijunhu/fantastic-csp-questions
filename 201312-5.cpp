//
// Created by Saijun Hu on 2019/2/19.
//
#include <iostream>
#include <cstring>
using namespace std;
//思路：两次dfs，第一次从s点出发，dfs,找到所有可以到达的的点，并看是否包含T点，若不包含，输出
//"i'm stuck"；否则的话进行第二步，遍历所有上述的可到达点集合，依次进行dfs，统计不能到达T点
//的个数，返回即可
const  int N=50;
const int DIRECTION_SIZE=4;
struct _direction{
    int delta_r,delta_c;
} direction[DIRECTION_SIZE] = {{-1,0},{1,0},{0,-1},{0,1}};

char grid[N][N];
int visited[N][N], visited2[N][N];

int R, C;
//判断坐标是否合法或者可移动到
inline bool isLegal(int r,int c){
    if(0<=r && r<R && 0<=c && c<C && !visited[r][c] && grid[r][c]!='#'){
        return true;
    }else{ return false;}
}
//dfs
void dfs(int r, int c){
    int nextr,nextc;
    visited[r][c]=1;
    char ch = grid[r][c];
    switch (ch){
        case '+':
        case 'S':
        case 'T':
            //四个方向均可以走
            for(int i=0;i<DIRECTION_SIZE;i++){
                nextr=r+direction[i].delta_r;
                nextc=c+direction[i].delta_c;
                if(isLegal(nextr,nextc)) dfs(nextr,nextc);
            }
            break;
        case '-':
            for(int i=2;i<DIRECTION_SIZE;i++){
                nextr=r+direction[i].delta_r;
                nextc=c+direction[i].delta_c;
                if(isLegal(nextr,nextc)) dfs(nextr,nextc);
            }
            break;
        case '|':
            for(int i=0;i<2;i++){
                nextr=r+direction[i].delta_r;
                nextc=c+direction[i].delta_c;
                if(isLegal(nextr,nextc)) dfs(nextr,nextc);
            }
            break;
        case '.':
            nextr=r+direction[1].delta_r;
            nextc=c+direction[1].delta_c;
            if(isLegal(nextr,nextc)) dfs(nextr,nextc);
            break;

    }
}
int main(){
    int s_r,s_c,t_r,t_c;
    cin>>R>>C;
    //二维数组的输入
    for(int i=0;i<R;i++)
        cin>>grid[i];
    //找到起点和终点
    for (int j = 0; j < R; ++j) {
        for (int i = 0; i < C; ++i) {
            char ch =grid[j][i];
            if(ch=='S'){s_r=j;s_c=i;}
            if(ch=='T'){t_r=j;t_c=i;}
        }
    }
    //dfs，标记从S可以到达的点
    memset(visited,0, sizeof(visited));
    dfs(s_r,s_c);
    memcpy(visited2,visited, sizeof(visited));

    if(!visited2[t_r][t_c]) {cout<<"I'm stuck!"<<endl;}
    else{
        //dfs2,统计S可到达，但不可到达T的数量
        int count=0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C ; ++j) {
                if(visited2[i][j]){
                    memset(visited,0, sizeof(visited));
                    dfs(i,j);
                    if(!visited[t_r][t_c]) count++;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
