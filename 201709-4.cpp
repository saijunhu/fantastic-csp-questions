//
// Created by Saijun Hu on 2019-02-27.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool visit[1000];
vector<int> graph[1000];
int know[1000][1000];

void dfs(int u,int origin){
    visit[u]=true;
    know[u][origin]=1;
    know[origin][u]=1;
    for (auto v: graph[u]) {
        if(!visit[v]) dfs(v,origin);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        graph[u-1].push_back(v-1);
    }
    for (int i = 0; i <n ; ++i) {
        fill(visit,visit+n,false);
        dfs(i,i);
    }
    //check the cnt;
    int cnt=0;//the not know all vertex's number
    for (int i = 0; i < n; ++i) {
        if(count(know[i],know[i]+n,true)==n) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}