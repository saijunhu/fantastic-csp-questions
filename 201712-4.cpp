//
// Created by Saijun Hu on 2019-02-28.
// TODO 不会
#include <iostream>
#include <vector>

using namespace std;
int N,M;
struct edge{
    int t,v,c;
    edge(int t=0,int v=0,int c=0):t(t),v(v),c(c){}
};
vector<edge> graph[500];
bool visited[500];
int main(){
    cin>>N>>M;
    while(M--){
        int t,s,e,c;
        cin>>t>>s>>e>>c;
        graph[s-1].emplace_back(edge(t,e-1,c));
        graph[e-1].emplace_back(edge(t,s-1,c));
    }
    return 0;
}
