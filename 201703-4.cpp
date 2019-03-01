//
// Created by Saijun Hu on 2019-02-26.
// TODO krskal的改进，可以认为这是最小代价的另一种定义而已，经典算法模板需要掌握，此题
// 结合优先级队列来做，更加方便，作为模板领悟
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct edge{
    int start,end,weight;
    edge(int s,int e,int w):start(s),end(e),weight(w){}
    bool operator <(const edge& b) const{
        return this->weight >b.weight;//每次选出全局最小的
    }
};
int N,M;
priority_queue<edge> edges;
vector<int> p;

int find(int x){ return p[x]==x ? x : p[x]=find(p[x]);}//Union-Find's find

int kruskal(){
    int ans =-1;
    for (int i = 0; i < N; ++i) p.push_back(i);//初始化并查集
    while(find(0)!=find(N-1)) {
        edge e = edges.top();edges.pop();
        int x = find(e.start);//找出边的端点所在的集合
        int y = find(e.end);
        if(x!=y){ ans=max(ans,e.weight); p[x]=y;}//如果在不同集合，合并，并取最大作为权
        //该算法与kruskal的不同之处
    }
    return ans;
}
int main(){
    cin>>N>>M;
    int i=M;
    while(i--){
        int v1,v2,weight;
        cin>>v1>>v2>>weight;
        edge e = edge(v1-1,v2-1,weight);
        edges.push(e);
    }
    cout<<kruskal()<<endl;
    return 0;
}

