//
// Created by Saijun Hu on 2019-02-23.
// TODO dfs遍历树状图，两次便可以得到直径
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int N,M;
int visited1[20008]={0};
int visited2[20008]={0};
vector<int> graph[200016];
void dfs(int start,int depth,int& turn_vertex,int& maxdepth,int visited[]){
    visited[start]=1;
    if(depth>maxdepth){
        turn_vertex=start;
        maxdepth=depth;
    }
    for (int i = 0; i < graph[start].size(); ++i) {
        int x=graph[start][i];
        if(!visited[x]) dfs(x,depth+1,turn_vertex,maxdepth,visited);
    }
}
int main(){
    cin>>N>>M;
    for (int i = 2; i <= N; ++i) {
        int x;cin>>x;
        graph[i].push_back(x);
        graph[x].push_back(i);
    }
    for (int i = 1; i < M; ++i) {
        int x;cin>>x;
        graph[10000+i].push_back(x);
        graph[x].push_back(10000+i);
    }
    int turn_vex=1,maxdepth=-1;
    dfs(1,0,turn_vex,maxdepth,visited1);
    dfs(turn_vex,0,turn_vex,maxdepth,visited2);
    cout<<maxdepth<<endl;
    return 0;
}

