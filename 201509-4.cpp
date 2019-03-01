//
// Created by Saijun Hu on 2019-02-23.
// TODO 超时，30分，需要改进。tarjan算法，以后再说

#include <iostream>
#include <vector>
using namespace std;
int ver_num,edge_num;
vector<int> graph[10000];
void dfs(int s,int d,int& flag,int visted[]){
    visted[s]=1;
    if(s==d) {
        flag=true;
        return;
    }
    for (int k = 0; k < graph[s].size(); ++k) {
        int x=graph[s][k];
        if(!visted[x]) dfs(x,d,flag,visted);
    }
}
int main(){

    cin>>ver_num>>edge_num;
    int mem[ver_num][ver_num];
    while(edge_num--){
        int a,b;
        cin>>a>>b;
        graph[a-1].push_back(b-1);
    }
    int cnt=0;
    for (int i = 0; i < ver_num; ++i) {
        for (int j = 0; j < ver_num; ++j) {
            int visited[10000]={0};
            int flag=0;
            dfs(i,j,flag,visited);
            mem[i][j]=flag;
        }
    }

    for (int i = 0; i < ver_num; ++i) {
        for (int j = 0; j < ver_num ; ++j) {//
            //注意排除自己到自己的1！
            if(i!=j && mem[i][j]==1 && mem[j][i]==1) cnt++;
        }
    }
    cout<<cnt/2<<endl;
    return 0;
}